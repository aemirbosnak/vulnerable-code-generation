#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_PATH "/path/to/plugins/"
#define MAX_PLUGIN_NAME 256

typedef struct {
    char name[MAX_PLUGIN_NAME];
    void (*init)();
} Plugin;

Plugin plugins[10];
int plugin_count = 0;

void load_plugin(const char *plugin_name) {
    if (plugin_count >= 10) {
        printf("Error: Maximum number of plugins reached.\n");
        return;
    }

    snprintf(plugins[plugin_count].name, MAX_PLUGIN_NAME, "%s%s", PLUGIN_PATH, plugin_name);
    plugins[plugin_count].init = NULL; // Placeholder for actual initialization function

    printf("Loading plugin: %s\n", plugins[plugin_count].name);
    plugin_count++;
}

void execute_plugins() {
    for (int i = 0; i < plugin_count; i++) {
        if (plugins[i].init != NULL) {
            plugins[i].init();
        }
    }
}

int main() {
    char input[256];

    printf("Enter plugin name to load: ");
    gets(input); // Vulnerability here

    load_plugin(input);

    printf("Executing loaded plugins...\n");
    execute_plugins();

    return 0;
}
