#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef void (*func_ptr)(void);

int main() {
    void* handle = dlopen("./plugin.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    func_ptr plugin_func = (func_ptr)dlsym(handle, "do_something");
    if ((void*)plugin_func == NULL) {
        fprintf(stderr, "%s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    plugin_func(); // Forgotten memory dereference vulnerability here

    dlclose(handle);
    return 0;
}

// plugin.c (part of plugin.so)
void do_something() {
    char* my_secret_data = malloc(10);
    // Some processing on 'my_secret_data'...
    free(my_secret_data);
}
