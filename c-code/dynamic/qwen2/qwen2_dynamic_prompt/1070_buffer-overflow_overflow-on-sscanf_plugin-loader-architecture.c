#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLUGIN_NAME_LENGTH 20

typedef struct {
    char name[MAX_PLUGIN_NAME_LENGTH];
} Plugin;

void load_plugin(const char* plugin_path) {
    FILE* file = fopen(plugin_path, "r");
    if (!file) {
        perror("Failed to open plugin file");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        if (strncmp(line, "plugin_name=", 14) == 0) {
            char* plugin_name = line + 14;
            Plugin plugin;
            // Vulnerability: Buffer overflow due to insufficient check on plugin_name length
            sscanf(plugin_name, "%s", plugin.name);
            printf("Loaded plugin: %s\n", plugin.name);
        }
    }

    fclose(file);
}

int main() {
    const char* plugin_path = "plugins/plugin.txt";
    load_plugin(plugin_path);
    return 0;
}
