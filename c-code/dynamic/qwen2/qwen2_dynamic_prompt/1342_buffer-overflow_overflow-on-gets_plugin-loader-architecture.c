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
    snprintf(plugins[plugin_count].name, MAX_PLUGIN_NAME, "%s%s", PLUGIN_PATH, plugin_name);
    printf("Loading plugin: %s\n", plugins[plugin_count].name);

    // Simulate loading plugin by calling its init function
    plugins[plugin_count].init();
    plugin_count++;
}

void execute_plugins() {
    for (int i = 0; i < plugin_count; i++) {
        printf("Executing plugin: %s\n", plugins[i].name);
        // Simulate plugin execution
    }
}

int main() {
    printf("Welcome to the Plugin Loader Architecture!\n");

    // Vulnerability: Buffer overflow due to use of gets()
    printf("Enter the name of the plugin to load: ");
    char plugin_name[32];
    gets(plugin_name); // Use of gets() intentionally for demonstration purposes

    load_plugin(plugin_name);
    execute_plugins();

    return 0;
}
