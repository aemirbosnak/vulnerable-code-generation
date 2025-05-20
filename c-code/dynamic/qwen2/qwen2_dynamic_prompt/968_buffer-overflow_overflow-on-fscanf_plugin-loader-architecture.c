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

void load_plugin(Plugin *plugin) {
    printf("Loading plugin: ");
    if (fscanf(stdin, "%19s", plugin->name) != 1) {
        fprintf(stderr, "Failed to read plugin name.\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    Plugin plugins[3];
    int i;

    for (i = 0; i < 3; i++) {
        printf("Enter name for plugin %d: ", i + 1);
        load_plugin(&plugins[i]);
    }

    printf("\nPlugins loaded:\n");
    for (i = 0; i < 3; i++) {
        printf("%s\n", plugins[i].name);
    }

    return 0;
}
