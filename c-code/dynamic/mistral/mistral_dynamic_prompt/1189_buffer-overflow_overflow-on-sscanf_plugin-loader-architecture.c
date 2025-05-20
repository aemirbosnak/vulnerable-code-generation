#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* Plugin;

Plugin load_plugin(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open plugin file: %s\n", filename);
        return NULL;
    }

    char buffer[10];
    fgets(buffer, sizeof(buffer), file); // Vulnerable sscanf call with buffer overflow
    fclose(file);

    char* plugin_name = strtok(buffer, "\n");
    Plugin plugin = malloc(strlen(plugin_name) + 1);
    strcpy(plugin, plugin_name);

    return plugin;
}

void unload_plugin(Plugin plugin) { free(plugin); }

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <plugin_file>\n", argv[0]);
        return 1;
    }

    Plugin plugin = load_plugin(argv[1]);
    if (!plugin) return 1;

    printf("Loaded plugin: %s\n", plugin);
    unload_plugin(plugin);

    return 0;
}
