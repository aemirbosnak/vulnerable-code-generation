#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[256];
    void (*func)();
} Plugin;

Plugin* plugins[10];
int num_plugins = 0;

void load_plugin(Plugin* plugin) {
    plugins[num_plugins++] = plugin;
}

void list_plugins() {
    for (int i = 0; i < num_plugins; i++) {
        printf("Plugin %d: %s\n", i, plugins[i]->name);
    }
}

void execute_plugin(int index) {
    if (index >= 0 && index < num_plugins)
        plugins[index]->func();
    else
        printf("Invalid plugin index.\n");
}

void evil_plugin_func() {
    char buffer[128];
    printf("Executing evil plugin...\n");
    fscanf(stdin, "%s", buffer);
}

int main() {
    Plugin plugin = {"Evil Plugin", evil_plugin_func};
    load_plugin(&plugin);
    list_plugins();

    printf("\nEnter index of plugin to execute: ");
    int index;
    scanf("%d", &index);
    execute_plugin(index);

    return 0;
}
