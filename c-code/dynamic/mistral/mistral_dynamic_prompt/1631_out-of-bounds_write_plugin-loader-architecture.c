#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dlfcn.h>

#define PLUGIN_DIR "/tmp/plugins/"

typedef void (*load_func_t)(char* arg);

int main(int argc, char** argv) {
    char plugin_path[256];
    load_func_t load;

    if (argc < 2) {
        printf("Usage: %s <plugin_name>\n", argv[0]);
        return 1;
    }

    snprintf(plugin_path, sizeof(plugin_path), "%s%s.so", PLUGIN_DIR, argv[1]);

    void* handle = dlopen(plugin_path, RTLD_LAZY);
    if (!handle) {
        printf("Error: %s\n", dlerror());
        return 1;
    }

    load = (load_func_t)dlsym(handle, "load_function");
    if ((void*)load == NULL) {
        printf("Error: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    char* args = (char*)malloc(256 * sizeof(char));
    strcpy(args, "Oops, we're writing over the buffer!\n");

    load(args + 256); // write past the end of the allocated buffer

    free(args);
    dlclose(handle);

    return 0;
}
