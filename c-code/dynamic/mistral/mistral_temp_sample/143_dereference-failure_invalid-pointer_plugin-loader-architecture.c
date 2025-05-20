#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef void (*func_ptr)(void);

int main() {
    void* handle = dlopen("non_existing_plugin.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 1;
    }

    func_ptr func = (func_ptr)dlsym(handle, "dangerous_function");
    if ((void*)func == NULL) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    (*func)();
    dlclose(handle);
    return 0;
}

// In a separate file, let's create a shared object (plugin) with an invalid function pointer.
// Save this code in a file named dangerous_plugin.c
#include <stdio.h>
void dangerous_function() {
    int* null_ptr = NULL;
    *null_ptr = 42; // Dereference null pointer
}
