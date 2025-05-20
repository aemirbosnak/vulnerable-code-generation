#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef void (*load_plugin)(void);

int main() {
    void* handle;
    char* path = "./plugin.so";

    handle = dlopen(path, RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    load_plugin plugin_func = (load_plugin)dlsym(handle, "load_function");
    if (!plugin_func) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    (*plugin_func)(); // Dereference error at this line if "load_function" doesn't initialize a valid pointer

    dlclose(handle);
    return 0;
}

// plugin.so contents:
void load_function() {
    int* null_pointer = NULL;
    *null_pointer = 42; // Uninitialized pointer leads to dereference failure
}
