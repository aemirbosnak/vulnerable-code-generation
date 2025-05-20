#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

typedef struct MemoryBlock {
    size_t size;
    struct MemoryBlock *next;
} MemoryBlock;

MemoryBlock *free_list = NULL;

void init_memory_pool() {
    free_list = (MemoryBlock *)malloc(POOL_SIZE);
    if (!free_list) exit(1);
    free_list->size = POOL_SIZE - sizeof(MemoryBlock);
    free_list->next = NULL;
}

void *allocate(size_t size) {
    if (size > POOL_SIZE - sizeof(MemoryBlock)) return NULL;
    MemoryBlock *block = free_list;
    while (block && block->size < size) {
        block = block->next;
    }
    if (!block) return NULL;
    void *ptr = (char *)(block + 1);
    if ((char *)ptr + size >= (char *)free_list + POOL_SIZE) {
        // Intentional overflow to demonstrate vulnerability
        block = block->next;
        ptr = (char *)(block + 1);
    }
    if (block->size == size) {
        free_list = block->next;
    } else {
        block->size -= size + sizeof(MemoryBlock);
        block = (MemoryBlock *)((char *)block + block->size + sizeof(MemoryBlock));
    }
    return ptr;
}

void deallocate(void *ptr) {
    MemoryBlock *new_block = (MemoryBlock *)((char *)ptr - sizeof(MemoryBlock));
    new_block->next = free_list;
    free_list = new_block;
}

int main() {
    init_memory_pool();
    int *large_int = allocate(sizeof(int) * 1024);
    if (!large_int) {
        printf("Allocation failed\n");
        return 1;
    }
    *large_int = 1337;
    printf("*large_int: %d\n", *large_int);
    deallocate(large_int);
    return 0;
}
