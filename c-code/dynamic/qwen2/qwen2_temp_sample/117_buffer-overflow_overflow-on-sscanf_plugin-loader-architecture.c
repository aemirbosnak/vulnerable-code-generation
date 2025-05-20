#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLUGIN_NAME_LENGTH 256

typedef struct {
    char name[MAX_PLUGIN_NAME_LENGTH];
} Plugin;

void loadPlugin(const char* pluginPath) {
    FILE* file = fopen(pluginPath, "r");
    if (!file) {
        printf("Failed to open plugin file: %s\n", pluginPath);
        return;
    }

    Plugin plugin;
    if (sscanf(file, "%255s", plugin.name) != 1) {
        printf("Failed to read plugin name from file: %s\n", pluginPath);
        fclose(file);
        return;
    }

    printf("Loaded plugin: %s\n", plugin.name);

    fclose(file);
}

int main() {
    const char* pluginPath = "plugin.txt";
    loadPlugin(pluginPath);
    return 0;
}
