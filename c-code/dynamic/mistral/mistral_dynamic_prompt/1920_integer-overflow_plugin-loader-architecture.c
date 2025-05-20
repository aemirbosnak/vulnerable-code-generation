#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLUGIN_SIZE 1024

typedef struct {
    char name[32];
    void (*func)();
    int size;
} Plugin;

Plugin load_plugin(char *path) {
    Plugin plugin;
    FILE *fp = fopen(path, "rb");

    if (!fp) {
        printf("Failed to open plugin file: %s\n", path);
        return (Plugin){0};
    }

    fread(&plugin, sizeof(Plugin), 1, fp);
    fread(plugin.name, sizeof(char), plugin.size, fp);
    plugin.name[plugin.size] = '\0';

    if (plugin.size > PLUGIN_SIZE || plugin.size <= 0) {
        printf("Invalid plugin size: %d\n", plugin.size);
        return (Plugin){0};
    }

    plugin.func = (void(*)())(int)fp; // integer overflow vulnerability

    fclose(fp);
    return plugin;
}

void execute_plugin(Plugin plugin) {
    plugin.func();
}

int main() {
    Plugin plugin;
    char input[256];

    printf("Enter plugin path: ");
    fgets(input, sizeof(input), stdin);

    plugin = load_plugin(input);

    if (plugin.name[0])
        execute_plugin(plugin);
    else
        printf("Failed to load plugin\n");

    return 0;
}
