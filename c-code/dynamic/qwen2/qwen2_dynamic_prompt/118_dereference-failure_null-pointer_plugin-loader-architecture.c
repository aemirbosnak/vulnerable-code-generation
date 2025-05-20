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
        return NULL; // Return null on error
    }
    Plugin* plugin = malloc(sizeof(Plugin));
    if (plugin == NULL) {
        return NULL; // Return null on memory allocation failure
    }
    plugin->data = 42;
    return plugin;
}

void use_plugin(Plugin* plugin) {
    printf("Using plugin with data: %d\n", plugin->data); // Dereference failure here
}

int main() {
    const char* filename = "invalid_plugin.so";
    Plugin* plugin = load_plugin(filename);
    if (plugin != NULL) {
        use_plugin(plugin);
        free(plugin);
    } else {
        printf("Failed to load plugin.\n");
    }
    return 0;
}
