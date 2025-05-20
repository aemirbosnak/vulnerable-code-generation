#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[100];
    void (*func)();
} Plugin;

void load_plugin(char *filename) {
    Plugin plugin;
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Failed to open plugin file.\n");
        return;
    }

    fscanf(file, "%s", plugin.name); // Buffer overflow vulnerability
    plugin.func = (void(*)())strtoul(plugin.name, NULL, 10);

    if (plugin.func != NULL) {
        printf("Loading plugin: %s\n", plugin.name);
        (*plugin.func)();
    } else {
        printf("Invalid plugin format.\n");
    }

    fclose(file);
}

void dummy_plugin() {
    printf("Welcome to the exploited plugin loader!\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./plugin_loader <plugin_file>\n");
        return 1;
    }

    load_plugin(argv[1]);

    return 0;
}
