#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef void (*function_t)(void);

int main() {
    void* handle;
    function_t function;
    char* error;

    handle = dlopen("./plugin.so", RTLD_NOW | RTLD_GLOBAL);

    if (!handle) {
        fputs (dlerror(), stderr);
        return 1;
    }

    function = (function_t)dlsym(handle, "my_function");

    if ((error = dlerror()) != NULL) {
        fputs (error, stderr);
        dlclose(handle);
        return 1;
    }

    (*function)(); // intentionally dereferencing uninitialized pointer

    if (dlclose(handle) != 0) {
        perror("dlclose");
        return 1;
    }

    return 0;
}

// plugin.so
#include <stdio.h>
void my_function() {
    printf("Plugin loaded successfully\n");
    char* uninitialized_pointer = 0;
    // Some plugin logic here
    printf("Accessing uninitialized memory: %c\n", *uninitialized_pointer);
}
