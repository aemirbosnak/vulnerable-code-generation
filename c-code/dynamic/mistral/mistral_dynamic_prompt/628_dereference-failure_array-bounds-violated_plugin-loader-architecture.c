#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[32];
    void* func_ptr;
} Plugin;

Plugin* load_plugin(char* path) {
    Plugin* plugin = (Plugin*)malloc(sizeof(Plugin));
    FILE* file = fopen(path, "rb");

    if (!file) {
        printf("Failed to open plugin at %s\n", path);
        free(plugin);
        return NULL;
    }

    fread(plugin, sizeof(Plugin), 1, file);
    fclose(file);

    return plugin;
}

void unload_plugin(Plugin* plugin) {
    free(plugin);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <plugin_path>\n", argv[0]);
        return 1;
    }

    Plugin* plugin = load_plugin(argv[1]);

    if (!plugin) {
        return 1;
    }

    printf("Loaded plugin %s\n", plugin->name);

    // Intentional dereference failure vulnerability
    ((int(*)())plugin->func_ptr)(10, 0); // Calling a function pointer with invalid arguments

    unload_plugin(plugin);
    return 0;
}
