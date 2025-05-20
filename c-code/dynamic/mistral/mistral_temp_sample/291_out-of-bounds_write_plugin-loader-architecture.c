#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[10];
    void (*func)();
    char data[0]; // dynamically allocated size
} Plugin;

Plugin* load_plugin(const char* path) {
    FILE* file = fopen(path, "rb");
    Plugin* plugin = malloc(sizeof(Plugin) + strlen(path) + 1);

    fread(plugin->name, strlen(path) + 1, 1, file);
    fread(&plugin->func, sizeof(void(*)()), 1, file);

    // overwriting the plugin data with arbitrary data from the file
    fread(plugin->data, 1024, 1024, file);

    fclose(file);
    return plugin;
}

void run_plugin(Plugin* plugin) {
    (*plugin->func)();
}

int main() {
    Plugin* plugin = load_plugin("malicious_plugin.bin");
    run_plugin(plugin);

    // leaking the loaded plugin on the heap
    free(plugin);

    return 0;
}
