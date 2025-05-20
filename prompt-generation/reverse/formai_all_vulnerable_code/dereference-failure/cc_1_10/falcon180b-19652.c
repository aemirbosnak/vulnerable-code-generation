//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    char *name;
    uint32_t size;
    uint32_t address;
    bool is_kernel;
} module_t;

module_t *modules = NULL;
uint32_t total_size = 0;
uint32_t kernel_size = 0;
uint32_t num_modules = 0;

uint32_t get_free_address(uint32_t start, uint32_t size) {
    uint32_t end = start + size;
    while (modules!= NULL && modules->address <= end) {
        start = modules->address + modules->size;
    }
    return start;
}

void add_module(char *name, uint32_t size, bool is_kernel) {
    module_t *new_module = malloc(sizeof(module_t));
    new_module->name = strdup(name);
    new_module->size = size;
    new_module->address = get_free_address(0, size);
    new_module->is_kernel = is_kernel;
    modules = realloc(modules, sizeof(module_t) * ++num_modules);
    modules[num_modules - 1] = *new_module;
    total_size += size;
    if (is_kernel) {
        kernel_size += size;
    }
}

void print_modules() {
    printf("Name\tSize\tAddress\tIs Kernel\n");
    for (int i = 0; i < num_modules; i++) {
        printf("%s\t%d\t0x%08X\t%s\n", modules[i].name, modules[i].size, modules[i].address, modules[i].is_kernel? "Yes" : "No");
    }
}

int main() {
    add_module("kernel.bin", 1024, true);
    add_module("driver1.bin", 512, false);
    add_module("driver2.bin", 256, false);
    print_modules();
    return 0;
}