#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef void (*load_plugin_fn)(char* plugin_path);

int main() {
    load_plugin_fn load_plugin;
    char* plugin_path;

    // User input for plugin path
    scanf("%s", &plugin_path);

    void* plugin_handle = dlopen(plugin_path, RTLD_LAZY);

    if (!plugin_handle) {
        printf("Error: %s\n", dlerror());
        free(plugin_path);
        return 1;
    }

    load_plugin = (load_plugin_fn)dlsym(plugin_handle, "load_plugin_func");
    load_plugin(plugin_path); // UAF example: reusing 'plugin_path'

    dlclose(plugin_handle);
    free(plugin_path);
    return 0;
}

// Sample plugin
void load_plugin_func(char* plugin_path) {
    printf("Loaded plugin: %s\n", plugin_path);
    // Plugin code here
    free(plugin_path); // UAF: memory is still being used by main()
}
