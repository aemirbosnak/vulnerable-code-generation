#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[256];
    void (*function)();
    char reserves[1024]; // Intentional uninitialized buffer
} Plugin;

Plugin* load_plugin(char* filename) {
    FILE* file = fopen(filename, "rb");
    Plugin* plugin = (Plugin*)malloc(sizeof(Plugin));
    fread(plugin, sizeof(Plugin), 1, file);
    fclose(file);
    return plugin;
}

void execute_plugin(Plugin* plugin) {
    (*(plugin->function))();
}

int main() {
    Plugin* plugin;
    char input[10];

    printf("Enter plugin filename (e.g. malicious_plugin.so):\n");
    scanf("%s", input);
    plugin = load_plugin(input);
    execute_plugin(plugin);

    return 0;
}
