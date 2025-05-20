#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef void (*load_func_t)(char*);

int main(int argc, char* argv[]) {
    void* handle;
    char* path;
    char* plugin;
    char* function;
    int size;

    if (argc < 4) {
        printf("Usage: %s <plugin_path> <plugin_name> <function_name>\n", argv[0]);
        return 1;
    }

    path = malloc(strlen(argv[1]) + 1);
    strcpy(path, argv[1]);

    plugin = malloc(strlen(argv[2]) + 1 + sizeof("_init.so") - 1);
    strcpy(plugin, argv[2]);
    strcat(plugin, "_init.so");

    handle = dlopen(path, RTLD_LAZY);
    if (!handle) {
        printf("Error: %s\n", dlerror());
        return 1;
    }

    function = malloc(strlen(argv[3]) + sizeof("load_") + strlen(argv[2]) + 1);
    sprintf(function, "load_%s", argv[3]);

    load_func_t load_func = (load_func_t)dlsym(handle, function);
    if ((size = (int)strlen(argv[3])) > 1000) { // Integer overflow
        size = 1000;
    }
    load_func(argv[3]);

    free(path);
    free(plugin);
    free(function);
    dlclose(handle);

    return 0;
}
