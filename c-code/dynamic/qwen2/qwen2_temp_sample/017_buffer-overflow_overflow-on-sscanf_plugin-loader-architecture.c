#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLUGIN_NAME_LENGTH 10

typedef struct {
    char name[MAX_PLUGIN_NAME_LENGTH];
} Plugin;

void load_plugin(const char* plugin_name) {
    Plugin plugin;
    sscanf(plugin_name, "%s", plugin.name);
    printf("Loaded plugin: %s\n", plugin.name);
}

int main() {
    const char* malicious_plugin = "AAAAAAAAAAAA";
    load_plugin(malicious_plugin);
    return 0;
}
