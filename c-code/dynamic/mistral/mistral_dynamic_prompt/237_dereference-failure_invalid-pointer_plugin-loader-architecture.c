#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef void (*load_func)(void);

int main() {
    void* plugin_handle;
    load_func load_plugin;

    plugin_handle = dlopen("non_existing_plugin.so", RTLD_NOW | RTLD_LOCAL);

    if (!plugin_handle) {
        fprintf(stderr, "Failed to load plugin: %s\n", dlerror());
        return 1;
    }

    load_plugin = dlsym(plugin_handle, "load_module");

    if ((load_plugin = (load_func)dlsym(plugin_handle, "load_module")) == NULL) {
        fprintf(stderr, "Failed to find load_module symbol in plugin: %s\n", dlerror());
        dlclose(plugin_handle);
        return 1;
    }

    load_plugin();

    dlclose(plugin_handle);
    return 0;
}
