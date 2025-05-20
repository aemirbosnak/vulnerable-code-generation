#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLUGIN_NAME_LENGTH 10

typedef struct {
    char name[MAX_PLUGIN_NAME_LENGTH];
} Plugin;

void load_plugin(const char* plugin_path) {
    Plugin plugin;
    FILE* file = fopen(plugin_path, "r");
    if (!file) {
        printf("Failed to open plugin file: %s\n", plugin_path);
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%9s", plugin.name) == 1) {
            printf("Loaded plugin: %s\n", plugin.name);
        }
    }

    fclose(file);
}

int main() {
    const char* plugin_paths[] = {
        "plugins/plugin1.txt",
        "plugins/plugin2.txt",
        "plugins/plugin3.txt"
    };

    for (size_t i = 0; i < 3; ++i) {
        load_plugin(plugin_paths[i]);
    }

    return 0;
}
