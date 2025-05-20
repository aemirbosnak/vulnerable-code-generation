#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
} Plugin;

Plugin* load_plugin(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) return NULL;

    Plugin* plugin = malloc(sizeof(Plugin));
    if (!plugin) {
        fclose(file);
        return NULL;
    }

    size_t bytes_read = fread(plugin, sizeof(Plugin), 1, file);
    if (bytes_read != 1) {
        free(plugin);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return plugin;
}

void use_plugin(Plugin* plugin) {
    printf("Using plugin with data: %d\n", plugin->data);
}

int main() {
    Plugin* plugin = load_plugin("nonexistent_plugin.bin");
    if (!plugin) {
        printf("Failed to load plugin.\n");
        return 1;
    }

    use_plugin(plugin); // Dereference failure here

    free(plugin);

    return 0;
}
