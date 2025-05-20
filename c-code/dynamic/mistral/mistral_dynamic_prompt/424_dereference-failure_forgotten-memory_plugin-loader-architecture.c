#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef void(*plugin_func)(void);

int main() {
    void* plugin_handle;
    plugin_func plugin_func_ptr;

    plugin_handle = dlopen("./plugins/evil_plugin.so", RTLD_NOW | RTLD_LOCAL);
    if (!plugin_handle) {
        printf("Error: Could not load plugin\n");
        return 1;
    }

    plugin_func_ptr = (plugin_func)dlsym(plugin_handle, "run_evil_code");
    if ((plugin_func_ptr) == NULL) {
        printf("Error: Function run_evil_code not found in plugin\n");
        dlclose(plugin_handle);
        return 1;
    }

    (*plugin_func_ptr)();

    dlclose(plugin_handle);
    return 0;
}

// In plugins/evil_plugin.c
void run_evil_code() {
    int* ptr = (int*)malloc(10 * sizeof(int));
    // some legitimate code here
    // ...
    // Forgotten memory dereference below
    printf("The value at address %p is %d\n", *(ptr + 200), *(ptr + 200));
}
