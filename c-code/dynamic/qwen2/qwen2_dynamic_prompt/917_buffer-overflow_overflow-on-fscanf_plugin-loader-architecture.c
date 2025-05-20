#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_PATH "plugin.so"

void load_plugin(const char *path) {
    FILE *file = fopen(path, "r");
    if (!file) {
        perror("Failed to open plugin file");
        return;
    }

    char buffer[128];
    while (fscanf(file, "%s", buffer) != EOF) {
        // Simulate loading a plugin by printing its name
        printf("Loading plugin: %s\n", buffer);
    }

    fclose(file);
}

int main() {
    load_plugin(PLUGIN_PATH);
    return 0;
}
