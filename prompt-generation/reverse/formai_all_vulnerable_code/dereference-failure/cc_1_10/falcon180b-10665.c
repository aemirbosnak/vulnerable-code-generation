//Falcon-180B DATASET v1.0 Category: Memory management ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void* address;
    size_t size;
} MemoryBlock;

typedef struct {
    MemoryBlock* blocks;
    int count;
    int capacity;
} MemoryManager;

MemoryManager* createMemoryManager() {
    MemoryManager* manager = (MemoryManager*) malloc(sizeof(MemoryManager));
    manager->blocks = (MemoryBlock*) malloc(10 * sizeof(MemoryBlock));
    manager->count = 0;
    manager->capacity = 10;
    return manager;
}

void destroyMemoryManager(MemoryManager* manager) {
    free(manager->blocks);
    free(manager);
}

void* allocate(MemoryManager* manager, size_t size) {
    if (manager->count == manager->capacity) {
        printf("Memory manager is full, cannot allocate %zu bytes.\n", size);
        return NULL;
    }
    MemoryBlock* block = &manager->blocks[manager->count++];
    block->address = malloc(size);
    block->size = size;
    return block->address;
}

void deallocate(MemoryManager* manager, void* address) {
    for (int i = 0; i < manager->count; ++i) {
        if (manager->blocks[i].address == address) {
            free(manager->blocks[i].address);
            manager->blocks[i].address = NULL;
            manager->blocks[i].size = 0;
            manager->count--;
            return;
        }
    }
    printf("Address %p not found in memory manager.\n", address);
}

int main() {
    MemoryManager* manager = createMemoryManager();
    printf("Allocated memory manager with capacity %d.\n", manager->capacity);
    void* buffer1 = allocate(manager, 1024);
    printf("Allocated %zu bytes at address %p.\n", 1024, buffer1);
    void* buffer2 = allocate(manager, 512);
    printf("Allocated %zu bytes at address %p.\n", 512, buffer2);
    deallocate(manager, buffer1);
    printf("Deallocated %zu bytes at address %p.\n", 1024, buffer1);
    deallocate(manager, buffer2);
    printf("Deallocated %zu bytes at address %p.\n", 512, buffer2);
    destroyMemoryManager(manager);
    printf("Destroyed memory manager.\n");
    return 0;
}