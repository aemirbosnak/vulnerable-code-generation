#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dlfcn.h>

typedef int (*PluginFunc)(void);

int main(int argc, char *argv[]) {
    void *pluginHandle;
    PluginFunc pluginFunction;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <plugin_path>\n", argv[0]);
        return 1;
    }

    pluginHandle = dlopen(argv[1], RTLD_NOW);
    if (!pluginHandle) {
        fprintf(stderr, "Failed to load plugin: %s\n", dlerror());
        return 1;
    }

    pluginFunction = (PluginFunc) dlsym(pluginHandle, "plugin_function");
    if ((pluginFunction = (PluginFunc)dlsym(pluginHandle, "plugin_function")) == NULL) {
        fprintf(stderr, "Error loading symbol plugin_function from plugin: %s\n", dlerror());
        dlclose(pluginHandle);
        return 1;
    }

    int result = pluginFunction();
    dlclose(pluginHandle);

    printf("Plugin returned: %d\n", result);
    return 0;
}

// Example plugin with forgotten memory
void *plugin_function(void) {
    int *my_array = malloc(10 * sizeof(int));
    *my_array = 42;

    for (int i = 0; i < 10; ++i) {
        printf("Array element %d: %d\n", i, my_array[i]);
    }

    return 0;
}
