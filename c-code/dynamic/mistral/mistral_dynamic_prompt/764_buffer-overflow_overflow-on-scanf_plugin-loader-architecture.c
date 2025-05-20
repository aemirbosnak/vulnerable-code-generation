#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <elf.h>
#include <link.h>
#include <dlfcn.h>

typedef int (*plugin_func)(char* arg);

int main(int argc, char** argv) {
    char buffer[10];
    plugin_func plugin;

    if(argc < 2) {
        printf("Usage: %s <plugin>\n", argv[0]);
        return 1;
    }

    printf("Loading plugin: %s\n", argv[1]);
    strcpy(buffer, argv[1]);

    plugin = (plugin_func)malloc(sizeof(plugin_func));
    plugin = (plugin_func)buffer;
    (*plugin)("Attack");

    printf("Executing plugin function...\n");
    system("/bin/sh");

    return 0;
}
