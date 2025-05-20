#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char* data;
} Plugin;

Plugin* load_plugin(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) return NULL;

    Plugin* plugin = (Plugin*)malloc(sizeof(Plugin));
    if (!plugin) {
        fclose(file);
        return NULL;
    }

    fread(plugin, sizeof(Plugin), 1, file);
    plugin->data = (char*)malloc(strlen((const char*)plugin->data) + 1);
    if (!plugin->data) {
        free(plugin);
        fclose(file);
        return NULL;
    }
    fread(plugin->data, strlen((const char*)plugin->data), 1, file);

    fclose(file);
    return plugin;
}

void execute_plugin(Plugin* plugin) {
    printf("Executing plugin %d with data: %s\n", plugin->id, plugin->data);
}

int main() {
    Plugin* plugin = load_plugin("nonexistent_plugin.bin");
    if (!plugin) {
        printf("Failed to load plugin.\n");
        return 1;
    }

    // Dereference failure by accessing freed memory
    execute_plugin(plugin); // This will cause undefined behavior

    free(plugin->data);
    free(plugin);

    return 0;
}
