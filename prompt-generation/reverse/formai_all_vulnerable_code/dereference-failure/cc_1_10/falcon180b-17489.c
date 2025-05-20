//Falcon-180B DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Block {
    size_t size;
    int free;
    struct Block *next;
} Block;

Block *freeList = (void*)0;

void init() {
    freeList = (Block*)malloc(sizeof(Block));
    freeList->size = 0;
    freeList->free = true;
    freeList->next = (void*)0;
}

void *myMalloc(size_t numBytes) {
    Block *current = freeList;
    while ((current->size < numBytes) ||!current->free) {
        current = current->next;
    }

    if (current->size == numBytes) {
        current->free = false;
        return (void*)(++current);
    } else {
        Block *newBlock = (void*)malloc(numBytes + sizeof(Block));
        newBlock->size = numBytes;
        newBlock->free = false;
        newBlock->next = current->next;
        current->next = newBlock;
        return (void*)(++newBlock);
    }
}

void myFree(void* ptr) {
    if (ptr == freeList) {
        return;
    }

    Block* current = (Block*)ptr;
    --current;

    if (!current->free) {
        current->free = true;
        return;
    }

    Block* next = current->next;
    while (next!= freeList && next->size == current->size &&!next->free) {
        next = next->next;
    }

    if (next!= freeList) {
        current->size += next->size + sizeof(Block);
        current->next = next->next;
        free(next);
    }
}

int main() {
    init();

    void* p1 = myMalloc(10);
    void* p2 = myMalloc(20);
    void* p3 = myMalloc(30);

    printf("p1: %p\n", p1);
    printf("p2: %p\n", p2);
    printf("p3: %p\n", p3);

    myFree(p1);
    myFree(p3);

    void* p4 = myMalloc(40);
    void* p5 = myMalloc(50);

    printf("p4: %p\n", p4);
    printf("p5: %p\n", p5);

    myFree(p2);
    myFree(p4);
    myFree(p5);

    return 0;
}