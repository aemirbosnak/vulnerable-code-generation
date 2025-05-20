//Falcon-180B DATASET v1.0 Category: Browser Plugin ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *name;
    int (*func)(void);
} plugin_t;

static int count_plugins = 0;
static plugin_t *plugins = NULL;

void register_plugin(char *name, int (*func)(void)) {
    plugin_t *new_plugin = malloc(sizeof(plugin_t));
    if (!new_plugin) {
        printf("Error: Out of memory\n");
        return;
    }
    new_plugin->name = strdup(name);
    new_plugin->func = func;
    plugins = realloc(plugins, sizeof(plugin_t) * ++count_plugins);
    plugins[count_plugins - 1] = *new_plugin;
}

void unregister_plugin(char *name) {
    int i;
    for (i = 0; i < count_plugins; i++) {
        if (!strcmp(plugins[i].name, name)) {
            free(plugins[i].name);
            plugins[i] = plugins[--count_plugins];
            break;
        }
    }
}

int call_plugins(void) {
    int i;
    for (i = 0; i < count_plugins; i++) {
        printf("Calling plugin '%s'\n", plugins[i].name);
        plugins[i].func();
    }
    return 0;
}

static void plugin_example(void) {
    printf("Hello, world!\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [register|unregister] [plugin_name]\n", argv[0]);
        return 1;
    }

    if (!strcmp(argv[1], "register")) {
        if (argc!= 3) {
            printf("Usage: %s register [plugin_name]\n", argv[0]);
            return 1;
        }
        register_plugin(argv[2], plugin_example);
        printf("Plugin '%s' registered successfully\n", argv[2]);
    } else if (!strcmp(argv[1], "unregister")) {
        if (argc!= 3) {
            printf("Usage: %s unregister [plugin_name]\n", argv[0]);
            return 1;
        }
        unregister_plugin(argv[2]);
        printf("Plugin '%s' unregistered successfully\n", argv[2]);
    } else {
        printf("Invalid command\n");
        return 1;
    }

    call_plugins();

    return 0;
}