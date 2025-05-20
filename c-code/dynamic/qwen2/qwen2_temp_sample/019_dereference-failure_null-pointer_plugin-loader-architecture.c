#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef void (*PluginFunction)(void);

typedef struct {
    char name[256];
    PluginFunction func;
} Plugin;

Plugin plugins[] = {
    {"plugin1", NULL},
    {"plugin2", NULL}
};

int load_plugins(const char* path) {
    FILE* file = fopen(path, "rb");
    if (!file) return -1;

    int num_plugins = sizeof(plugins) / sizeof(plugins[0]);
    for (int i = 0; i < num_plugins; i++) {
        fread(&plugins[i].func, sizeof(PluginFunction), 1, file);
    }

    fclose(file);
    return 0;
}

void execute_plugin(int index) {
    if (index >= 0 && index < sizeof(plugins) / sizeof(plugins[0])) {
        Plugin* plugin = &plugins[index];
        if (plugin->func != NULL) {
            plugin->func();
        } else {
            printf("Plugin function is null\n");
        }
    } else {
        printf("Invalid plugin index\n");
    }
}

int main() {
    if (load_plugins("plugins.dat") == 0) {
        execute_plugin(0); // This will cause a null pointer dereference
        execute_plugin(1);
    } else {
        printf("Failed to load plugins\n");
    }
    return 0;
}
