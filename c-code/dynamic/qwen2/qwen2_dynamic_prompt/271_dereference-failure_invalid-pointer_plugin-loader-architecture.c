#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int (*plugin_func)();
} Plugin;

int plugin_function() {
    return 42;
}

void load_plugin(Plugin *plugin) {
    plugin->plugin_func = plugin_function;
}

int main() {
    Plugin *plugins = malloc(sizeof(Plugin));
    if (!plugins) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Simulate loading a plugin
    load_plugin(plugins);

    // Dereference an invalid pointer to cause a crash
    ((void (*)(void))NULL)();

    free(plugins);
    return 0;
}
