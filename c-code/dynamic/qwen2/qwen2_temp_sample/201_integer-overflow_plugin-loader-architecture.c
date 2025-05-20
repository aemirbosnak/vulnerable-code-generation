#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_PATH "/path/to/plugin"

typedef struct {
    int data;
} Plugin;

Plugin* load_plugin(const char* path) {
    FILE* file = fopen(path, "rb");
    if (!file) {
        perror("Failed to open plugin file");
        return NULL;
    }

    Plugin* plugin = (Plugin*)malloc(sizeof(Plugin));
    if (!plugin) {
        perror("Failed to allocate memory for plugin");
        fclose(file);
        return NULL;
    }

    size_t bytes_read = fread(&plugin->data, sizeof(int), 1, file);
    if (bytes_read != 1) {
        perror("Failed to read plugin data");
        free(plugin);
        fclose(file);
        return NULL;
    }

    fclose(file);
    return plugin;
}

void execute_plugin(Plugin* plugin) {
    int result = plugin->data * 2; // Integer overflow vulnerability here

    printf("Executing plugin with data: %d\n", result);
}

int main() {
    Plugin* plugin = load_plugin(PLUGIN_PATH);
    if (plugin) {
        execute_plugin(plugin);
        free(plugin);
    }
    return 0;
}
