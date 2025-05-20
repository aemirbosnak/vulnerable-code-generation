//Falcon-180B DATASET v1.0 Category: Memory management ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

// Define a struct for our memory block
typedef struct {
    size_t size; // Size of the block in bytes
    int id; // Unique identifier for the block
    char data[0]; // Variable length data
} MemoryBlock;

// Function to allocate a new memory block
MemoryBlock* allocate_memory(size_t size) {
    MemoryBlock* block = (MemoryBlock*)malloc(sizeof(MemoryBlock) + size);
    if (!block) {
        printf("Error: Out of memory!\n");
        exit(1);
    }
    block->size = size;
    block->id = rand(); // Assign a unique identifier
    return block;
}

// Function to free a memory block
void free_memory(MemoryBlock* block) {
    free(block);
}

// Function to print the contents of a memory block
void print_memory(MemoryBlock* block) {
    printf("ID: %d, Size: %zu bytes, Data:\n", block->id, block->size);
    for (int i = 0; i < block->size; i++) {
        printf("%02X ", ((unsigned char*)block->data)[i]);
        if (i % 16 == 15) {
            printf("\n");
        }
    }
    printf("\n");
}

// Main function
int main() {
    // Allocate some memory blocks
    MemoryBlock* block1 = allocate_memory(32);
    MemoryBlock* block2 = allocate_memory(64);
    MemoryBlock* block3 = allocate_memory(128);

    // Print the contents of the blocks
    print_memory(block1);
    print_memory(block2);
    print_memory(block3);

    // Free some memory blocks
    free_memory(block1);
    free_memory(block3);

    // Print the contents of the remaining block
    print_memory(block2);

    // Free the last memory block
    free_memory(block2);

    return 0;
}