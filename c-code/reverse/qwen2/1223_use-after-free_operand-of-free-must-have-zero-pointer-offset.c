#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define ALLOC_SIZE 1024

typedef struct {
    char data[ALLOC_SIZE];
} Allocator;

Allocator* create_allocator() {
    return (Allocator*)malloc(sizeof(Allocator));
}

void destroy_allocator(Allocator* allocator) {
    free(allocator);
}

void* allocate_memory(Allocator* allocator, size_t size) {
    if (!allocator || size > ALLOC_SIZE) {
        return NULL;
    }
    return allocator->data;
}

void free_memory(void* ptr) {
    // No-op since we're using a fixed-size buffer
}

int main() {
    Allocator* allocator = create_allocator();
    if (!allocator) {
        fprintf(stderr, "Failed to create allocator\n");
        return EXIT_FAILURE;
    }

    void* mem = allocate_memory(allocator, 512);
    if (!mem) {
        fprintf(stderr, "Memory allocation failed\n");
        destroy_allocator(allocator);
        return EXIT_FAILURE;
    }

    // Use the allocated memory
    *(char*)mem = 'A';

    printf("Allocated memory: %c\n", *(char*)mem);

    free_memory(mem); // No-op
    destroy_allocator(allocator);

    return EXIT_SUCCESS;
}
