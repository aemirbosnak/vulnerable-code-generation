#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <elf.h>
#include <link.h>
#include <dlfcn.h>

#define PLUGIN_FILE "vulnerable_plugin.so"
#define BUFFER_SIZE 100

void load_plugin(const char *path) {
    void *handle = dlopen(path, RTLD_LAZY | RTLD_LOCAL);
    if (!handle) {
        fprintf(stderr, "Error: %s\n", dlerror());
        return;
    }

    char buffer[BUFFER_SIZE];
    gets(buffer); // intentionally vulnerable to buffer overflow

    // function pointer to plugin entry point
    void (*entry_point)(char *args);
    entry_point = dlsym(handle, "entry_point");
    if ((*entry_point))
        (*entry_point)(buffer);

    dlclose(handle);
}

int main(int argc, char *argv[]) {
    load_plugin(PLUGIN_FILE);
    return 0;
}

// In vulnerable_plugin.so
void entry_point(char *args) {
    write(STDOUT_FILENO, args, strlen(args));
}
