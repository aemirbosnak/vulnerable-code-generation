#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[100];
    void (*func)();
} Plugin;

Plugin* plugins[10];
int plugin_count = 0;

void load_plugin(Plugin* plugin) {
    plugins[plugin_count++] = plugin;
    printf("Loaded plugin: %s\n", plugin->name);
}

void list_plugins() {
    for (int i = 0; i < plugin_count; i++) {
        printf("%d: %s\n", i, plugins[i]->name);
    }
}

void run_plugin(int index) {
    if (index >= plugin_count) {
        printf("Invalid plugin index\n");
        return;
    }
    (plugins[index]->func)();
}

void plugin_func_example() {
    printf("Executing example plugin function\n");
}

int main() {
    Plugin example_plugin = {"example_plugin", plugin_func_example};
    load_plugin(&example_plugin);

    char buffer[10];
    printf("Enter the index of the plugin to run: ");
    scanf("%s", buffer);
    run_plugin(atoi(buffer));

    return 0;
}
