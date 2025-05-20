#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef void (*FuncPtr)(void);

int main(int argc, char *argv[]) {
    void *handle;
    FuncPtr pFunc;

    if (argc != 2) {
        printf("Usage: %s <plugin_path>\n", argv[0]);
        return 1;
    }

    handle = dlopen(argv[1], RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return 2;
    }

    pFunc = (FuncPtr) dlsym(handle, "load_data");
    if ((void *)pFunc == NULL) {
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(handle);
        return 3;
    }

    pFunc(); // Vulnerable line: dereferencing uninitialized pointer

    dlclose(handle);
    return 0;
}

// Sample plugin code (invalid pointer used)
#ifndef PLUGIN_H
#define PLUGIN_H

void load_data() {
    char *data = malloc(10); // Allocating 10 bytes of memory
    // Some logic here...
    int num = 5;
    data[num] = 'X'; // Dereferencing out of bounds (invalid pointer)
}

#endif
