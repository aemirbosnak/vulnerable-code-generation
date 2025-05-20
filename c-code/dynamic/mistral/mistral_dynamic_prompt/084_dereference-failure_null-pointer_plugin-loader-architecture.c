#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef void (*PluginFunc)(void);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <plugin_file>\n", argv[0]);
        return 1;
    }

    void *plugin_handle = dlopen(argv[1], RTLD_LAZY);
    if (!plugin_handle) {
        fprintf(stderr, "Failed to load plugin: %s\n", dlerror());
        return 1;
    }

    PluginFunc plugin_func = (PluginFunc)dlsym(plugin_handle, "plugin_function");
    if ((plugin_func = (PluginFunc)dlsym(plugin_handle, "plugin_function")) == NULL) {
        fprintf(stderr, "Failed to find function 'plugin_function' in the plugin.\n");
        dlclose(plugin_handle);
        return 1;
    }

    plugin_func(); // Dereference null pointer, assumed that "plugin_function" returns a null pointer in malicious plugins

    dlclose(plugin_handle);
    return 0;
}
