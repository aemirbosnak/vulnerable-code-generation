#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef void (*load_plugin_func)(void);

int main() {
    void* handle;
    char* plugin_path = "./nonexistent_plugin.so";
    load_plugin_func load_plugin;

    handle = dlopen(plugin_path, RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    load_plugin = (load_plugin_func) dlsym(handle, "load_plugin_func");
    if ((load_plugin = (load_plugin_func) dlsym(handle, "load_plugin_func")) == NULL) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    load_plugin();

    dlclose(handle);
    return 0;
}
