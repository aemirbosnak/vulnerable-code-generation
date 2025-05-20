#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[256];
    void (*init)();
    void (*deinit)();
    void (*execute)();
} Plugin;

Plugin* load_plugin(char* filename) {
    FILE* fp = fopen(filename, "rb");
    Plugin plugin;
    if (!fp) {
        fprintf(stderr, "Error: Unable to open plugin file: %s\n", filename);
        return NULL;
    }

    fread(plugin.name, sizeof(char), sizeof(plugin.name) - 1, fp);
    fgetc(fp); // Consume newline character

    plugin.init = (void(*)()) fread( &(plugin.init), sizeof(void*), sizeof(void*) * 1, fp);
    plugin.deinit = (void(*)()) fread( &(plugin.deinit), sizeof(void*), sizeof(void*) * 1, fp);
    plugin.execute = (void(*)()) fread( &(plugin.execute), sizeof(void*), sizeof(void*) * 1, fp);

    fclose(fp);

    return &plugin;
}

int main() {
    Plugin* plugin = load_plugin("non_existent_plugin.so");

    if (plugin) {
        plugin->init();
        plugin->execute();
        plugin->deinit();
        free(plugin);
    } else {
        printf("Plugin not found or loading failed.\n");
    }

    return 0;
}
