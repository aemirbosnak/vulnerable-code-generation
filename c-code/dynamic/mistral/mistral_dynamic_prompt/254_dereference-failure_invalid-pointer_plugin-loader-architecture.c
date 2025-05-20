#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef int (*FunctionPointer)(void);

int main() {
    void *handle;
    char *error;
    FunctionPointer func;

    handle = dlopen("plugin.so", RTLD_NOW | RTLD_LOCAL | RTLD_GLOBAL);
    if (!handle) {
        fputs (dlerror(), stderr);
        exit(1);
    }

    func = (FunctionPointer) dlsym(handle, "secret_function");
    if ((error = dlerror()) != NULL) {
        fputs (error, stderr);
        dlclose(handle);
        exit(1);
    }

    // Intentionally misaligned pointer
    int *invalid_ptr = (int *) ((size_t)func + 1);
    int result = *invalid_ptr; // Dereference failure (invalid pointer)

    printf("Result: %d\n", result);

    dlclose(handle);
    return 0;
}

//plugin.so content (misaligned data in the function)
#include <stdio.h>

int secret_function() {
    int arr[4];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    return arr[0];
}
