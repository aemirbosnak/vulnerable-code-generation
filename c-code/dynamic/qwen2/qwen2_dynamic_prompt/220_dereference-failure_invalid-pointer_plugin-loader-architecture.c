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
    const char* plugin_filename = "nonexistent_plugin.bin";
    Plugin* plugin = load_plugin(plugin_filename);

    if (!plugin) {
        fprintf(stderr, "Failed to load plugin.\n");
        return EXIT_FAILURE;
    }

    // Deliberate dereference failure
    use_plugin(NULL); // Invalid pointer

    free(plugin);
    return EXIT_SUCCESS;
}
