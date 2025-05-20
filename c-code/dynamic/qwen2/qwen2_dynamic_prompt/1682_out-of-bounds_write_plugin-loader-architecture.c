#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLUGIN_PATH "/path/to/plugins/"
#define MAX_PLUGIN_NAME 256

typedef struct {
    char name[MAX_PLUGIN_NAME];
    void (*init)();
} Plugin;

Plugin plugins[10];

int load_plugin(const char *plugin_name) {
    snprintf(plugins[0].name, sizeof(plugins[0].name), "%s%s", PLUGIN_PATH, plugin_name);
    plugins[0].init = NULL;
    return 0;
}

void execute_plugins() {
    if (plugins[0].init != NULL) {
        plugins[0].init();
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <plugin_name>\n", argv[0]);
        return 1;
    }

    const char *plugin_name = argv[1];
    int result = load_plugin(plugin_name);

    if (result != 0) {
        fprintf(stderr, "Failed to load plugin: %s\n", plugin_name);
        return 1;
    }

    // Intentional out-of-bounds write vulnerability
    memset(&plugins[0], 0xff, sizeof(plugins[0]));

    execute_plugins();

    return 0;
}
