#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    void* function;
} Plugin;

Plugin* load_plugin(char* filename) {
    Plugin* plugin = malloc(sizeof(Plugin));
    FILE* file = fopen(filename, "r");
    fscanf(file, "%s %p", plugin->name, &plugin->function);
    fclose(file);
    return plugin;
}

void run_plugin(Plugin* plugin) {
    ((void(*)()) plugin->function)();
}

int main(int argc, char* argv[]) {
    Plugin* plugins[5];
    int i;

    for (i = 1; i < argc; i++) {
        plugins[i - 1] = load_plugin(argv[i]);
    }

    for (i = 0; i < argc - 1; i++) {
        run_plugin(plugins[i]);
    }

    for (i = 0; i < argc - 1; i++) {
        free(plugins[i]);
    }

    return 0;
}
