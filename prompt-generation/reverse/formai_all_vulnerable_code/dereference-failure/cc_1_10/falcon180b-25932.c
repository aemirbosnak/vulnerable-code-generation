//Falcon-180B DATASET v1.0 Category: Memory management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_SIZE 10000 // Size of the heap

typedef struct block {
    size_t size; // Size of the block
    int free; // Flag indicating whether this block is available or not
    struct block *next; // Pointer to the next block
} Block;

Block *freeList = (void*)0; // Initialize free list to NULL

// Function to initialize the heap
void init() {
    char *heap = (char*)malloc(HEAP_SIZE); // Allocate memory for the heap
    if (heap == NULL) {
        printf("Error: Unable to allocate memory for the heap.\n");
        exit(1);
    }
    freeList = (Block*)heap; // Set the free list to the beginning of the heap
    freeList->size = HEAP_SIZE - sizeof(Block);
    freeList->free = 1;
    freeList->next = NULL;
}

// Function to allocate a block of memory from the heap
void *myMalloc(size_t numBytes) {
    Block *curr = freeList;
    while ((curr->size < numBytes) && (curr->next!= NULL)) {
        curr = curr->next;
    }

    if (curr->size == numBytes) {
        curr->free = 0;
        return (void*)(++curr);
    } else if (curr->size > numBytes) {
        Block *newBlock = (void*)((void*)curr + numBytes + sizeof(Block));
        newBlock->size = curr->size - numBytes - sizeof(Block);
        newBlock->free = 1;
        newBlock->next = curr->next;
        curr->size = numBytes;
        curr->free = 0;
        curr->next = newBlock;
        return (void*)(++curr);
    }
    return NULL;
}

// Function to free a block of memory
void myFree(void* ptr) {
    if (ptr == NULL) {
        return;
    }

    Block* block = (Block*)ptr;
    --block;

    block->free = 1;
}

// Main function
int main() {
    init();

    int* num = (int*)myMalloc(sizeof(int));
    *num = 42;

    char* str = (char*)myMalloc(10);
    strcpy(str, "Hello");

    printf("Number: %d\n", *num);
    printf("String: %s\n", str);

    myFree(num);
    myFree(str);

    return 0;
}