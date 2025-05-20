#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[100];
    void (*func)();
} Plugin;

Plugin* load_plugin(char* path) {
    FILE* file = fopen(path, "r");
    Plugin plugin;
    fscanf(file, "%s %p", plugin.name, &plugin.func);
    fclose(file);
    return &plugin;
}

void run_plugin(Plugin* plugin) {
    (*(plugin->func))();
}

int main(int argc, char* argv[]) {
    Plugin* plugin = load_plugin(argv[1]);
    run_plugin(plugin);

    char buffer[10];
    sscanf(argv[2], "%s", buffer);
    printf("User input: %s\n", buffer);

    return 0;
}
