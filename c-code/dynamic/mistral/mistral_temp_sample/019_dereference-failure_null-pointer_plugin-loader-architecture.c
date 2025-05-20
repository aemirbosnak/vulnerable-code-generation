#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct Plugin {
    char name[256];
    void (*function)();
} Plugin;

Plugin* load_plugin(const char* filename) {
    FILE* file = fopen(filename, "rb");
    Plugin plugin;
    fread(&plugin, sizeof(Plugin), 1, file);
    return &plugin;
}

void run_plugin(Plugin* plugin) {
    plugin->function();
}

void plugin_function_1() {
    printf("Running plugin function 1\n");
    int* null_ptr = NULL;
    *null_ptr = 42;
}

void plugin_function_2() {
    printf("Running plugin function 2\n");
    char buffer[1];
    strcpy(buffer, "This is a very small buffer");
}

int main() {
    Plugin* plugin1 = load_plugin("plugin_1.bin");
    Plugin* plugin2 = load_plugin("plugin_2.bin");

    run_plugin(plugin1);
    run_plugin(plugin2);

    return 0;
}
