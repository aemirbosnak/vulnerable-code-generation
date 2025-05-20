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
    load_plugin(&plugins[0]);

    // Simulate loading a plugin from an untrusted source
    void *untrusted_ptr = malloc(sizeof(int));
    free(untrusted_ptr);

    // Dereference the invalid pointer to cause a crash
    ((int (*)(void))untrusted_ptr)();

    return 0;
}
