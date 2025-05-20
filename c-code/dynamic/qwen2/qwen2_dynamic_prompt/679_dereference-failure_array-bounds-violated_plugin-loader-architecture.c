#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_COUNT 10

typedef struct {
    int id;
    char name[20];
} Plugin;

Plugin plugins[PLUGIN_COUNT];

void load_plugins() {
    FILE *file = fopen("plugins.txt", "r");
    if (!file) {
        printf("Failed to open plugins file\n");
        return;
    }

    for (int i = 0; i < PLUGIN_COUNT; i++) {
        fscanf(file, "%d %s", &plugins[i].id, plugins[i].name);
    }

    fclose(file);
}

void execute_plugin(int index) {
    if (index >= 0 && index < PLUGIN_COUNT) {
        printf("Executing plugin: %s\n", plugins[index].name);
    } else {
        printf("Invalid plugin index\n");
    }
}

int main() {
    load_plugins();

    // Intentional out-of-bounds access
    execute_plugin(PLUGIN_COUNT);

    return 0;
}
