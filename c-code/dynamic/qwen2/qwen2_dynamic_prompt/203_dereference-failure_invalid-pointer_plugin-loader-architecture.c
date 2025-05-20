#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int (*func)();
} Plugin;

int malicious_function() {
    return 42;
}

Plugin load_plugin(const char* filename) {
    Plugin plugin;
    plugin.func = (int (*)())malloc(sizeof(int));
    if (!plugin.func) {
        exit(1);
    }
    // Simulate loading a function from a plugin
    *(int*)plugin.func = (int)malicious_function;
    return plugin;
}

void execute_plugin(Plugin plugin) {
    printf("Executing plugin...\n");
    int result = plugin.func();
    printf("Result: %d\n", result);
}

int main() {
    Plugin plugin = load_plugin("nonexistent_plugin.so");
    execute_plugin(plugin); // Dereference failure here
    free((void*)plugin.func);
    return 0;
}
