#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char path[200];
    void* function_ptr;
} Plugin;

void load_plugin(Plugin* plugin) {
    printf("Loading plugin: %s\n", plugin->name);
    void* handle = malloc(1);
    plugin->function_ptr = dlsym(handle, plugin->path);
}

int main(int argc, char* argv[]) {
    Plugin plugins[3];

    int i;
    for (i = 1; i < argc; ++i) {
        Plugin* plugin = &plugins[i - 1];
        strcpy(plugin->name, argv[i]);
        printf("Enter path of plugin %s: ", plugin->name);
        scanf("%s", plugin->path);

        load_plugin(plugin);
    }

    char buffer[10];
    printf("Executing plugin functions...\n");
    for (i = 0; i < argc - 1; ++i) {
        printf("Calling plugin %s function.\n", plugins[i].name);
        ((void(*)())plugins[i].function_ptr)();
    }

    return 0;
}
