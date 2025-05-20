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
    
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    unsigned char *buffer = malloc(file_size);
    if (!buffer) {
        perror("Failed to allocate memory for plugin");
        fclose(file);
        return;
    }
    
    fread(buffer, 1, file_size, file);
    fclose(file);
    
    PluginFunction plugin_func = (PluginFunction)buffer;
    plugin_func();
    
    free(buffer);
}

int main() {
    char plugin_name[256];
    printf("Enter plugin name: ");
    scanf("%s", plugin_name); // Vulnerability here
    
    load_plugin(plugin_name);
    
    return 0;
}
