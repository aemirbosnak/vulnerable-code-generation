#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLUGINS 10

typedef struct {
    void (*func)();
} Plugin;

void load_plugins(Plugin *plugins, int num_plugins) {
    FILE *fp;
    char filename[256];
    void (*plugin_func)();

    for (int i = 0; i < num_plugins; i++) {
        snprintf(filename, sizeof(filename), "plugin%d.so", i);
        fp = fopen(filename, "r");
        if (!fp) {
            printf("Failed to open plugin %d\n", i);
            continue;
        }

        // Simulate loading plugin function address from file
        fread(&plugin_func, sizeof(plugin_func), 1, fp);
        fclose(fp);

        plugins[i].func = plugin_func;
    }
}

void run_plugins(Plugin *plugins, int num_plugins) {
    for (int i = 0; i < num_plugins; i++) {
        if (i >= MAX_PLUGINS) { // Dereference failure here: array bounds violated
            printf("Running out-of-bounds plugin %d\n", i);
        } else {
            plugins[i].func();
        }
    }
}

void plugin_0() {
    printf("Executing plugin 0\n");
}

void plugin_1() {
    printf("Executing plugin 1\n");
}

int main() {
    Plugin plugins[MAX_PLUGINS];
    plugins[0] = (Plugin){plugin_0};
    plugins[1] = (Plugin){plugin_1};

    load_plugins(plugins, MAX_PLUGINS + 2); // Load more plugins than allocated space
    run_plugins(plugins, MAX_PLUGINS + 2);

    return 0;
}
