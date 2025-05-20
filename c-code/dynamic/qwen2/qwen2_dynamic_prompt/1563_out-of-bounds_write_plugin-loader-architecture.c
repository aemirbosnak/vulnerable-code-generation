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
    PluginFunction func;
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
    fread(&new_plugin.func, sizeof(new_plugin.func), 1, file);

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
        printf("Executing plugin: %s\n", plugins[i].name);
        plugins[i].func();
    }
}

int main() {
    // Simulate loading plugins
    load_plugin("plugin1.so");
    load_plugin("plugin2.so");

    // Execute all loaded plugins
    execute_plugins();

    return 0;
}
