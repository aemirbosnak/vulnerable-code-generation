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

void load_plugin(Plugin *plugin, const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Failed to open file: %s\n", filename);
        return;
    }
    fread(plugin->data, 1, PLUGIN_SIZE, file);
    fclose(file);
}

void execute_plugin(Plugin *plugin) {
    // Simulate execution by printing the first 10 characters
    for (int i = 0; i < 10 && plugin->data[i] != '\0'; i++) {
        putchar(plugin->data[i]);
    }
    putchar('\n');
}

int main() {
    Plugin plugins[3];
    const char *filenames[] = {"plugin1.bin", "plugin2.bin", "plugin3.bin"};

    for (int i = 0; i < 3; i++) {
        load_plugin(&plugins[i], filenames[i]);
    }

    for (int i = 0; i < 3; i++) {
        execute_plugin(&plugins[i]);
    }

    return 0;
}
