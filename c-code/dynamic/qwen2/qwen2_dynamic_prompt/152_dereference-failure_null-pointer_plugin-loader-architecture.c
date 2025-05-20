#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
} Plugin;

Plugin* load_plugin(const char* name) {
    if (strcmp(name, "valid_plugin") == 0) {
        return malloc(sizeof(Plugin));
    } else {
        return NULL;
    }
}

void use_plugin(Plugin* plugin) {
    printf("Using plugin with data: %d\n", plugin->data);
}

int main() {
    const char* plugin_name = "invalid_plugin";
    Plugin* plugin = load_plugin(plugin_name);

    // Deliberate dereference failure
    use_plugin(plugin); // This will cause a null pointer dereference

    free(plugin); // Freeing the allocated memory to avoid memory leak

    return 0;
}
