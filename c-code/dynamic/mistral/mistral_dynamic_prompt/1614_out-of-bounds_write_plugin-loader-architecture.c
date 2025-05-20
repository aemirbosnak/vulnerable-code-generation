#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[32];
    char (*function)();
    void* data;
} Plugin;

Plugin* load_plugin(char* filename) {
    FILE* file = fopen(filename, "rb");
    Plugin* plugin = malloc(sizeof(Plugin));
    if (!file || !plugin) return NULL;

    fread(plugin->name, sizeof(char), 32, file);
    fread(&plugin->function, sizeof(void*), 1, file);
    plugin->data = malloc(fgetc(file));
    fread(plugin->data, fgetc(file), ftell(file) - 33, file);
    fclose(file);

    return plugin;
}

void unload_plugin(Plugin* plugin) {
    free(plugin->data);
    free(plugin);
}

void main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <plugin_file>\n", argv[0]);
        return;
    }

    Plugin* plugin = load_plugin(argv[1]);
    if (!plugin) {
        printf("Error loading plugin.\n");
        return;
    }

    printf("Loaded plugin: %s\n", plugin->name);
    ((void(*)()) plugin->function)(); // Vulnerable call

    unload_plugin(plugin);
}
