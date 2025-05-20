#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char* func;
    int size;
} Plugin;

Plugin* load_plugin(const char* filename) {
    FILE* file = fopen(filename, "rb");
    Plugin* plugin = malloc(sizeof(Plugin));
    fread(plugin->name, sizeof(char), 20, file);
    plugin->func = malloc(plugin->size);
    fread(plugin->func, 1, plugin->size, file);
    fclose(file);
    return plugin;
}

void execute_plugin(Plugin* plugin) {
    ((void(*)()) plugin->func)();
}

void free_plugin(Plugin* plugin) {
    free(plugin->func);
    free(plugin);
}

int main() {
    Plugin* plugin = load_plugin("vulnerable_plugin.bin");
    execute_plugin(plugin);
    free_plugin(plugin);
    return 0;
}

// vulnerable_plugin.bin content:
char junk[100]; // arbitrary junk data
char secret_flag[] = "SECRET_FLAG"; // secret flag
char leak[8]; // to store address of secret_flag

void vulnerable_plugin() {
    memcpy(leak, &secret_flag, sizeof(leak));
    printf("Flag: %s\n", leak); // out of bounds read
}
