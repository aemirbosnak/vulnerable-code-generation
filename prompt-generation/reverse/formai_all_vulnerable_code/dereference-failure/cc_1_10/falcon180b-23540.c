//Falcon-180B DATASET v1.0 Category: Memory management ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCK_SIZE 1024 // maximum size of a block
#define NUM_BLOCKS 10 // number of blocks to allocate

typedef struct block {
    size_t size;
    char data[MAX_BLOCK_SIZE];
    struct block *next;
} Block;

Block *freeList = NULL; // initialize free list to NULL

void init() {
    Block *block = (Block *)malloc(sizeof(Block));
    if (block == NULL) {
        printf("Error: failed to allocate memory for free list\n");
        exit(1);
    }
    freeList = block;
    for (int i = 0; i < NUM_BLOCKS - 1; i++) {
        block->next = (Block *)malloc(sizeof(Block));
        if (block->next == NULL) {
            printf("Error: failed to allocate memory for block %d\n", i+1);
            exit(1);
        }
        block = block->next;
    }
    block->next = NULL;
}

void *myMalloc(size_t size) {
    Block *current = freeList;
    while (current!= NULL && current->size < size) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Error: block of size %d not available\n", size);
        return NULL;
    }
    void *result = &current->data[0];
    current->size = size;
    current->next = NULL;
    freeList = current->next;
    return result;
}

void myFree(void *ptr) {
    if (ptr == NULL) {
        printf("Error: attempting to free NULL pointer\n");
        return;
    }
    Block *block = (Block *)ptr;
    // merge with adjacent free blocks if possible
    Block *prev = NULL;
    Block *next = block->next;
    while (next!= NULL && next->size == MAX_BLOCK_SIZE) {
        block->size += next->size;
        block->next = next->next;
        free(next);
        next = block->next;
    }
    block->next = freeList;
    freeList = block;
}

int main() {
    init();
    void *ptr1 = myMalloc(100);
    void *ptr2 = myMalloc(200);
    void *ptr3 = myMalloc(300);
    printf("Allocated %d bytes at %p\n", 100, ptr1);
    printf("Allocated %d bytes at %p\n", 200, ptr2);
    printf("Allocated %d bytes at %p\n", 300, ptr3);
    myFree(ptr1);
    myFree(ptr2);
    myFree(ptr3);
    return 0;
}