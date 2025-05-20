//Falcon-180B DATASET v1.0 Category: Memory management ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000
#define BLOCK_SIZE 100

typedef struct block {
    size_t size;
    int free;
    struct block *next;
} Block;

Block *freeList = (void*)0;

void init() {
    freeList = (Block*)malloc(sizeof(Block));
    freeList->size = MAX_SIZE - sizeof(Block);
    freeList->free = 1;
    freeList->next = (void*)0;
}

void *myMalloc(size_t size) {
    Block *current = freeList;
    while (current->size < size && current->next!= NULL) {
        current = current->next;
    }

    if (current->size == size) {
        current->free = 0;
        return (void*)(++current);
    } else if (current->size > size + sizeof(Block)) {
        Block *newBlock = (void*)((void*)current + size + sizeof(Block));
        newBlock->size = current->size - size - sizeof(Block);
        newBlock->free = 1;
        newBlock->next = current->next;
        current->size = size;
        current->free = 0;
        return (void*)(++current);
    }

    return NULL;
}

void myFree(void* ptr) {
    if (ptr!= NULL && ptr!= (void*)0) {
        Block* block = (Block*)ptr;
        --(block);
        block->free = 1;
    }
}

int main() {
    init();

    void* p1 = myMalloc(100);
    void* p2 = myMalloc(200);
    void* p3 = myMalloc(300);

    printf("Allocated %d bytes at %p\n", 100, p1);
    printf("Allocated %d bytes at %p\n", 200, p2);
    printf("Allocated %d bytes at %p\n", 300, p3);

    myFree(p1);
    myFree(p2);
    myFree(p3);

    return 0;
}