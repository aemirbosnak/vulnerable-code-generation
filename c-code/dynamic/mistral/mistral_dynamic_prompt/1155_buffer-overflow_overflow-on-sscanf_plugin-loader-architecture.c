#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[16];
    char path[128];
    void (*load)();
} Plugin;

void load_plugin(Plugin p) {
    p.load();
}

void evil_plugin_func() {
    char buf[8];
    char *ptr = (char*)(&buf + 8);

    printf("Loading plugin: %s\n", ptr);
    sscanf(ptr, "%s", (char *)&free);
    free(0);
}

int main() {
    Plugin plugin = {"evil_plugin", "./evil_plugin.so", evil_plugin_func};
    load_plugin(plugin);

    return 0;
}
