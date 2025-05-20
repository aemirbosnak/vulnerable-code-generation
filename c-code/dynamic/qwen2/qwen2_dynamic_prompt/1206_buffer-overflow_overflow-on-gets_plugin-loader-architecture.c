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
    printf("Loading plugin: %s\n", plugin->name);
}

int main() {
    Plugin plugins[10];
    int num_plugins = 10;
    char input[100];

    printf("Enter plugin names:\n");
    for (int i = 0; i < num_plugins; i++) {
        printf("Plugin %d: ", i + 1);
        fgets(input, sizeof(input), stdin);
        // Remove newline character if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }
        strncpy(plugins[i].name, input, MAX_PLUGIN_NAME_LENGTH - 1);
        plugins[i].name[MAX_PLUGIN_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
    }

    printf("\nPlugins loaded:\n");
    for (int i = 0; i < num_plugins; i++) {
        load_plugin(&plugins[i]);
    }

    return 0;
}
