#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_PATH "plugin.so"

typedef void (*PluginFunction)(void);

int main() {
    FILE *file = fopen(PLUGIN_PATH, "r");
    if (!file) {
        perror("Failed to open plugin file");
        return EXIT_FAILURE;
    }

    char buffer[10];
    PluginFunction plugin_func;

    // Vulnerability: No bounds checking on fscanf
    fscanf(file, "%s", buffer);
    fclose(file);

    // Assume buffer contains function pointer value
    *(void **)&plugin_func = (void *)strtoll(buffer, NULL, 16);

    // Execute the function from the loaded plugin
    plugin_func();

    return EXIT_SUCCESS;
}
