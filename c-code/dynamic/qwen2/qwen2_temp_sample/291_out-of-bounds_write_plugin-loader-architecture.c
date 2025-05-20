#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLUGINS 10
typedef void (*PluginFunc)(void);

struct Plugin {
    char name[20];
    PluginFunc func;
};

struct PluginManager {
    struct Plugin plugins[MAX_PLUGINS];
    int count;
} pm;

void load_plugin(char *name, PluginFunc func) {
    if (pm.count >= MAX_PLUGINS) return;
    snprintf(pm.plugins[pm.count].name, sizeof(pm.plugins[pm.count].name), "%s", name);
    pm.plugins[pm.count].func = func;
    pm.count++;
}

void execute_plugins() {
    for (int i = 0; i < pm.count; i++) {
        pm.plugins[i].func();
    }
}

void bad_plugin(void) {
    // Example of an unsafe write operation
    *(int *)0xdeadbeef = 42;
}

int main() {
    load_plugin("bad_plugin", bad_plugin);
    execute_plugins();
    return 0;
}
