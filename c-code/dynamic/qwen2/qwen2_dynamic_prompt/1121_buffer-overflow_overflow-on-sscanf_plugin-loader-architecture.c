#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLUGIN_NAME_LENGTH 16

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

    // Vulnerable line - no bounds checking
    fscanf(file, "%s", plugin.name);

    fclose(file);
    printf("Loaded plugin: %s\n", plugin.name);
}

int main() {
    const char* plugin_path = "plugin.txt";
    load_plugin(plugin_path);
    return 0;
}
