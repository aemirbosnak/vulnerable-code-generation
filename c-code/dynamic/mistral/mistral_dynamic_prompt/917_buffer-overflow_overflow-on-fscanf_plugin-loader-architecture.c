#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[10];
    void (*init)();
} Plugin;

void load_plugin(char *path) {
    FILE *file = fopen(path, "r");
    Plugin plugin;

    if (file) {
        fscanf(file, "%s", plugin.name);
        fscanf(file, "%*s %p\n", (void**)&plugin.init);
        fclose(file);
        printf("Loaded plugin: %s\n", plugin.name);
        plugin.init();
    } else {
        printf("Failed to load plugin: %s\n", path);
    }
}

void example_plugin_init() {
    setbuf(stdout, NULL);
    char buffer[1];
    printf("Executing plugin...\n");
    scanf("%s", buffer); // Buffer overflow vulnerability
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <plugin_path>\n", argv[0]);
        return 1;
    }

    load_plugin(argv[1]);
    return 0;
}
