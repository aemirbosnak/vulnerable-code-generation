#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_PATH "/path/to/plugins/"

typedef struct {
    char name[20];
    void (*execute)();
} Plugin;

void load_plugin(const char *plugin_name) {
    char path[100];
    snprintf(path, sizeof(path), "%s%s", PLUGIN_PATH, plugin_name);
    FILE *file = fopen(path, "r");
    if (!file) {
        printf("Failed to open plugin: %s\n", plugin_name);
        return;
    }

    Plugin plugin;
    fscanf(file, "%19s", plugin.name); // Vulnerable line - no bounds checking
    plugin.execute = NULL; // Placeholder

    printf("Loaded plugin: %s\n", plugin.name);

    fclose(file);
}

int main() {
    char input[10];
    printf("Enter plugin name: ");
    scanf("%9s", input); // Vulnerable line - no bounds checking

    load_plugin(input);

    return 0;
}
