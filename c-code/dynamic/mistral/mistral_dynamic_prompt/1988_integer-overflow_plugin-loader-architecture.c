#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Plugin {
    char name[64];
    void (*func)();
    size_t size;
} Plugin;

Plugin *load_plugin(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    Plugin *plugin = malloc(sizeof(Plugin));
    fread(plugin, 1, sizeof(Plugin), fp);
    fclose(fp);
    return plugin;
}

void do_plugin(Plugin *plugin) {
    ((void(*)())((char*)plugin + plugin->size - sizeof(void(*)())))(plugin);
}

int main() {
    Plugin *plugin = load_plugin("vuln_plugin.bin");
    do_plugin(plugin);
    free(plugin);
    return 0;
}

// vuln_plugin.c
void plugin_func(Plugin *plugin) {
    char buffer[10];
    scanf("%s", buffer);
    sprintf(buffer, "%s%s", buffer, plugin->name);
    printf("Hello from %s!\n", buffer);
}
