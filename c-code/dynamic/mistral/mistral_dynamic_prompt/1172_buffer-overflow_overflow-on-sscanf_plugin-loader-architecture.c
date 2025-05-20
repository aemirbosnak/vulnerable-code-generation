#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLUGIN_MAGIC_NUM 0xDEADBEEF
#define BUFFER_SIZE 1024

typedef struct Plugin {
    unsigned int magic_num;
    char name[128];
    char (*init)(void);
} Plugin;

Plugin* load_plugin(const char* filename) {
    FILE* file = fopen(filename, "r");
    Plugin* plugin = malloc(sizeof(Plugin));
    fread(plugin, 1, sizeof(Plugin), file);
    fclose(file);
    return plugin;
}

void free_plugin(Plugin* plugin) {
    free(plugin);
}

void run_plugin(Plugin* plugin) {
    if (plugin->magic_num == PLUGIN_MAGIC_NUM) {
        plugin->init();
    } else {
        printf("Invalid plugin file\n");
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <plugin_file>\n", argv[0]);
        return 1;
    }

    Plugin* plugin = load_plugin(argv[1]);
    char buf[BUFFER_SIZE];
    printf("Enter command to execute in plugin: ");
    fgets(buf, BUFFER_SIZE, stdin);

    // Deliberate buffer overflow vulnerability starts here
    sscanf(buf, "%s", buf + 128);
    // Deliberate buffer overflow vulnerability ends here

    run_plugin(plugin);
    free_plugin(plugin);
    return 0;
}
