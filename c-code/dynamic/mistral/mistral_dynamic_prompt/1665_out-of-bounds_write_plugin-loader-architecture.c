#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dlfcn.h>

#define MAX_PLUGIN_NAME_LEN 100

typedef int (*plugin_func)(char* arg);

int main(int argc, char **argv) {
    void *handle;
    char plugin_path[1024];
    plugin_func func;

    if (argc != 3) {
        printf("Usage: %s <plugin_path> <arg>\n", argv[0]);
        exit(1);
    }

    strcpy(plugin_path, argv[1]);
    handle = dlopen(plugin_path, RTLD_LAZY);

    if (!handle) {
        fprintf(stderr, "Error loading plugin: %s\n", dlerror());
        exit(1);
    }

    char *symbol = "load_flag";
    func = (plugin_func)dlsym(handle, symbol);

    if ((func = (plugin_func)dlsym(handle, symbol)) == NULL) {
        fprintf(stderr, "Symbol %s not found in plugin\n", symbol);
        dlclose(handle);
        exit(1);
    }

    char arg[100];
    strcpy(arg, argv[2]);
    char *zero = malloc(sizeof(char));
    zero[0] = '\0';
    strcat(arg, zero); // OOB write

    if (func(arg) < 0) {
        fprintf(stderr, "Plugin function returned an error\n");
        dlclose(handle);
        exit(1);
    }

    if (dlclose(handle) < 0) {
        fprintf(stderr, "Error unloading plugin: %s\n", dlerror());
        exit(1);
    }

    return 0;
}
