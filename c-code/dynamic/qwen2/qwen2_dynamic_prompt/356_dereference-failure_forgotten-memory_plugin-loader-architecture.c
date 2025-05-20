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

    // Dereference failure here: using an uninitialized pointer
    use_plugin(plugin); // This will cause undefined behavior

    if (plugin) {
        free(plugin);
    }

    return 0;
}
