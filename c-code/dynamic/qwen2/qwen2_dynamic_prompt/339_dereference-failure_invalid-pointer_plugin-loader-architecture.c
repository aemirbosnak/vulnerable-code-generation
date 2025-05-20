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
    Plugin plugins[10];
    for (int i = 0; i < 10; i++) {
        load_plugin(&plugins[i]);
    }

    // Simulate loading a plugin from an untrusted source
    void *untrusted_ptr = malloc(sizeof(Plugin));
    if (!untrusted_ptr) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Dereference the invalid pointer to cause a crash
    ((Plugin *)untrusted_ptr)->func();

    free(untrusted_ptr);
    return 0;
}
