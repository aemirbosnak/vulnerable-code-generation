#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

typedef struct Plugin {
    char name[256];
    void (*func)();
} Plugin;

Plugin plugins[10];
int plugin_count = 0;

void load_plugin(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) return;

    Plugin new_plugin;
    fscanf(fp, "%s", new_plugin.name);
    fscanf(fp, "%*d"); // Ignore version number
    fscanf(fp, "(void)(){\n%*[^\n]\n}"); // Ignore plugin function implementation

    plugins[plugin_count++] = new_plugin;
    printf("Loaded plugin: %s\n", new_plugin.name);
}

void execute_plugins() {
    for (int i = 0; i < plugin_count; ++i) {
        (*(plugins[i].func))();
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <plugin_file1> [plugin_file2] ...\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; ++i) {
        load_plugin(argv[i]);
    }

    execute_plugins();

    return 0;
}
