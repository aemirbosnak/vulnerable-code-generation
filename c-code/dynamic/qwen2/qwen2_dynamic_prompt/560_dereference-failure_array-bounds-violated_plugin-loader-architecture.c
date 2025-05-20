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
    FILE *file = fopen("plugins.txt", "r");
    if (!file) {
        perror("Failed to open plugins file");
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
        printf("Invalid plugin index: %d\n", index);
    }
}

int main() {
    load_plugins();

    // Deliberate array bounds violation
    execute_plugin(PLUGIN_COUNT); // This will cause an out-of-bounds access

    return 0;
}
