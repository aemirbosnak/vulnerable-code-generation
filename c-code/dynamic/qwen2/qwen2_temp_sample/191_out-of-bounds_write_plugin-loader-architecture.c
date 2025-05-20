#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLUGINS 10

typedef struct {
    void (*init)();
    void (*run)();
} Plugin;

Plugin plugins[MAX_PLUGINS];
int plugin_count = 0;

void load_plugin(void *plugin_code) {
    if (plugin_count >= MAX_PLUGINS) return;
    memcpy(&plugins[plugin_count], plugin_code, sizeof(Plugin));
    plugin_count++;
}

void execute_plugins() {
    for (int i = 0; i < plugin_count; i++) {
        if (plugins[i].init) plugins[i].init();
        if (plugins[i].run) plugins[i].run();
    }
}

int main() {
    // Simulating loading plugins from memory
    char plugin_data[] = {
        0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90, 0x90,  // NOP sled
        0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC, 0xCC   // INT3 - Breakpoint
    };

    load_plugin(plugin_data);
    execute_plugins();

    printf("Plugins executed.\n");
    return 0;
}
