#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[100];
    void (*func)();
} Plugin;

Plugin* load_plugin(const char* path) {
    Plugin* plugin = (Plugin*)malloc(sizeof(Plugin));
    FILE* file = fopen(path, "r");

    if (!file) {
        free(plugin);
        return NULL;
    }

    fread(plugin->name, 100, 1, file);
    fread(&plugin->func, sizeof(void(*)()), 1, file);

    fclose(file);

    return plugin;
}

void plugin_func(Plugin* plugin) {
    (plugin->func)();
}

void main() {
    Plugin* plugin = load_plugin("plugin.bin");

    if (plugin) {
        plugin_func(plugin);
    }
}
