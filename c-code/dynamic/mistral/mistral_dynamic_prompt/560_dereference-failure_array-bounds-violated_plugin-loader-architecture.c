#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef int (*PluginFunc)(int arg);

int main() {
    void *handle;
    char *path = "./plugin.so";
    PluginFunc plugin_func;
    int arg = 42;

    handle = dlopen(path, RTLD_NOW | RTLD_LOCAL);

    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    plugin_func = dlsym(handle, "plugin_function");

    if ((plugin_func = (PluginFunc)dlsym(handle, "plugin_function")) == NULL) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    printf("Calling plugin function with argument: %d\n", arg);
    (*plugin_func)(arg + sizeof(int) * 10); // Vulnerability: Accessing memory beyond the allocated space

    dlclose(handle);
    return 0;
}

// In plugin.so file
int plugin_function(int arg) {
    int arr[arg];
    int i;
    for (i = 0; i < arg; ++i) {
        arr[i] = i * i;
    }
    return arr[arg]; // Accessing array out of bounds
}
