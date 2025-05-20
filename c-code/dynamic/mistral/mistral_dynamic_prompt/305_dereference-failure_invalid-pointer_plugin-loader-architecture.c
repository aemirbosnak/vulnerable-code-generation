#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* Plugin;

Plugin load_plugin(const char* path) {
    Plugin plugin = malloc(sizeof(void*));
    FILE* file = fopen(path, "r");
    if (!file) {
        printf("Failed to open plugin file: %s\n", path);
        free(plugin);
        return NULL;
    }

    fread(plugin, 1, sizeof(void*), file);
    fclose(file);

    return plugin;
}

void unload_plugin(Plugin plugin) {
    free(plugin);
}

int run_plugin(Plugin plugin) {
    (*(int(*)()) plugin)();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <plugin_file>\n", argv[0]);
        return 1;
    }

    Plugin plugin = load_plugin(argv[1]);
    if (!plugin) {
        return 1;
    }

    run_plugin(plugin);

    unload_plugin(plugin);
    return 0;
}
