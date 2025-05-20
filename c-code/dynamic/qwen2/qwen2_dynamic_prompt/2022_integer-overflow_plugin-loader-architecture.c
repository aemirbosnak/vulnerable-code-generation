#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_PATH "/path/to/plugins"

typedef struct {
    int id;
    char name[256];
} Plugin;

void load_plugin(Plugin *plugin) {
    FILE *file = fopen(plugin->name, "r");
    if (file == NULL) {
        perror("Failed to open plugin file");
        return;
    }

    // Simulate loading plugin data
    fscanf(file, "%d %s", &plugin->id, plugin->name);
    fclose(file);

    printf("Loaded plugin: ID=%d, Name=%s\n", plugin->id, plugin->name);
}

int main() {
    Plugin plugins[10];
    int num_plugins = 10;

    // Simulate loading multiple plugins
    for (int i = 0; i < num_plugins; i++) {
        snprintf(plugins[i].name, sizeof(plugins[i].name), "%s/plugin%d.so", PLUGIN_PATH, i);
        plugins[i].id = i + 1;
    }

    // Intentionally create an integer overflow by adding a large number
    int overflow_value = 2147483647; // Maximum value for a signed int
    overflow_value += 1; // This will cause an overflow

    printf("Overflow value: %d\n", overflow_value);

    // Load plugins with potential overflow
    for (int i = 0; i < num_plugins; i++) {
        load_plugin(&plugins[i]);
    }

    return 0;
}
