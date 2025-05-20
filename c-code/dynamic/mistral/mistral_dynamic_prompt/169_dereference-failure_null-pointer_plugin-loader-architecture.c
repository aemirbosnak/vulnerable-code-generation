#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*function_ptr)(void);

struct plugin {
    char name[50];
    function_ptr func;
};

void plugin1_func(void) {
    printf("Plugin 1 function executed successfully.\n");
}

void plugin2_func(void) {
    printf("Plugin 2 function executed successfully.\n");
    int *null_ptr = NULL;
    *null_ptr = 42; // Null pointer dereference
}

int main() {
    struct plugin plugins[3] = {
        {"Plugin 1", plugin1_func},
        {"Plugin 2", plugin2_func}
    };

    for (int i = 0; i < 3; ++i) {
        if (plugins[i].func) {
            printf("Loading plugin %s...\n", plugins[i].name);
            plugins[i].func();
        } else {
            printf("Could not load plugin %s. Function is NULL.\n", plugins[i].name);
        }
    }

    return 0;
}
