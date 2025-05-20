//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PLUGINS 10
#define MAX_PLUGIN_NAME_LEN 32

typedef struct {
    char name[MAX_PLUGIN_NAME_LEN];
    void (*init)(void);
    void (*destroy)(void);
} Plugin;

int num_plugins = 0;
Plugin *plugins = NULL;

void load_plugin(const char *name, void (*init_func)(void), void (*destroy_func)(void)) {
    if (num_plugins >= MAX_PLUGINS) {
        printf("Error: Too many plugins loaded.\n");
        return;
    }

    Plugin *plugin = malloc(sizeof(Plugin));
    strncpy(plugin->name, name, MAX_PLUGIN_NAME_LEN);
    plugin->init = init_func;
    plugin->destroy = destroy_func;

    plugins = realloc(plugins, sizeof(Plugin) * (num_plugins + 1));
    plugins[num_plugins++] = *plugin;
}

void unload_plugin(const char *name) {
    for (int i = 0; i < num_plugins; i++) {
        if (strcmp(plugins[i].name, name) == 0) {
            plugins[i].destroy();
            plugins[i].init = NULL;
            plugins[i].destroy = NULL;

            num_plugins--;
            plugins = realloc(plugins, sizeof(Plugin) * num_plugins);

            break;
        }
    }
}

void init_plugins(void) {
    for (int i = 0; i < num_plugins; i++) {
        plugins[i].init();
    }
}

void destroy_plugins(void) {
    for (int i = num_plugins - 1; i >= 0; i--) {
        plugins[i].destroy();
    }
}

// Example plugin
void example_init(void) {
    printf("Example plugin initialized.\n");
}

void example_destroy(void) {
    printf("Example plugin destroyed.\n");
}

int main(int argc, char **argv) {
    load_plugin("example", example_init, example_destroy);
    init_plugins();

    printf("Running plugins...\n");
    for (int i = 0; i < num_plugins; i++) {
        printf(" - %s\n", plugins[i].name);
    }

    destroy_plugins();
    unload_plugin("example");

    return 0;
}