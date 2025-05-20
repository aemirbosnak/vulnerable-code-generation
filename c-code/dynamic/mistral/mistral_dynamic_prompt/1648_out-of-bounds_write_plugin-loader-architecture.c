#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[64];
    void (*func)();
    char data[0];
} Plugin;

void load_plugin(Plugin *plugin, char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Failed to open plugin: %s\n", filename);
        return;
    }

    fread(plugin, sizeof(Plugin) + sizeof(char), fseek(fp, 0, SEEK_END), fp);
    fclose(fp);

    plugin->func();
}

void evil_plugin_func() {
    char buf[256];
    gets(buf);

    // Out-of-bounds write vulnerability.
    // Assume sizeof(buf) < 64 bytes, leading to buffer overflow.
    strcpy(buf, "This plugin contains an out-of-bounds write vulnerability");
    printf("%s\n", buf);
}

int main(int argc, char **argv) {
    Plugin plugin;
    if (argc != 2) {
        printf("Usage: %s <plugin_file>\n", argv[0]);
        return 1;
    }

    load_plugin(&plugin, argv[1]);

    return 0;
}
