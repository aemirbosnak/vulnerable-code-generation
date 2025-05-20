#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[100];
    void (*func)();
} Plugin;

Plugin* load_plugin(char* path) {
    FILE* fp = fopen(path, "r");
    Plugin plugin;
    fscanf(fp, "%s\n", plugin.name);
    fscanf(fp, "%*s %p\n", &plugin.func);
    return &plugin;
}

void run_plugin(Plugin* plugin) {
    (*plugin->func)();
}

void example_plugin_func() {
    char buffer[10];
    gets(buffer); // buffer overflow vulnerability here
    printf("You entered: %s\n", buffer);
}

int main() {
    Plugin* plugin = load_plugin("example_plugin.txt");
    run_plugin(plugin);
    return 0;
}

// example_plugin.txt content:
// PluginExample
// (void (*)())example_plugin_func
