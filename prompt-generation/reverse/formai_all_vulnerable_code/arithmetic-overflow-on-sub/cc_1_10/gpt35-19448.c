//FormAI DATASET v1.0 Category: Memory management ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 512 // Maximum memory size

struct Memory_Block {
    int start_address;
    int size;
    struct Memory_Block *next;
};

struct Memory_Block *memory_start = NULL; // Address of Start Block

void print_memory() {
    printf("--- MEMORY ---\n");
    struct Memory_Block *block = memory_start;
    while (block != NULL) {
        printf("start_address: %d | size: %d\n", block->start_address, block->size);
        block = block->next;
    }
    printf("---------------\n");
}

void allocate_memory(int size) {
    struct Memory_Block *block = memory_start;
    struct Memory_Block *last_block = NULL;
    while (block != NULL) {
        if (block->size >= size) {
            // Block found. Subtract allocated size from block
            block->size = block->size - size;

            // Create new block for allocated memory
            struct Memory_Block *allocated_block = (struct Memory_Block*)malloc(sizeof(struct Memory_Block));
            allocated_block->start_address = block->start_address + block->size;
            allocated_block->size = size;

            // Update last_block and next of allocated_block and block respectively
            if (last_block == NULL) {
                memory_start = allocated_block;
            } else {
                last_block->next = allocated_block;
            }
            allocated_block->next = block;

            printf("Memory allocated successfully.\n");
            return;
        } else {
            last_block = block;
            block = block->next;
        }
    }
    printf("Memory allocation failed.\n");
}

void free_memory(int start_address) {
    struct Memory_Block *block = memory_start;
    struct Memory_Block *last_block = NULL;
    while (block != NULL) {
        if (block->start_address == start_address) {
            // Block found. Remove it from memory and free it
            if (last_block == NULL) {
                memory_start = block->next;
            } else {
                last_block->next = block->next;
            }
            free(block);
            printf("Memory freed successfully.\n");
            return;
        } else {
            last_block = block;
            block = block->next;
        }
    }
    printf("Memory free failed. Block not found.\n");
}

int main() {
    int option, size, start_address;

    // Initialize memory with one block
    struct Memory_Block *initial_block = (struct Memory_Block*)malloc(sizeof(struct Memory_Block));
    initial_block->start_address = 0;
    initial_block->size = MEMORY_SIZE;
    initial_block->next = NULL;
    memory_start = initial_block;

    // Start of Retro Game
    printf("Welcome to Memory Allocation Game!\n\n");
    while (option != 3) {
        printf("1. Allocate Memory\n2. Free Memory\n3. Quit\n\nEnter option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("\nEnter size to allocate: ");
                scanf("%d", &size);
                allocate_memory(size);
                print_memory();
                break;
            case 2:
                printf("\nEnter start address to free: ");
                scanf("%d", &start_address);
                free_memory(start_address);
                print_memory();
                break;
            case 3:
                printf("\nEnd of game. Thanks for playing!\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
        }
    }

    return 0;
}