#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[256];
    void (*func)();
} Plugin;

void load_plugin(Plugin *plugin, char *filename) {
    FILE *file = fopen(filename, "r");
    fscanf(file, "%s %p", plugin->name, &plugin->func);
    fclose(file);
}

void vulnerable_function(char *input) {
    char buffer[10];
    sscanf(input, "%s", buffer);
    // Exploitable code here...
}

int main(int argc, char **argv) {
    Plugin plugin;
    load_plugin(&plugin, argv[1]);
    vulnerable_function(plugin.name);
    return 0;
}
