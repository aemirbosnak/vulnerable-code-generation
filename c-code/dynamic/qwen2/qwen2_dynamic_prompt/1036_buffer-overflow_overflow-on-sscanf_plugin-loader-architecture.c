#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLUGIN_NAME_LENGTH 20

typedef struct {
    char name[MAX_PLUGIN_NAME_LENGTH];
} Plugin;

void load_plugin(const char* plugin_data) {
    Plugin plugin;
    if (sscanf(plugin_data, "%s", plugin.name) != 1) {
        fprintf(stderr, "Failed to parse plugin data\n");
        return;
    }
    printf("Loaded plugin: %s\n", plugin.name);
}

int main() {
    const char* malicious_input = "A very long string that will cause a buffer overflow";
    load_plugin(malicious_input);
    return 0;
}
