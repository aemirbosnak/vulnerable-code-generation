//Falcon-180B DATASET v1.0 Category: Memory management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define MAX_ALLOCATIONS 1000
#define MAX_BLOCK_SIZE 1000

typedef struct block {
    size_t size;
    int free;
    struct block *next;
} Block;

Block *freeList = (void*)0;

void init() {
    freeList = (Block*)malloc(sizeof(Block));
    freeList->size = MAX_BLOCK_SIZE;
    freeList->free = true;
    freeList->next = (void*)0;
}

void *myMalloc(size_t numBytes) {
    Block *current = freeList;
    while (current!= NULL && current->size < numBytes) {
        current = current->next;
    }

    if (current == NULL) {
        fprintf(stderr, "Out of memory!\n");
        exit(1);
    }

    if (current->size == numBytes) {
        current->free = false;
        return (void*)(++current);
    } else if (current->size > numBytes + sizeof(Block)) {
        Block *newBlock = (void*)((void*)current + numBytes + sizeof(Block));
        newBlock->size = current->size - numBytes - sizeof(Block);
        newBlock->free = true;
        newBlock->next = current->next;
        current->size = numBytes;
        current->free = false;
        return (void*)(++current);
    }

    return NULL;
}

void myFree(void *ptr) {
    if (ptr == NULL) {
        return;
    }

    Block *block = (Block*)ptr;
    --block;

    block->free = true;
}

int main() {
    srand(time(NULL));

    init();

    int i;
    for (i = 0; i < MAX_ALLOCATIONS; ++i) {
        void *ptr = myMalloc(rand() % MAX_BLOCK_SIZE);
        if (ptr!= NULL) {
            memset(ptr, rand() % 256, rand() % MAX_BLOCK_SIZE);
        }
    }

    for (i = 0; i < MAX_ALLOCATIONS; ++i) {
        myFree(malloc(rand() % MAX_BLOCK_SIZE));
    }

    return 0;
}