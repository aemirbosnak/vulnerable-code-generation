#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLUGIN_NAME_LENGTH 20

typedef struct {
    char name[MAX_PLUGIN_NAME_LENGTH];
} Plugin;

void load_plugin(Plugin *plugin, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    if (fgets(plugin->name, sizeof(plugin->name), file)) {
        // Remove newline character if present
        size_t len = strlen(plugin->name);
        if (len > 0 && plugin->name[len - 1] == '\n') {
            plugin->name[len - 1] = '\0';
        }
    } else {
        fprintf(stderr, "Failed to read plugin name from file\n");
    }

    fclose(file);
}

int main() {
    Plugin plugins[3];
    int num_plugins = 3;

    for (int i = 0; i < num_plugins; i++) {
        printf("Enter filename for plugin %d: ", i + 1);
        char filename[100];
        fgets(filename, sizeof(filename), stdin);

        // Remove newline character if present
        size_t len = strlen(filename);
        if (len > 0 && filename[len - 1] == '\n') {
            filename[len - 1] = '\0';
        }

        load_plugin(&plugins[i], filename);
    }

    printf("\nLoaded Plugins:\n");
    for (int i = 0; i < num_plugins; i++) {
        printf("%s\n", plugins[i].name);
    }

    return 0;
}
