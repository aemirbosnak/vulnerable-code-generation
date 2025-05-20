#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_PATH "plugin.so"

typedef void (*PluginFunction)(void);

int main() {
    FILE *file = fopen(PLUGIN_PATH, "rb");
    if (!file) {
        perror("Failed to open plugin file");
        return EXIT_FAILURE;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = malloc(fileSize + 1);
    if (!buffer) {
        perror("Failed to allocate memory for plugin buffer");
        fclose(file);
        return EXIT_FAILURE;
    }

    size_t bytesRead = fread(buffer, 1, fileSize, file);
    if (bytesRead != fileSize) {
        perror("Failed to read plugin file");
        free(buffer);
        fclose(file);
        return EXIT_FAILURE;
    }
    buffer[fileSize] = '\0';

    PluginFunction pluginFunc = (PluginFunction)buffer;

    // Simulate an out-of-bounds read by accessing beyond the allocated buffer
    printf("Calling plugin function...\n");
    pluginFunc();

    free(buffer);
    fclose(file);
    return EXIT_SUCCESS;
}
