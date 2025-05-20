#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef int (*PluginFunction)(void);

int main() {
    void *handle;
    PluginFunction pluginFunc;

    handle = dlopen("nonexistent_plugin.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    pluginFunc = (PluginFunction) dlsym(handle, "plugin_function");
    if ((pluginFunc = (PluginFunction)dlsym(handle, "plugin_function")) == NULL) {
        fprintf(stderr, "Warning: Missing plugin function.\n");
    }

    pluginFunc(); // Dereference invalid pointer

    dlclose(handle);
    return 0;
}
