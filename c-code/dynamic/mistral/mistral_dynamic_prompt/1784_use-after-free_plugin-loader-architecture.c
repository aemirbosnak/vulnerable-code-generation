#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[64];
    void (*func)();
    struct Plugin* next;
} Plugin;

Plugin* head = NULL;

void load_plugin(char* path) {
    Plugin* plugin = (Plugin*)malloc(sizeof(Plugin));
    FILE* file = fopen(path, "r");
    if (!file) return;

    fscanf(file, "%s", plugin->name);
    fscanf(file, " %p", &plugin->func);
    fgetc(file); // consume newline

    plugin->next = head;
    head = plugin;
    fclose(file);
}

void use_plugin(char* name) {
    Plugin* current = head;
    while (current) {
        if (strcmp(current->name, name) == 0) {
            current->func();
            free(current);
            break;
        }
        current = current->next;
    }
}

int main() {
    load_plugin("plugin1.bin");
    load_plugin("plugin2.bin");

    use_plugin("plugin1");

    load_plugin("plugin3.bin"); // introduces use-after-free vulnerability by calling 'use_plugin' before 'plugin1' is freed

    use_plugin("plugin2");

    return 0;
}
