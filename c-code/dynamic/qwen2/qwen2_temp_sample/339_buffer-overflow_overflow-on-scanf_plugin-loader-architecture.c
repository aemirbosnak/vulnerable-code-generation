#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef void (*PluginFunc)(void);

void load_plugin(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Failed to open file: %s\n", filename);
        return;
    }

    // Allocate memory for the plugin function pointer
    PluginFunc plugin_func = malloc(sizeof(PluginFunc));
    if (!plugin_func) {
        printf("Failed to allocate memory for plugin function\n");
        fclose(file);
        return;
    }

    // Read the plugin function address from the file
    fread(plugin_func, sizeof(PluginFunc), 1, file);

    // Close the file after reading
    fclose(file);

    // Call the plugin function
    (*plugin_func)();
}

int main() {
    char input[256];
    printf("Enter plugin filename: ");
    scanf("%s", input);  // Vulnerability here

    // Load the plugin
    load_plugin(input);

    return 0;
}
