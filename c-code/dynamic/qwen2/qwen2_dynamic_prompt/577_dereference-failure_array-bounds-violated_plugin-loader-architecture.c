#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_COUNT 3

typedef struct {
    int id;
    char name[20];
} Plugin;

Plugin plugins[PLUGIN_COUNT];

void load_plugins() {
    FILE *file = fopen("plugins.dat", "rb");
    if (!file) {
        printf("Failed to open plugins file.\n");
        return;
    }

    fread(plugins, sizeof(Plugin), PLUGIN_COUNT, file);
    fclose(file);
}

void execute_plugins() {
    for (int i = 0; i <= PLUGIN_COUNT; i++) { // Dereference failure here
        printf("Executing plugin %d: %s\n", plugins[i].id, plugins[i].name);
    }
}

int main() {
    load_plugins();
    execute_plugins();
    return 0;
}
