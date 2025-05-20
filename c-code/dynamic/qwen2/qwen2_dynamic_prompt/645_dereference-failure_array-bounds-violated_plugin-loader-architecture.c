#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLUGINS 10

typedef struct {
    int id;
    char name[256];
} Plugin;

Plugin plugins[MAX_PLUGINS];

void load_plugins() {
    FILE *file = fopen("plugins.txt", "r");
    if (!file) {
        printf("Failed to open plugins file.\n");
        return;
    }

    int i = 0;
    while (i < MAX_PLUGINS && fscanf(file, "%d %s", &plugins[i].id, plugins[i].name) == 2) {
        i++;
    }
    fclose(file);
}

void execute_plugin(int index) {
    if (index >= 0 && index < MAX_PLUGINS) {
        printf("Executing plugin: %s\n", plugins[index].name);
        // Simulate plugin execution
        // This is where you would call the plugin's function
    } else {
        printf("Invalid plugin index: %d\n", index);
    }
}

int main() {
    load_plugins();

    // Intentionally out-of-bounds access to demonstrate vulnerability
    execute_plugin(MAX_PLUGINS);

    return 0;
}
