#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLUGIN_NAME_LENGTH 10

typedef struct {
    char name[MAX_PLUGIN_NAME_LENGTH];
} Plugin;

void load_plugin(Plugin *plugin) {
    printf("Loading plugin: %s\n", plugin->name);
}

int main() {
    Plugin plugins[2];
    FILE *file = fopen("plugins.txt", "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 2; i++) {
        if (fscanf(file, "%9s", plugins[i].name) != 1) {
            fprintf(stderr, "Error reading plugin name\n");
            fclose(file);
            return EXIT_FAILURE;
        }
        load_plugin(&plugins[i]);
    }

    fclose(file);
    return EXIT_SUCCESS;
}
