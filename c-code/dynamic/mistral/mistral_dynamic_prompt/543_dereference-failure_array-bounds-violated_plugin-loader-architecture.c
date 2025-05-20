#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dlfcn.h>

typedef void (*func_t)(void);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <plugin_path>\n", argv[0]);
        return 1;
    }

    void *handle = dlopen(argv[1], RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    char buffer[10];
    if (read(0, buffer, 10) <= 0) {
        fprintf(stderr, "Error reading from stdin\n");
        dlclose(handle);
        return 1;
    }

    func_t function = (func_t)strtoul(buffer, NULL, 10);
    function();

    dlclose(handle);
    return 0;
}
