#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void (*plugin_function)();
} Plugin;

void load_plugin(Plugin *plugin) {
    if (plugin == NULL) {
        printf("Error: Plugin is NULL\n");
        return;
    }
    plugin->plugin_function();
}

int main() {
    Plugin *plugins = malloc(sizeof(Plugin) * 2);
    if (plugins == NULL) {
        printf("Error: Failed to allocate memory for plugins\n");
        return 1;
    }

    // Initialize plugins
    plugins[0].plugin_function = NULL; // Null function pointer
    plugins[1].plugin_function = (void (*)(void))printf; // Valid function pointer

    // Load plugins
    load_plugin(&plugins[0]); // This will cause a null pointer dereference
    load_plugin(&plugins[1]);

    free(plugins);

    return 0;
}
