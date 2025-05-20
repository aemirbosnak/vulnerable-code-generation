#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void (*plugin_func)();
} Plugin;

void load_plugin(Plugin *plugin) {
    if (plugin == NULL) {
        printf("Plugin is null\n");
        return;
    }
    plugin->plugin_func();
}

int main() {
    Plugin *plugin = NULL;
    load_plugin(plugin);
    return 0;
}
