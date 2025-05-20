#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_BUFFER_SIZE 10

typedef struct {
    char name[20];
    void (*function)();
} Plugin;

void loadPlugin(Plugin *plugin, const char *buffer) {
    sscanf(buffer, "%s", plugin->name);
    plugin->function = NULL; // Simulate loading function pointer
}

void executePlugin(Plugin *plugin) {
    if (plugin->function != NULL) {
        plugin->function();
    }
}

int main() {
    Plugin plugins[PLUGIN_BUFFER_SIZE];
    char inputBuffer[100];

    printf("Enter plugin data: ");
    fgets(inputBuffer, sizeof(inputBuffer), stdin);

    int count = 0;
    while (count < PLUGIN_BUFFER_SIZE && inputBuffer[0] != '\n') {
        loadPlugin(&plugins[count], inputBuffer);
        count++;
        fgets(inputBuffer, sizeof(inputBuffer), stdin);
    }

    for (int i = 0; i < count; i++) {
        printf("Loading plugin: %s\n", plugins[i].name);
        executePlugin(&plugins[i]);
    }

    return 0;
}
