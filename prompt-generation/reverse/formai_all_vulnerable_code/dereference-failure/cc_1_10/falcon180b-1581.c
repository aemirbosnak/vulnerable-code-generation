//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEMORY_BLOCKS 100
#define MIN_BLOCK_SIZE 8

typedef struct memory_block {
    size_t size;
    void* address;
} memory_block_t;

memory_block_t* memory_blocks = NULL;
int num_memory_blocks = 0;

void init_memory() {
    memory_blocks = calloc(MAX_MEMORY_BLOCKS, sizeof(memory_block_t));
    num_memory_blocks = 0;
}

void* malloc(size_t size) {
    if (size <= 0) {
        return NULL;
    }

    void* address = NULL;
    memory_block_t* curr_block = memory_blocks;

    while (curr_block!= NULL && curr_block->size < size) {
        curr_block++;
    }

    if (curr_block == NULL) {
        if (num_memory_blocks >= MAX_MEMORY_BLOCKS) {
            return NULL;
        }

        curr_block = memory_blocks + num_memory_blocks;
        curr_block->size = size;
        curr_block->address = malloc(size);
        num_memory_blocks++;
    } else if (curr_block->size > size) {
        curr_block->size = size;
        address = curr_block->address;
    } else {
        curr_block++;
    }

    return address;
}

void free(void* address) {
    memory_block_t* curr_block = memory_blocks;

    while (curr_block!= NULL) {
        if (curr_block->address == address) {
            if (curr_block->size > MIN_BLOCK_SIZE) {
                curr_block->size = MIN_BLOCK_SIZE;
            } else {
                free(curr_block->address);
                curr_block->size = 0;
            }
            break;
        }

        curr_block++;
    }
}

int main() {
    init_memory();

    void* ptr1 = malloc(10);
    void* ptr2 = malloc(20);
    void* ptr3 = malloc(30);

    printf("Allocated 10 bytes at %p\n", ptr1);
    printf("Allocated 20 bytes at %p\n", ptr2);
    printf("Allocated 30 bytes at %p\n", ptr3);

    free(ptr1);
    free(ptr3);

    printf("Freed 10 bytes at %p\n", ptr1);
    printf("Freed 30 bytes at %p\n", ptr3);

    return 0;
}