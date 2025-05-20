#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <dlfcn.h>

void (*plugin_function)();

int main() {
    void* handle = dlopen("nonexistent_plugin.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Cannot open library: %s\n", dlerror());
        return 1;
    }

    *(void**) (&plugin_function) = dlsym(handle, "nonexistent_function");
    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        fprintf(stderr, "%s\n", dlsym_error);
        dlclose(handle);
        return 1;
    }

    // Trigger out-of-bounds read
    int data[10];
    plugin_function(data);  // This will crash due to use-after-free

    dlclose(handle);
    return 0;
}
