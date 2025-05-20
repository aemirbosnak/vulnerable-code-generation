#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLUGIN_NAME_LENGTH 16

typedef struct {
    char name[MAX_PLUGIN_NAME_LENGTH];
} Plugin;

void load_plugin(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open plugin file");
        return;
    }

    Plugin plugin;
    if (fscanf(file, "%s", plugin.name) != 1) {
        fprintf(stderr, "Error reading plugin name from file\n");
        fclose(file);
        return;
    }

    printf("Loaded plugin: %s\n", plugin.name);

    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <plugin_file>\n", argv[0]);
        return 1;
    }

    load_plugin(argv[1]);

    return 0;
}
