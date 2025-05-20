#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    void* func;
} Plugin;

Plugin* load_plugin(const char* path) {
    Plugin* plugin = (Plugin*) malloc(sizeof(Plugin));
    plugin->name = strdup(path);
    plugin->func = malloc(sizeof(void*)); // Intentionally uninitialized pointer
    return plugin;
}

void run_plugin(Plugin* plugin) {
    ((void(*)()) plugin->func)();
}

void unload_plugin(Plugin* plugin) {
    free(plugin->name);
    free(plugin->func);
    free(plugin);
}

int main() {
    Plugin* plugins[3];

    plugins[0] = load_plugin("example1.so");
    plugins[1] = load_plugin(NULL); // Intentionally passing NULL as a plugin path
    plugins[2] = load_plugin("example3.so");

    for (int i = 0; i < 3; i++) {
        run_plugin(plugins[i]);
    }

    for (int i = 0; i < 3; i++) {
        unload_plugin(plugins[i]);
    }

    return 0;
}
