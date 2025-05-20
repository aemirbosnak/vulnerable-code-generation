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

void load_plugin(const char* plugin_data) {
    Plugin plugin;
    if (sscanf(plugin_data, "%s", plugin.name) != 1) {
        printf("Failed to parse plugin data\n");
        return;
    }
    printf("Loaded plugin: %s\n", plugin.name);
}

int main() {
    const char* malicious_plugin_data = "AAAAAAAAAAAA";
    load_plugin(malicious_plugin_data);
    return 0;
}
