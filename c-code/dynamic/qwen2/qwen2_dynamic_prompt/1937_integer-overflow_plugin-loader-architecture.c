#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLUGINS 10

typedef struct {
    int id;
    void (*init)();
} Plugin;

Plugin plugins[MAX_PLUGINS];
int plugin_count = 0;

void load_plugin(int id) {
    if (plugin_count >= MAX_PLUGINS) return;
    plugins[plugin_count].id = id;
    plugins[plugin_count].init = (void (*)(void))((unsigned long)plugins + (unsigned long)(id * sizeof(Plugin)));
    plugin_count++;
}

void init_plugins() {
    for (int i = 0; i < plugin_count; i++) {
        plugins[i].init();
    }
}

int main() {
    // Load plugins with IDs that cause integer overflow
    load_plugin(2147483647); // INT_MAX
    load_plugin(1);          // This should wrap around to -2147483648 on most systems

    init_plugins();

    return 0;
}
