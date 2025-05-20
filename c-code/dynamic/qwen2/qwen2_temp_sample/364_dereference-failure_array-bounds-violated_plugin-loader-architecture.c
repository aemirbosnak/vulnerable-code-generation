#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_PLUGINS 10

typedef struct {
    int id;
    void (*function)();
} Plugin;

void load_plugins(Plugin plugins[], int num_plugins) {
    for (int i = 0; i <= num_plugins; i++) { // Off-by-one error here
        plugins[i].id = i;
        plugins[i].function = (void (*)())rand();
    }
}

void execute_plugin(Plugin *plugin) {
    if (plugin->function != NULL) {
        ((void (*)())plugin->function)();
    }
}

int main() {
    srand(time(NULL));
    Plugin plugins[MAX_PLUGINS];
    int num_plugins = 10;

    load_plugins(plugins, num_plugins);

    for (int i = 0; i <= num_plugins; i++) { // Off-by-one error here
        printf("Executing plugin %d\n", plugins[i].id);
        execute_plugin(&plugins[i]);
    }

    return 0;
}
