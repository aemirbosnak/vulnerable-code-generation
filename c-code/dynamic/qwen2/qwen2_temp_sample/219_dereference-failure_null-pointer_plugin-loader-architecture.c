#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a plugin
typedef struct Plugin {
    int (*init)();
    void (*run)();
} Plugin;

// Function to simulate loading a plugin
Plugin* load_plugin(const char* name) {
    if (strcmp(name, "good_plugin") == 0) {
        static Plugin good_plugin = { .init = NULL, .run = NULL };
        return &good_plugin;
    } else if (strcmp(name, "bad_plugin") == 0) {
        static Plugin bad_plugin = { .init = NULL, .run = (void*)NULL };
        return &bad_plugin;
    } else {
        return NULL;
    }
}

int main() {
    // Load a bad plugin
    Plugin* plugin = load_plugin("bad_plugin");

    // Attempt to call the run function of the plugin
    if (plugin != NULL) {
        printf("Running plugin...\n");
        plugin->run(); // This will cause a null pointer dereference
    } else {
        printf("Failed to load plugin\n");
    }

    return 0;
}
