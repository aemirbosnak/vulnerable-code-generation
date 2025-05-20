//Falcon-180B DATASET v1.0 Category: Memory management ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BLOCK_SIZE 8

typedef struct block {
    size_t size;
    int free;
    struct block *next;
} block_t;

block_t *freeList = (void*)0;

void init() {
    char *heap = (char*)sbrk(0);
    freeList = (block_t*)heap;
    freeList->size = BLOCK_SIZE - sizeof(block_t);
    freeList->free = true;
    freeList->next = (void*)0;
}

void *malloc(size_t numBytes) {
    block_t *current, *prev;
    void *result;

    current = freeList;
    while ((((current->size) < numBytes) || ((current->free) == false)) && (current!= freeList)) {
        prev = current;
        current = current->next;
    }

    if (current->size == numBytes) {
        current->free = false;
        result = (void*)(++current);
        return result;
    } else if (current->size > numBytes + BLOCK_SIZE) {
        block_t *newBlock = (void*)((void*)current + numBytes + BLOCK_SIZE);
        newBlock->size = current->size - numBytes - BLOCK_SIZE;
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

void free(void* ptr) {
    if (ptr!= NULL) {
        block_t* blk = (block_t*)ptr;
        --blk;
        blk->free = true;
    }
}

int main() {
    init();

    int* p = (int*)malloc(sizeof(int));
    *p = 42;

    char* q = (char*)malloc(16);
    strcpy(q, "Hello, world!");

    free(p);
    free(q);

    return 0;
}