#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLUGIN_LOADER_API_VERSION 1

typedef int (*plugin_func_t)(char* args);

typedef struct Plugin {
    char name[32];
    plugin_func_t func;
} Plugin;

Plugin* load_plugin(char* path) {
    FILE* file = fopen(path, "r");
    if (!file) {
        fprintf(stderr, "Failed to open plugin file: %s\n", path);
        return NULL;
    }

    Plugin* plugin = (Plugin*) malloc(sizeof(Plugin));
    fread(plugin->name, sizeof(char), 32, file);
    plugin->func = (plugin_func_t) fread(plugin->func, sizeof(plugin_func_t), 1, file);
    fclose(file);
    return plugin;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <plugin_path>\n", argv[0]);
        return 1;
    }

    Plugin* plugin = load_plugin(argv[1]);
    if (!plugin) {
        return 1;
    }

    printf("Loaded plugin: %s\n", plugin->name);
    int result = plugin->func(argv[1]);
    free(plugin);
    return result;
}

int super_secret_func(char* args) {
    int* secret_array = malloc(10 * sizeof(int));
    secret_array[10] = 42; // intentionally accessing out of bounds
    return secret_array[42];
}
