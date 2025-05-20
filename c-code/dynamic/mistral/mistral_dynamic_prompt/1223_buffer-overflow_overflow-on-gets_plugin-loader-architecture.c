#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct Plugin {
    char name[20];
    char (*func)();
    char buffer[1024];
} Plugin;

Plugin *plugins[5];
int num_plugins = 0;

void load_plugin(Plugin *plugin) {
    printf("Loading plugin: %s\n", plugin->name);
    plugins[num_plugins++] = plugin;
}

void run_plugins() {
    int i;
    for (i = 0; i < num_plugins; i++) {
        (plugins[i]->func)();
    }
}

Plugin create_plugin(char *name, char *func, char *data) {
    Plugin plugin;
    strcpy(plugin.name, name);
    plugin.func = (char (*)()) func;
    strcpy(plugin.buffer, data);
    return plugin;
}

int main() {
    Plugin malicious_plugin = create_plugin("evil", "system", "rm -rf / --no-preserve-root; /bin/sh");
    load_plugin(&malicious_plugin);
    run_plugins();

    Plugin valid_plugin = create_plugin("legit", NULL, "");
    gets(valid_plugin.buffer); // Vulnerable to buffer overflow
    load_plugin(&valid_plugin);
    run_plugins();

    return 0;
}
