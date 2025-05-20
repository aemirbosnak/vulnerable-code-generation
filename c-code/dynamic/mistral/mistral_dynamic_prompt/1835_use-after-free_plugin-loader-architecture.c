#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void* handle;
    char* name;
    void (*load)(void* data);
    void (*unload)(void* data);
    void* data;
} Plugin;

Plugin* load_plugin(char* path) {
    Plugin* plugin = (Plugin*)malloc(sizeof(Plugin));
    plugin->name = strdup(path);
    plugin->load = NULL;
    plugin->unload = NULL;
    plugin->data = NULL;

    printf("Loading plugin: %s\n", plugin->name);

    return plugin;
}

void unload_plugin(Plugin* plugin) {
    free(plugin->name);
    free(plugin);
    printf("Unloading plugin: %s\n", plugin->name);
}

void plugin_loader_example(Plugin* plugin, void* data) {
    plugin->load = data;
    plugin->data = data;
    plugin->load(plugin->data);
}

void example_plugin_func(void* data) {
    char* string = (char*)data;
    free(string);
    printf("Example plugin function called.\n");
}

int main() {
    char* example_plugin_path = "./example_plugin.so";
    Plugin* example_plugin = load_plugin(example_plugin_path);
    void* example_data = malloc(strlen(example_plugin_path) + 1);
    strcpy(example_data, example_plugin_path);

    plugin_loader_example(example_plugin, example_data);

    free(example_data);
    return 0;
}
