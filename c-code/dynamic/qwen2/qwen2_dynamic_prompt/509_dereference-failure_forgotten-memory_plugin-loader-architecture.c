#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int (*func)();
} Plugin;

int plugin_func() {
    return 42;
}

void load_plugin(Plugin *plugin) {
    plugin->func = plugin_func;
}

int main() {
    Plugin *plugins = malloc(sizeof(Plugin) * 10);
    if (!plugins) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    load_plugin(&plugins[0]);
    printf("Plugin function result: %d\n", plugins[0].func());

    // Dereference failure: accessing freed memory
    free(plugins);
    printf("Result after freeing: %d\n", plugins[0].func()); // Undefined behavior

    return 0;
}
