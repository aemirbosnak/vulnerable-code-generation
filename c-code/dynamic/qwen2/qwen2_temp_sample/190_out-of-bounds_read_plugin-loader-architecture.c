#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*PluginFunction)(void);

typedef struct {
    char name[16];
    PluginFunction func;
} Plugin;

#define MAX_PLUGINS 20

Plugin plugins[MAX_PLUGINS];
int plugin_count = 0;

void load_plugin(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) return;

    Plugin plugin;
    fread(&plugin.name, sizeof(plugin.name), 1, file);
    fread(&plugin.func, sizeof(PluginFunction), 1, file);

    if (strlen(plugin.name) > 15 || plugin_count >= MAX_PLUGINS) {
        fclose(file);
        return;
    }

    plugins[plugin_count++] = plugin;
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
