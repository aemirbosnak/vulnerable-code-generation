#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_BUFFER_SIZE 128

typedef struct {
    char buffer[PLUGIN_BUFFER_SIZE];
} Plugin;

int loadPlugin(const char* filename) {
    Plugin plugin;
    FILE* file = fopen(filename, "r");
    if (!file) return -1;

    fgets(plugin.buffer, sizeof(plugin.buffer), file);
    fclose(file);

    // Vulnerability: Buffer Overflow
    sscanf(plugin.buffer, "%*s %s", plugin.buffer);

    printf("Loaded plugin: %s\n", plugin.buffer);
    return 0;
}

int main() {
    const char* malicious_filename = "malicious_plugin.txt";
    if (loadPlugin(malicious_filename) != 0) {
        printf("Failed to load plugin.\n");
    }
    return 0;
}
