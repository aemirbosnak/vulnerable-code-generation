#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef void (*plugin_func)(void);

struct plugin {
    char name[32];
    unsigned int size;
    plugin_func func;
};

void load_plugin(struct plugin *plugins, int num_plugins) {
    char buf[256];
    int i;

    printf("Enter the name of the plugin to load: ");
    fgets(buf, sizeof(buf), stdin);

    for (i = 0; i < num_plugins; i++) {
        if (strncmp(buf, plugins[i].name, strlen(buf)) == 0) {
            ((void(*)())(plugins + i))();
            break;
        }
    }
}

void plugin1(void) {
    char buf[1024];
    printf("Plugin 1: Enter a command: ");
    fgets(buf, sizeof(buf), stdin);
    system(buf);
}

void plugin2(void) {
    char buf[1024];
    printf("Plugin 2: Enter a string: ");
    fread(buf, 1, sizeof(buf) - 1, stdin);
    printf("You entered: %s\n", buf);
}

int main() {
    struct plugin plugins[] = {
        {"plugin1", sizeof(plugin1), plugin1},
        {"plugin2", sizeof(plugin2), plugin2}
    };

    load_plugin(plugins, sizeof(plugins) / sizeof(plugins[0]));

    return 0;
}
