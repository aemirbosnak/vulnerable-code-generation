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
        fprintf(stderr, "Too many plugins\n");
        return;
    }

    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open plugin file");
        return;
    }

    char buffer[256];
    if (!fgets(buffer, sizeof(buffer), file)) {
        fclose(file);
        perror("Failed to read plugin name");
        return;
    }
    buffer[strcspn(buffer, "\n")] = '\0';

    plugins[plugin_count].name = strdup(buffer);

    if (!fgets(buffer, sizeof(buffer), file)) {
        free(plugins[plugin_count].name);
        fclose(file);
        perror("Failed to read plugin init function");
        return;
    }
    buffer[strcspn(buffer, "\n")] = '\0';

    // Simulate loading plugin by setting up a dummy init function
    plugins[plugin_count].init = NULL;

    printf("Loaded plugin: %s\n", plugins[plugin_count].name);
    plugin_count++;
}

void unload_plugins() {
    for (int i = 0; i < plugin_count; i++) {
        free(plugins[i].name);
        plugins[i].name = NULL;
        plugins[i].init = NULL;
    }
    plugin_count = 0;
}

void use_after_free_vulnerability() {
    if (plugin_count == 0) {
        printf("No plugins loaded\n");
        return;
    }

    // Use after free vulnerability
    printf("Using plugin: %s\n", plugins[0].name);
    plugins[0].init(); // This will crash because plugins[0].init is NULL
}

int main() {
    load_plugin("plugin1.txt");
    load_plugin("plugin2.txt");

    use_after_free_vulnerability();

    unload_plugins();

    return 0;
}
