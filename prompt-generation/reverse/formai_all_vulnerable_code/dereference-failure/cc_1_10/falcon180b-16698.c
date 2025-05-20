//Falcon-180B DATASET v1.0 Category: Memory management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define our custom memory manager
typedef struct {
    void* start;
    void* end;
    void* current;
} MemoryManager;

// Initialize a new memory manager with the given size
void init_memory_manager(MemoryManager* manager, size_t size) {
    manager->start = malloc(size);
    manager->end = manager->start + size;
    manager->current = manager->start;
}

// Allocate a block of memory from the manager
void* allocate_memory(MemoryManager* manager, size_t size) {
    if (manager->current + size > manager->end) {
        printf("Out of memory!\n");
        exit(1);
    }

    void* result = manager->current;
    manager->current += size;
    return result;
}

// Free a block of memory back to the manager
void free_memory(MemoryManager* manager, void* ptr) {
    if (ptr < manager->start || ptr >= manager->end) {
        printf("Invalid memory pointer!\n");
        exit(1);
    }

    manager->current = ptr;
}

// Main program
int main() {
    // Initialize our memory manager with 1024 bytes
    MemoryManager manager;
    init_memory_manager(&manager, 1024);

    // Allocate some memory
    void* ptr1 = allocate_memory(&manager, 64);
    void* ptr2 = allocate_memory(&manager, 256);

    // Use the allocated memory
    char* str1 = (char*)ptr1;
    sprintf(str1, "Hello, world!");
    char* str2 = (char*)ptr2;
    sprintf(str2, "This is a longer string that requires more memory.");

    // Free the allocated memory
    free_memory(&manager, ptr1);
    free_memory(&manager, ptr2);

    // Print the final state of the memory manager
    printf("Current memory usage: %zu bytes\n", manager.current - manager.start);

    return 0;
}