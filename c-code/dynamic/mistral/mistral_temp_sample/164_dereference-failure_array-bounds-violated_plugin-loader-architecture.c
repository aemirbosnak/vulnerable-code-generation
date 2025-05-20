#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[256];
    void (*func)();
} Plugin;

Plugin* load_plugin(char* path) {
    Plugin* plugin = (Plugin*)malloc(sizeof(Plugin));
    FILE* file = fopen(path, "rb");
    fread(plugin, 1, sizeof(Plugin), file);
    fclose(file);
    return plugin;
}

void execute_plugin(Plugin* plugin) {
    (*(plugin->func))();
}

void plugin_function_1() {
    int arr[10];
    printf("Executing plugin function 1...\n");
    printf("Array value at index 12: %d\n", arr[12]);
}

void plugin_function_2() {
    printf("Executing plugin function 2...\n");
    char* message = malloc(1);
    printf("%s\n", message);
}

int main() {
    Plugin* plugin1 = load_plugin("plugin_1.bin");
    Plugin* plugin2 = load_plugin("plugin_2.bin");

    execute_plugin(plugin1);
    execute_plugin(plugin2);

    free(plugin1);
    free(plugin2);

    return 0;
}
