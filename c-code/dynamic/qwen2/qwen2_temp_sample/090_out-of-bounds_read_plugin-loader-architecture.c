#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_SIZE 1024

typedef struct {
    char data[PLUGIN_SIZE];
} Plugin;

void loadPlugin(Plugin *plugin, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Failed to open file: %s\n", filename);
        return;
    }
    fread(plugin->data, 1, PLUGIN_SIZE, file);
    fclose(file);
}

int main() {
    Plugin plugins[3];
    int index = 3; // Out-of-bounds access

    loadPlugin(&plugins[index], "nonexistent_plugin.bin");

    printf("Plugin loaded successfully.\n");

    return 0;
}
