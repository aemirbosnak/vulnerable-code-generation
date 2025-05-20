#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[256];
    void (*func)();
    struct Plugin* next;
} Plugin;

Plugin* plugins = NULL;

void load_plugin(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) return;

    Plugin* plugin = (Plugin*) malloc(sizeof(Plugin));
    fread(plugin, 1, sizeof(Plugin), fp);
    plugin->func = (void(*)()) plugin->func;
    plugin->next = plugins;
    plugins = plugin;
    fclose(fp);
}

void execute_plugins() {
    Plugin* current = plugins;
    while (current) {
        current->func();
        current = current->next;
    }
}

void plugin_func_1() {
    int* ptr = (int*) malloc(1);
    *ptr = 42;
    printf("Value: %d\n", *(ptr + 10));
    free(ptr);
}

void plugin_func_2() {
    char* str = malloc(1);
    strcpy(str, "Hello, World!");
    printf("%s\n", str + 5);
    free(str);
}

int main() {
    load_plugin("plugin_1.bin");
    load_plugin("plugin_2.bin");
    execute_plugins();
    return 0;
}
