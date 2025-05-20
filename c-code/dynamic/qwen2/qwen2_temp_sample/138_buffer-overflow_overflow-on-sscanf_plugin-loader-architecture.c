#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PLUGIN_NAME_LENGTH 256

typedef struct Plugin {
    char name[MAX_PLUGIN_NAME_LENGTH];
    void (*init)();
} Plugin;

void load_plugin(const char* path) {
    FILE* file = fopen(path, "r");
    if (!file) {
        perror("Failed to open plugin file");
        return;
    }

    Plugin plugin;
    if (fread(&plugin, sizeof(Plugin), 1, file) != 1) {
        perror("Failed to read plugin data");
        fclose(file);
        return;
    }

    // Vulnerability: Buffer overflow due to insufficient bounds checking on sscanf
    char buffer[32];
    if (sscanf(plugin.name, "%31s", buffer) != 1) {
        fprintf(stderr, "Failed to parse plugin name\n");
        fclose(file);
        return;
    }

    printf("Loaded plugin: %s\n", buffer);

    if (plugin.init) {
        plugin.init();
    }

    fclose(file);
}

int main() {
    const char* plugin_path = "malicious_plugin.bin";
    load_plugin(plugin_path);
    return 0;
}
