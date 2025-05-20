#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* allocate(size_t size) {
    return malloc(size);
}

void free_protected(void* ptr, size_t partial_size) {
    if (partial_size > 0 && partial_size <= *(size_t*)ptr) {
        *(size_t*)ptr = partial_size;
    } else {
        fprintf(stderr, "Error: Invalid partial size\n");
    }
}

int main() {
    size_t size = 16;
    void* mem = allocate(sizeof(size_t) + size);
    if (!mem) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    *(size_t*)mem = size;

    // Use the allocated memory
    char* data = (char*)(mem + sizeof(size_t));
    for (size_t i = 0; i < size; i++) {
        data[i] = 'A' + (i % 26);
    }

    printf("Original data: %s\n", data);

    // Free only part of the memory
    free_protected(mem, size / 2);

    // Attempt to use freed memory
    printf("Data after partial free: %s\n", data + size / 2);

    free(mem);
    return 0;
}
