#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLUGINS 10

typedef void (*PluginFunction)(void);

typedef struct {
    char name[256];
    PluginFunction function;
} Plugin;

Plugin plugins[MAX_PLUGINS];
int plugin_count = 0;

void load_plugin(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Failed to open plugin file: %s\n", filename);
        return;
    }

    Plugin new_plugin;
    fread(&new_plugin.name, sizeof(new_plugin.name), 1, file);
    fread(&new_plugin.function, sizeof(new_plugin.function), 1, file);

    if (plugin_count >= MAX_PLUGINS) {
        printf("Too many plugins loaded!\n");
        fclose(file);
        return;
    }

    plugins[plugin_count++] = new_plugin;
    fclose(file);
}

void execute_plugins() {
    for (int i = 0; i < plugin_count; i++) {
        plugins[i].function();
    }
}

void malicious_plugin(void) {
    // Out-of-bounds write vulnerability
    int buffer[10];
    memset(buffer, 0, sizeof(buffer));
    ((int*)buffer)[10] = 42; // Writing to an index out of bounds
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <plugin_file>\n", argv[0]);
        return 1;
    }

    load_plugin(argv[1]);

    // Intentionally loading a malicious plugin
    strcpy(plugins[plugin_count].name, "malicious_plugin");
    plugins[plugin_count].function = malicious_plugin;
    plugin_count++;

    execute_plugins();

    return 0;
}
