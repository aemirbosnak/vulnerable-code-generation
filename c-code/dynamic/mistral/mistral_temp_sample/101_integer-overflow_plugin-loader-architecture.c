#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[256];
    char function[256];
    void* function_ptr;
} Plugin;

Plugin* load_plugin(char* path) {
    Plugin* plugin = (Plugin*)malloc(sizeof(Plugin));
    FILE* file = fopen(path, "rb");
    fread(plugin, sizeof(Plugin), 1, file);
    fclose(file);
    plugin->function_ptr = (void*)(atoi(plugin->function + strlen(plugin->function) - 4));
    return plugin;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <plugin_path>\n", argv[0]);
        return 1;
    }

    Plugin* plugin = load_plugin(argv[1]);
    ((void(*)())plugin->function_ptr)();
    free(plugin);
    return 0;
}
