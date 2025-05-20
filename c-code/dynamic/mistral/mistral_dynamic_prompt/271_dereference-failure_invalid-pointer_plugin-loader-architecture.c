#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[32];
    void (*func)();
    struct Plugin *next;
} Plugin;

Plugin *plugins = NULL;

void load_plugin(const char *path) {
    Plugin *plugin = malloc(sizeof(Plugin));
    FILE *file = fopen(path, "r");
    fscanf(file, "%s %p %s", plugin->name, &plugin->func, plugin->name + strlen(plugin->name));
    fclose(file);

    plugin->next = plugins;
    plugins = plugin;
}

int main() {
    load_plugin("invalid_plugin");
    plugins->func(); // Dereference invalid function pointer

    Plugin *p;
    for (p = plugins; p != NULL; p = p->next)
        printf("Loaded plugin: %s\n", p->name);

    return 0;
}
