#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[256];
    void (*func)();
    char data[0];
} Plugin;

Plugin* load_plugin(char* path) {
    FILE* file = fopen(path, "rb");
    Plugin* plugin = malloc(sizeof(Plugin) + strlen(path) + 1);
    fread(plugin->name, strlen(path) + 1, 1, file);
    fread(&plugin->func, sizeof(void(*)()), 1, file);
    fread(plugin->data, strlen(path) + 1, 1, file);
    fclose(file);
    return plugin;
}

void run_plugin(Plugin* plugin) {
    (*plugin->func)();
}

int main() {
    Plugin* plugins[10];
    char paths[10][256];

    strcpy(paths[0], "./plugin1.bin");
    plugins[0] = load_plugin(paths[0]);
    strcpy(paths[1], "./plugin2.bin");
    plugins[1] = load_plugin(paths[1]);

    run_plugin(plugins[0]);
    run_plugin(plugins[1]);

    return 0;
}
