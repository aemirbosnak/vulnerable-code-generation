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

void load_plugin(const char* plugin_data) {
    Plugin plugin;
    if (sscanf(plugin_data, "%s", plugin.name) != 1) {
        fprintf(stderr, "Failed to parse plugin data\n");
        return;
    }
    printf("Loaded plugin: %s\n", plugin.name);
}

int main() {
    char input[100];
    printf("Enter plugin data: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character if present
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    load_plugin(input);

    return 0;
}
