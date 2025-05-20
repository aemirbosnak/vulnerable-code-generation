#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void* alloc_mem(int size) {
    return malloc(size);
}

void free_mem(void* ptr) {
    free(ptr);
}

int main() {
    int size = 10;
    void* ptr = alloc_mem(size);
    free_mem(ptr);
    printf("Writing to the freed memory: %p\n", ptr);
    *(int*)ptr = 42;
    printf("Value stored in the freed memory: %d\n", *(int*)ptr);
    return 0;
}
