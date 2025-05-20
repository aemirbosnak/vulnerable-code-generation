#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    struct Block* next;
    char data[1];
} Block;

Block* pool = NULL;

void allocate(size_t size) {
    Block* new_block = (Block*)malloc(sizeof(Block) + size);
    if (!new_block) {
        printf("Failed to allocate memory\n");
        return;
    }

    new_block->size = size;
    new_block->next = pool;
    pool = new_block;
}

void* acquire(size_t size) {
    Block* current = pool;

    while (current) {
        if (current->size >= size) {
            void* ptr = (char*)current + sizeof(Block);
            pool = current->next;
            return ptr;
        }
        current = current->next;
    }

    printf("Failed to find suitable block in the pool\n");
    return NULL;
}

int main() {
    int num_allocations = 10;

    for (int i = 0; i < num_allocations; ++i) {
        allocate(sizeof(int) * (i + 1));
    }

    int* arr = (int*)acquire(sizeof(int) * num_allocations);

    for (int i = 0; i < num_allocations; ++i) {
        arr[i] = i * 2;
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    printf("arr[%d] = %d\n", num_allocations, arr[num_allocations]); // Vulnerability: array index out of bounds

    return 0;
}
