#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_PATH "/path/to/plugins/"
#define MAX_PLUGIN_NAME_LENGTH 256

typedef struct {
    char name[MAX_PLUGIN_NAME_LENGTH];
    void (*init)();
} Plugin;

Plugin plugins[10];
int plugin_count = 0;

void load_plugin(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open plugin file");
        return;
    }

    fscanf(file, "%s", plugins[plugin_count].name);
    fclose(file);

    // Vulnerability: Buffer overflow due to lack of bounds checking
    printf("Loading plugin: %s\n", plugins[plugin_count].name);
    plugins[plugin_count].init();
    plugin_count++;
}

void init_plugins() {
    for (int i = 0; i < plugin_count; i++) {
        plugins[i].init();
    }
}

int main() {
    printf("Welcome to the Plugin Loader!\n");

    while (1) {
        char filename[MAX_PLUGIN_NAME_LENGTH];
        printf("Enter plugin filename (or 'exit' to quit): ");
        scanf("%s", filename);

        if (filename[0] == 'e' && filename[1] == 'x' && filename[2] == 'i' && filename[3] == 't') {
            break;
        }

        load_plugin(PLUGIN_PATH);
    }

    init_plugins();

    return 0;
}
