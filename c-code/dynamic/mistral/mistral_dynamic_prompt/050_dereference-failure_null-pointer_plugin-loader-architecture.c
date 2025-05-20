#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef void (*plugin_init)(void);

int main() {
    void *handle = dlopen("nonexistent_plugin.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    plugin_init init_func = (plugin_init)dlsym(handle, "init_function");
    init_func();

    dlclose(handle);
    return 0;
}

// In a separate file (init_function.c):
void init_function() {
    char *message = malloc(10);
    printf("%s\n", message[10]); // Deliberate dereference failure
}
