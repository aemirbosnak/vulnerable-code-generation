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

void* pool_allocate(size_t size) {
    static Block* pool = 0;
    static size_t total_size = 0;

    if (!pool) {
        pool = malloc(sizeof(Block) + sizeof(char) * 8192);
        total_size += sizeof(Block) + sizeof(char) * 8192;
    }

    Block* current = pool;
    while (current->size < size && (current - pool) * sizeof(Block) + current->size < total_size) {
        current++;
    }

    if ((current - pool) * sizeof(Block) + current->size == total_size) {
        printf("Not enough memory in pool.\n");
        return 0;
    }

    void* result = (void*)((char*)current + sizeof(Block));
    current->size = size;
    return result;
}

int main() {
    char* buffer = (char*)pool_allocate(1024);
    printf("Allocated buffer: %p\n", buffer);

    for (size_t i = 0; i < 1024; i++) {
        buffer[i] = 'A' + (i % 26);
    }

    // Out of bounds write
    buffer[1024] = 'Z';

    printf("Buffer content:\n");
    for (size_t i = 0; i < 1024; i++) {
        printf("%c ", buffer[i]);
    }

    return 0;
}
