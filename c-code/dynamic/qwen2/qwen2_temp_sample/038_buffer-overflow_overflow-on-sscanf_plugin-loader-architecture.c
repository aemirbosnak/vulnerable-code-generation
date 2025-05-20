#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

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

    Plugin plugin;
    if (fscanf(file, "%s", plugin.name) != 1) {
        fprintf(stderr, "Error reading plugin name\n");
        fclose(file);
        return;
    }

    // Vulnerability: Buffer overflow due to lack of length check
    printf("Loaded plugin: %s\n", plugin.name);

    fclose(file);
}

int main() {
    const char* plugin_path = "plugin.txt";
    load_plugin(plugin_path);
    return 0;
}
