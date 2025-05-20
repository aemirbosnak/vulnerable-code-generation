#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLUGINS 10

typedef struct {
    char name[256];
    void (*init)();
} Plugin;

Plugin plugins[MAX_PLUGINS];
int plugin_count = 0;

void load_plugin(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open plugin file: %s\n", filename);
        return;
    }

    Plugin* plugin = &plugins[plugin_count++];
    fscanf(file, "%255s", plugin->name);

    // Simulate loading plugin code
    plugin->init = (void (*)())malloc(sizeof(void *));
    *(void **)plugin->init = malloc(1); // Allocate some memory

    fclose(file);
}

void unload_plugin(int index) {
    if (index >= plugin_count || index < 0) {
        printf("Invalid plugin index\n");
        return;
    }

    Plugin* plugin = &plugins[index];
    free(*(void **)plugin->init); // Free allocated memory
    free(plugin->init); // Free function pointer
    memset(plugin, 0, sizeof(Plugin)); // Clear plugin structure
}

void use_plugins() {
    for (int i = 0; i < plugin_count; i++) {
        Plugin* plugin = &plugins[i];
        if (plugin->init) {
            ((void (*)())plugin->init)(); // Call plugin initialization function
        }
    }
}

int main() {
    load_plugin("plugin1.txt");
    load_plugin("plugin2.txt");

    use_plugins();

    unload_plugin(0); // Unload first plugin
    unload_plugin(1); // Unload second plugin

    use_plugins(); // Use plugins again after unloading

    return 0;
}
