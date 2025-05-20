#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLUGINS 10

typedef struct {
    char *name;
    void (*init)();
} Plugin;

Plugin plugins[MAX_PLUGINS];
int plugin_count = 0;

void load_plugin(const char *filename) {
    if (plugin_count >= MAX_PLUGINS) {
        printf("Error: Maximum number of plugins reached.\n");
        return;
    }

    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    char buffer[256];
    if (fgets(buffer, sizeof(buffer), file)) {
        size_t len = strlen(buffer);
        if (buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
        plugins[plugin_count].name = strdup(buffer);
    } else {
        fclose(file);
        printf("Error: Invalid plugin name in file %s\n", filename);
        return;
    }

    plugins[plugin_count].init = NULL; // Placeholder for actual initialization function
    plugin_count++;
}

void initialize_plugins() {
    for (int i = 0; i < plugin_count; i++) {
        if (plugins[i].init) {
            plugins[i].init();
        }
    }
}

void unload_plugins() {
    for (int i = 0; i < plugin_count; i++) {
        free(plugins[i].name);
        plugins[i].name = NULL;
        plugins[i].init = NULL;
    }
    plugin_count = 0;
}

int main() {
    load_plugin("plugin1.txt");
    load_plugin("plugin2.txt");

    initialize_plugins();

    unload_plugins(); // This should cause a use-after-free error

    // Deliberate use-after-free vulnerability
    printf("%s\n", plugins[0].name); // Accessing freed memory

    return 0;
}
