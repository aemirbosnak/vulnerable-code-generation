#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <dlfcn.h>

typedef void (*load_func)(char*);
typedef void (*unload_func)();

void load_plugin(char* path) {
    void* handle = dlopen(path, RTLD_NOW);

    if (!handle) {
        fprintf(stderr, "Failed to load plugin: %s\n", dlerror());
        return;
    }

    load_func load = (load_func)dlsym(handle, "load_function");
    unload_func unload = (unload_func)dlsym(handle, "unload_function");

    load(NULL); // Null pointer passed to function intentionally

    unload();
    dlclose(handle);
}

int main() {
    load_plugin("/path/to/nonexistent_plugin.so");

    return 0;
}
