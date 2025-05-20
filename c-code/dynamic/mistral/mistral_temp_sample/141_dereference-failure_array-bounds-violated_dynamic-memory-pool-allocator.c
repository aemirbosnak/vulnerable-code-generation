#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    char data[1];
} Block;

Block* pool = NULL;
size_t pool_size = 0;
size_t pool_capacity = 0;

void allocate(size_t size) {
    if (pool_size + size > pool_capacity) {
        pool_capacity *= 2;
        pool = realloc(pool, pool_capacity * sizeof(Block));
    }
    Block* block = &pool[pool_size];
    block->size = size;
    pool_size += size;
    return;
}

void* get_memory(size_t size) {
    allocate(size);
    return &pool[pool_size - size].data;
}

int main() {
    char* buffer = (char*)get_memory(10);
    strcpy(buffer, "This is a dangerous buffer.");
    printf("Buffer contents: %s\n", buffer);

    int* ptr = (int*)get_memory(sizeof(int));
    *ptr = 42;
    printf("Integer value: %d\n", *ptr);

    // Dereference out of bounds
    printf("Dereferencing out of bounds: %c\n", *(buffer + 11));

    return 0;
}
