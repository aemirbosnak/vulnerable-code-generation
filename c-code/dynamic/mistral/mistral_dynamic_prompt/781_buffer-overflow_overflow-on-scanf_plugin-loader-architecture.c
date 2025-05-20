#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[256];
    char path[512];
    void* func_ptr;
} Plugin;

Plugin* plugins[10];
int num_plugins = 0;

void load_plugin(char* name, char* path) {
    Plugin* new_plugin = (Plugin*)malloc(sizeof(Plugin));
    strcpy(new_plugin->name, name);
    strcpy(new_plugin->path, path);
    plugins[num_plugins++] = new_plugin;
}

void* get_plugin_func_ptr(char* name) {
    for (int i = 0; i < num_plugins; i++) {
        if (strcmp(plugins[i]->name, name) == 0) {
            return plugins[i]->func_ptr;
        }
    }
    return NULL;
}

int main() {
    char input[1024];
    char buffer[10];

    printf("Enter plugin name:\n");
    scanf("%s%s", input, buffer);

    void (*plugin_func)() = (void(*)())get_plugin_func_ptr(input);
    if (plugin_func != NULL) {
        printf("Loaded plugin: %s\n", input);
        plugin_func();
    } else {
        printf("Plugin not found.\n");
    }

    return 0;
}
