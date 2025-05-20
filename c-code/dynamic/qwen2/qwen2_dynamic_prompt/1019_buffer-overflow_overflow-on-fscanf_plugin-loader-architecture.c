#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_PATH "plugin.txt"

void load_plugin() {
    char buffer[10];
    FILE *file = fopen(PLUGIN_PATH, "r");
    if (file == NULL) {
        printf("Failed to open plugin file.\n");
        return;
    }
    fscanf(file, "%s", buffer);
    fclose(file);
    printf("Loaded plugin: %s\n", buffer);
}

int main() {
    load_plugin();
    return 0;
}
