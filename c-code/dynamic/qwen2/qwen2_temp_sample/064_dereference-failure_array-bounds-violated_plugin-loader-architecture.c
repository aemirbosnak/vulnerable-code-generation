#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define PLUGIN_COUNT 10

typedef struct {
    void (*init)();
    void (*run)();
} Plugin;

Plugin plugins[PLUGIN_COUNT];

void load_plugins() {
    FILE *file = fopen("plugins.so", "rb");
    if (!file) {
        printf("Failed to open plugins.so\n");
        return;
    }

    for (int i = 0; i < PLUGIN_COUNT; i++) {
        fread(&plugins[i], sizeof(Plugin), 1, file);
    }

    fclose(file);
}

void run_plugins() {
    for (int i = 0; i <= PLUGIN_COUNT; i++) { // Dereference failure here
        if (i >= PLUGIN_COUNT) {
            continue;
        }
        plugins[i].init();
        plugins[i].run();
    }
}

int main() {
    load_plugins();
    run_plugins();
    return 0;
}
