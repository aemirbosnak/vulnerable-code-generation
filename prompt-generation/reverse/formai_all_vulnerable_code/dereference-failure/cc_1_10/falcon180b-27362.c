//Falcon-180B DATASET v1.0 Category: Memory management ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define HEAP_SIZE 1000000 // 1 MB

typedef struct block {
    size_t size;
    int free;
    struct block *next;
} Block;

Block *freeList = (void*)0; // initialize free list to NULL
char heap[HEAP_SIZE]; // our heap

// Function to initialize our heap
void init() {
    freeList = (Block*)heap; // point to the start of the heap
    freeList->size = HEAP_SIZE - sizeof(Block);
    freeList->free = true;
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
    while ((((current->size) < numBytes) || ((current->free) == false)) && (current->next!= NULL)) {
        prev = current;
        current = current->next;
    }

    if ((current->size) == numBytes) {
        current->free = false;
        result = (void*)(++current);
        return result;
    } else if ((current->size) > (numBytes + sizeof(Block))) {
        Block *newBlock = (void*)((void*)current + numBytes + sizeof(Block));
        newBlock->size = (current->size) - numBytes - sizeof(Block);
        newBlock->free = true;
        newBlock->next = current->next;
        current->size = numBytes;
        current->free = false;
        current->next = newBlock;
        result = (void*)(++current);
        return result;
    }
    
    return NULL;
}

// Our free function
void myFree(void* ptr) {
    if ((void*)heap <= ptr) {
        if (ptr >= (void*)heap && ptr <= (void*)(heap + HEAP_SIZE)) {
            Block* blk = (Block*)ptr;
            --blk;
            blk->free = true;
        }
    }
}

int main() {
    int i;
    void *result;

    srand(time(NULL));

    for(i=0; i<10; i++) {
        result = myMalloc(rand() % 100);
        if(result!= NULL) {
            printf("Allocated %d bytes at %p\n", rand() % 100, result);
        }
    }

    for(i=0; i<10; i++) {
        myFree(result);
        result = myMalloc(rand() % 100);
        if(result!= NULL) {
            printf("Allocated %d bytes at %p\n", rand() % 100, result);
        }
    }

    return 0;
}