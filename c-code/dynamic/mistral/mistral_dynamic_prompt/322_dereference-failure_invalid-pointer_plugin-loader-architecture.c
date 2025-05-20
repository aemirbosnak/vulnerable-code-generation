#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef void* Plugin;

Plugin load_plugin(const char* path) {
    FILE* file = fopen(path, "rb");
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    rewind(file);

    Plugin plugin = malloc(size);
    fread(plugin, size, 1, file);
    fclose(file);

    return plugin;
}

void unload_plugin(Plugin plugin) {
    free(plugin);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s [path-to-plugin] [function-to-call]\n", argv[0]);
        return 1;
    }

    Plugin plugin = load_plugin(argv[1]);
    if (!plugin) {
        printf("Failed to load plugin.\n");
        return 1;
    }

    int (*function)(int, int) = (int(*)(int, int)) plugin;
    int result = function(2, 3);

    unload_plugin(plugin);

    printf("Result: %d\n", result);
    return 0;
}
