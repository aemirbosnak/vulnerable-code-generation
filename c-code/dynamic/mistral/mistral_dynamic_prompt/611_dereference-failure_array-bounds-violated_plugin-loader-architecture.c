#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLUGIN_LOADER_MAGIC_CODE "PLUGIN_LOADER_ROCKS"

typedef struct Plugin {
    char name[64];
    void (*load)();
    void (*unload)();
} Plugin;

Plugin* load_plugin(char* path) {
    FILE* file = fopen(path, "rb");
    Plugin* plugin = (Plugin*)malloc(sizeof(Plugin));
    fread(plugin, 1, sizeof(Plugin), file);
    if (strcmp(plugin->name, PLUGIN_LOADER_MAGIC_CODE) == 0) {
        (plugin->load)();
        return plugin;
    }
    free(plugin);
    return NULL;
}

void do_something_evil(void) {
    char* data = malloc(sizeof(char) * 5);
    printf("Evil function executing...\n");
    printf(data);
    // Accessing uninitialized memory
    printf("%c\n", data[5]);
}

void plugin1_load() {
    do_something_evil();
}

int main() {
    char* path = "path/to/plugin1.bin";
    Plugin* plugin = load_plugin(path);
    if (plugin != NULL) {
        (plugin->unload)();
    }
    return 0;
}
