//Falcon-180B DATASET v1.0 Category: Memory management ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 1000 // size of the heap

typedef struct block {
    size_t size; // size of the block
    int free; // flag indicating whether this block is available or not
    struct block *next; // pointer to the next block
} Block;

Block *freeList = (void*)0; // initialize free list to NULL
char heap[HEAP_SIZE]; // our heap

// Function to initialize our heap
void init() {
    freeList = (Block*)heap; // point to the start of the heap
    freeList->size = HEAP_SIZE - sizeof(Block);
    freeList->free = 1;
    freeList->next = (void*)0;
}

// Our malloc function
void *myMalloc(size_t numBytes) {
    Block *current, *prev;
    void *result;
    
    if (!(freeList->size)) { // if our freelist isn't initialized yet
        init();
    }
    
    current = freeList;
    while ((((current->size) < numBytes) || ((current->free) == 0)) && (current->next!= NULL)) {
        prev = current;
        current = current->next;
    }

    if ((current->size) == numBytes) {
        current->free = 0;
        result = (void*)(++current);
        return result;
    } else if ((current->size) > (numBytes + sizeof(Block))) {
        Block *newBlock = (void*)((void*)current + numBytes + sizeof(Block));
        newBlock->size = (current->size) - numBytes - sizeof(Block);
        newBlock->free = 1;
        newBlock->next = current->next;
        current->size = numBytes;
        current->free = 0;
        current->next = newBlock;
        result = (void*)(++current);
        return result;
    }
    return NULL;
}

// Our free function
void myFree(void* ptr) {
    if (((void*)heap <= ptr) && (ptr <= (void*)(heap + HEAP_SIZE))) {
        Block* blk = (Block*)ptr;
        --blk;
        blk->free = 1;
    }
}

int main() {
    void* ptr1 = myMalloc(10);
    void* ptr2 = myMalloc(20);
    void* ptr3 = myMalloc(30);

    printf("Size of block 1: %zu\n", myMalloc(0));
    printf("Size of block 2: %zu\n", myMalloc(0));
    printf("Size of block 3: %zu\n", myMalloc(0));

    myFree(ptr1);
    myFree(ptr2);
    myFree(ptr3);

    return 0;
}