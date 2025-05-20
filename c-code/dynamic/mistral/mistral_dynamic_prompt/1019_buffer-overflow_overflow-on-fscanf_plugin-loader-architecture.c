#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[20];
    void (*func)();
} Plugin;

void load_plugin(Plugin *plugin, char *path) {
    FILE *file = fopen(path, "r");
    if (!file) {
        perror("Error opening plugin file");
        return;
    }

    fscanf(file, "%s %*s %s\n", plugin->name, plugin->func);
    fclose(file);
}

void plugin_func() {
    printf("Executing plugin function\n");
}

int main() {
    Plugin plugin;
    char buf[10];
    char path[] = "/tmp/bad_plugin";

    load_plugin(&plugin, path);

    printf("Loaded plugin: %s\n", plugin.name);
    (*plugin.func)(); // Execute the loaded plugin function

    // Buffer overflow on fscanf in load_plugin function
    gets(buf); // DO NOT USE gets() in a real-world application!

    return 0;
}
