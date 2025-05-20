#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef void (*plugin_func_t)(void);

int main() {
    void* handle;
    char* path = "./non_existing_plugin.so";
    char* error;

    handle = dlopen(path, RTLD_LAZY | RTLD_LOCAL);
    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    plugin_func_t func = (plugin_func_t)dlsym(handle, "plugin_function");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "Error: %s\n", error);
        dlclose(handle);
        return 1;
    }

    func(); // Dereferencing an invalid pointer

    dlclose(handle);
    return 0;
}
