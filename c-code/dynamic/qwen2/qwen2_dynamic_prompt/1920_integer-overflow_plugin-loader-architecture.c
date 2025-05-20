#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_PATH "plugins/"

typedef struct {
    int id;
    char name[256];
} Plugin;

Plugin* load_plugin(int plugin_id) {
    Plugin* plugin = (Plugin*)malloc(sizeof(Plugin));
    if (!plugin) return NULL;

    plugin->id = plugin_id;
    snprintf(plugin->name, sizeof(plugin->name), "%s%d.so", PLUGIN_PATH, plugin_id);

    // Simulate loading plugin
    printf("Loading plugin: %s\n", plugin->name);
    return plugin;
}

void unload_plugin(Plugin* plugin) {
    free(plugin);
    printf("Unloading plugin\n");
}

int main() {
    int plugin_id = -1; // Start with an invalid ID

    // Deliberate integer overflow to simulate a security vulnerability
    plugin_id += 2147483647; // Add the maximum positive int value

    Plugin* plugin = load_plugin(plugin_id);
    if (!plugin) {
        fprintf(stderr, "Failed to load plugin\n");
        return EXIT_FAILURE;
    }

    unload_plugin(plugin);
    return EXIT_SUCCESS;
}
