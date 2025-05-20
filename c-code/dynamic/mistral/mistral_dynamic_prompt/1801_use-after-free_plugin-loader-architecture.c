#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[100];
    void (*func)();
    struct Plugin* next;
} Plugin;

Plugin* plugins = NULL;

void load_plugin(Plugin* plugin) {
    plugin->next = plugins;
    plugins = plugin;
}

void run_plugins() {
    Plugin* current = plugins;
    while (current) {
        current->func();
        current = current->next;
    }
}

void PluginA_func() {
    printf("Plugin A is running...\n");
    free(plugins);
}

void PluginB_func() {
    printf("Plugin B is running...\n");
    plugins->next = NULL;
}

int main() {
    Plugin A = { "Plugin A", &PluginA_func, NULL };
    Plugin B = { "Plugin B", &PluginB_func, &A };
    Plugin C = { "Plugin C", NULL, &B };

    load_plugin(&A);
    load_plugin(&B);
    load_plugin(&C);

    run_plugins();

    return 0;
}
