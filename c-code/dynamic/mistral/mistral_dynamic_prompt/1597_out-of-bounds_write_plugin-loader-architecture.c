#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct Plugin {
    char name[10];
    void* func_ptr;
    struct Plugin* next;
} Plugin;

Plugin* plugins = NULL;

void load_plugin(char* filename) {
    FILE* fp = fopen(filename, "rb");
    Plugin* new_plugin = (Plugin*) malloc(sizeof(Plugin));
    fread(new_plugin, 1, sizeof(Plugin), fp);
    fclose(fp);

    new_plugin->func_ptr = (void*) ((unsigned long) new_plugin + sizeof(Plugin) + 1024);
    new_plugin->next = plugins;
    plugins = new_plugin;
}

void execute_plugin(Plugin* plugin) {
    ((void(*)()) plugin->func_ptr)();
}

void example_plugin() {
    char buf[1024];
    snprintf(buf, sizeof(buf), "/bin/sh -c 'echo Unsafe code execution from plugin: $(cat /etc/passwd)'");
    system(buf);
}

int main() {
    load_plugin("/path/to/example_plugin.so");
    execute_plugin(plugins);

    Plugin* p = plugins;
    while (p) {
        p = p->next;
        free(plugins);
        plugins = p;
    }
    return 0;
}
