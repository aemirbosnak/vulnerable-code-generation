#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int (*plugin_func)();
} Plugin;

int malicious_plugin() {
    return 42;
}

int main() {
    Plugin *plugins = malloc(sizeof(Plugin));
    if (!plugins) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Simulate loading a plugin
    plugins->plugin_func = malicious_plugin;

    // Dereference an invalid pointer to cause a crash
    ((void (*)(void))NULL)();

    free(plugins);
    return 0;
}
