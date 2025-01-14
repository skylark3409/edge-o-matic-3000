#include "config.h"
#include "orgasm_control.h"
#include "ui/menu.h"
#include "ui/page.h"
#include "ui/ui.h"
#include "util/i18n.h"

static void
on_start_recording(const ui_menu_t* m, const ui_menu_item_t* item, UI_MENU_ARG_TYPE arg) {
    orgasm_control_startRecording();
    ui_reenter_menu();
}

static void
on_stop_recording(const ui_menu_t* m, const ui_menu_item_t* item, UI_MENU_ARG_TYPE arg) {
    orgasm_control_stopRecording();
    ui_reenter_menu();
}

static void on_open(const ui_menu_t* m, UI_MENU_ARG_TYPE arg) {
    ui_menu_add_page(m, &EDGING_CHART_PAGE);

    if (orgasm_control_isRecording()) {
        ui_menu_add_item(m, _("Stop Recording"), on_stop_recording, NULL);
    } else {
        ui_menu_add_item(m, _("Start Recording"), on_start_recording, NULL);
    }

#ifdef EOM_BETA
    ui_menu_add_item(m, _("Set Time Limit"), NULL, NULL);
    ui_menu_add_item(m, _("Set Edge Goal"), NULL, NULL);
#endif
}

DYNAMIC_MENU(EDGING_MODE_MENU, "Edging Menu", on_open);