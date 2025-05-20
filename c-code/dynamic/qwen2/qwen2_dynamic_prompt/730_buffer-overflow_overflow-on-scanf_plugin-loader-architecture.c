#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_PATH "/path/to/plugins/"
#define MAX_PLUGIN_NAME 256

typedef void (*PluginFunction)(void);

void load_plugin(const char *plugin_name) {
    char full_path[MAX_PLUGIN_NAME];
    snprintf(full_path, sizeof(full_path), "%s%s", PLUGIN_PATH, plugin_name);
    
    FILE *file = fopen(full_path, "r");
    if (!file) {
        perror("Failed to open plugin file");
        return;
    }
    
    PluginFunction plugin_func = NULL;
    while (fscanf(file, "%p", &plugin_func) == 1) {
        printf("Loading plugin function: %p\n", plugin_func);
        plugin_func();
    }
    
    fclose(file);
}

int main() {
    char plugin_name[256];
    printf("Enter plugin name: ");
    scanf("%255s", plugin_name); // Vulnerability here
    
    load_plugin(plugin_name);
    
    return 0;
}
