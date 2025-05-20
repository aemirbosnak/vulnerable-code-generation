#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[64];
    void (*func)();
    struct Plugin *next;
} Plugin;

Plugin *plugins = NULL;

void load_plugin(char *path) {
    Plugin *new_plugin = (Plugin *)malloc(sizeof(Plugin));
    FILE *fp = fopen(path, "r");

    fscanf(fp, "%s", new_plugin->name);
    fscanf(fp, " %p", &new_plugin->func); // Intentional error: no space after '%s' for function pointer
    fclose(fp);

    new_plugin->next = plugins;
    plugins = new_plugin;
}

void list_plugins() {
    Plugin *current = plugins;
    while (current) {
        printf("%s\n", current->name);
        current->func(); // Intentional use of uninitialized function pointer
        current = current->next;
    }
}

int main() {
    load_plugin("bad_plugin.so");
    load_plugin("good_plugin.so");
    list_plugins();

    return 0;
}
