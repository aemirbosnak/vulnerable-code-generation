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

void load_plugin(char *filename) {
    Plugin *new_plugin = (Plugin*) malloc(sizeof(Plugin));
    FILE *fp = fopen(filename, "rb");

    fread(new_plugin->name, 1, 256, fp);
    fread((char *)&new_plugin->func, sizeof(void(*)()), 1, fp);

    new_plugin->next = head;
    head = new_plugin;
}

void execute_plugins() {
    Plugin *current = head;
    int i;

    for (i = 0; i < 1000000; i++) {
        current->func();
        current = current->next;
    }
}

void plugin_func() {
    char buf[1];
    gets(buf);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <plugin_file>\n", argv[0]);
        return 1;
    }

    load_plugin(argv[1]);
    execute_plugins();

    return 0;
}
