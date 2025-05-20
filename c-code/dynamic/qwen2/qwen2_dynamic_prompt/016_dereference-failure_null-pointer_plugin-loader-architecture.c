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
        return NULL; // Return NULL to simulate failure
    }
    Plugin* plugin = malloc(sizeof(Plugin));
    if (plugin == NULL) {
        return NULL; // Return NULL to simulate memory allocation failure
    }
    plugin->data = 42;
    return plugin;
}

void use_plugin(Plugin* plugin) {
    if (plugin == NULL) {
        printf("Error: Plugin is null\n");
        return;
    }
    printf("Using plugin with data: %d\n", plugin->data);
}

int main() {
    const char* plugin_filename = "invalid_plugin.so";
    Plugin* plugin = load_plugin(plugin_filename);

    if (plugin == NULL) {
        printf("Failed to load plugin\n");
        return 1;
    }

    use_plugin(plugin); // This will cause a dereference failure

    free(plugin);
    return 0;
}
