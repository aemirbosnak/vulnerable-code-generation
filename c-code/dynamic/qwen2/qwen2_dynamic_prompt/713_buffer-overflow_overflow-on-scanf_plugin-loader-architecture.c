#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_PATH "/path/to/plugins/"

typedef struct {
    char name[256];
    void (*execute)();
} Plugin;

void load_plugin(const char *plugin_name) {
    char path[1024];
    snprintf(path, sizeof(path), "%s%s", PLUGIN_PATH, plugin_name);
    
    FILE *file = fopen(path, "r");
    if (!file) {
        printf("Failed to open plugin: %s\n", plugin_name);
        return;
    }
    
    Plugin plugin;
    fscanf(file, "%255s", plugin.name);
    plugin.execute = NULL; // Simulate loading function pointer
    
    printf("Loaded plugin: %s\n", plugin.name);
    
    // Vulnerability: No bounds checking on user input
    char buffer[10];
    printf("Enter command for plugin: ");
    scanf("%9s", buffer); // Buffer overflow vulnerability
    
    // Simulate executing plugin command
    if (strcmp(buffer, "run") == 0) {
        plugin.execute();
    } else {
        printf("Invalid command\n");
    }
}

int main() {
    printf("Plugin Loader Architecture Example\n");
    printf("Enter plugin name to load: ");
    char plugin_name[256];
    scanf("%255s", plugin_name);
    
    load_plugin(plugin_name);
    
    return 0;
}
