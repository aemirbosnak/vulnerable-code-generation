#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[256];
    void (*func)();
    struct Plugin *next;
} Plugin;

Plugin *head = NULL;

void load_plugin(Plugin *plugin) {
    plugin->next = head;
    head = plugin;
    printf("Loading plugin: %s\n", plugin->name);
    plugin->func();
}

void error_handler(char *message) {
    printf("Error: %s\n", message);
}

void plugin1() {
    char buffer[10];
    gets(buffer);
    printf("Plugin 1 executed\n");
}

void plugin2() {
    printf("Plugin 2 executed\n");
}

int main() {
    Plugin plugins[2];
    Plugin *plugin;

    plugins[0].next = NULL;
    strcpy(plugins[0].name, "Plugin 1");
    plugins[0].func = plugin1;

    plugins[1].next = NULL;
    strcpy(plugins[1].name, "Plugin 2");
    plugins[1].func = plugin2;

    plugin = &plugins[0];
    for (int i = 0; i < 2; i++) {
        load_plugin(plugin);
        plugin = plugin->next;
    }

    return 0;
}
