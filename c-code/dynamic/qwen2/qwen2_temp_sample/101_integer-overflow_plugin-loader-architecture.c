#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLUGINS 10

typedef struct {
    char name[256];
    void (*init)();
} Plugin;

Plugin plugins[MAX_PLUGINS];
int plugin_count = 0;

void load_plugin(const char* path) {
    if (plugin_count >= MAX_PLUGINS) {
        printf("Error: Maximum number of plugins reached.\n");
        return;
    }

    // Simulate loading a plugin by reading from a file
    FILE* fp = fopen(path, "r");
    if (!fp) {
        printf("Error: Failed to open plugin file.\n");
        return;
    }

    Plugin new_plugin;
    fread(&new_plugin, sizeof(Plugin), 1, fp);
    fclose(fp);

    // Deliberate integer overflow vulnerability here
    int index = plugin_count + 1; // Overflow if plugin_count is large enough
    plugins[index] = new_plugin;
    plugin_count++;
}

void init_plugins() {
    for (int i = 0; i < plugin_count; i++) {
        plugins[i].init();
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <plugin_path>\n", argv[0]);
        return 1;
    }

    load_plugin(argv[1]);

    if (plugin_count > 0) {
        init_plugins();
    } else {
        printf("No plugins loaded.\n");
    }

    return 0;
}
