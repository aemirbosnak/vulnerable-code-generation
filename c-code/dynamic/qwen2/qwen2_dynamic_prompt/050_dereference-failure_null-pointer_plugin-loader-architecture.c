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
    // Simulate loading a plugin from a file
    if (filename == NULL || strcmp(filename, "valid_plugin.so") != 0) {
        return NULL;
    }
    Plugin* plugin = malloc(sizeof(Plugin));
    if (plugin == NULL) {
        return NULL;
    }
    plugin->data = 42;
    return plugin;
}

void use_plugin(Plugin* plugin) {
    // Use the plugin
    printf("Plugin data: %d\n", plugin->data);
}

int main() {
    const char* plugin_filename = "valid_plugin.so";
    Plugin* plugin = load_plugin(plugin_filename);

    if (plugin == NULL) {
        fprintf(stderr, "Failed to load plugin.\n");
        return EXIT_FAILURE;
    }

    use_plugin(plugin);

    free(plugin);

    // Deliberate null pointer dereference vulnerability
    Plugin* null_plugin = NULL;
    use_plugin(null_plugin); // This will cause a segmentation fault

    return EXIT_SUCCESS;
}
