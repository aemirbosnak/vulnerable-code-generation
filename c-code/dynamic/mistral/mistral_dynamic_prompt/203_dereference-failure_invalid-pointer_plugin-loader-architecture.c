#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* Plugin;

void load_plugin(const char* path) {
    Plugin plugin = malloc(atoi(path) * sizeof(Plugin));
    printf("Loading plugin at %p\n", plugin);
}

int main() {
    char** args = (char**) malloc(5 * sizeof(char*));
    args[0] = "./dummy_plugin";
    args[1] = NULL;

    for (int i = 2; i < 5; ++i) {
        args[i] = (char*) malloc(10 * sizeof(char));
        sprintf(args[i], "invalid_ptr%d", i);
    }

    load_plugin(args[2]);
    load_plugin(args[3]);
    load_plugin(args[4]);

    for (int i = 0; args[i]; ++i) {
        free(args[i]);
    }
    free(args);

    return 0;
}
