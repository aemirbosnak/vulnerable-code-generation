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
    for (int i = 0; i <= plugin_count; i++) { // Out-of-bounds write
        if (plugins[i].function) {
            plugins[i].function();
        }
    }
}

void plugin_function_1(void) {
    printf("Executing plugin function 1\n");
}

void plugin_function_2(void) {
    printf("Executing plugin function 2\n");
}

int main() {
    load_plugin("plugin1.bin");
    load_plugin("plugin2.bin");

    execute_plugins();

    return 0;
}
