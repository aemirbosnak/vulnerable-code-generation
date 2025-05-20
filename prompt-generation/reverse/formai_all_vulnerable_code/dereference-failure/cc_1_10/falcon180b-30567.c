//Falcon-180B DATASET v1.0 Category: Memory management ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BLOCK_SIZE 1024
#define MAX_ALLOC_SIZE 1024 * 1024 * 10

typedef struct block {
    size_t size;
    int free;
    struct block *next;
} Block;

Block *freeList = (void *)0;

void init() {
    Block *block = (void *)malloc(MAX_BLOCK_SIZE);
    freeList = block;
    block->size = MAX_BLOCK_SIZE - sizeof(Block);
    block->free = 1;
    block->next = (void *)0;
}

void *myMalloc(size_t numBytes) {
    Block *current = freeList;
    while (current!= (void *)0 && current->size < numBytes)
        current = current->next;

    if (current == (void *)0) {
        Block *block = (void *)malloc(MAX_BLOCK_SIZE);
        if (block == (void *)0)
            return (void *)0;
        block->size = MAX_BLOCK_SIZE - sizeof(Block);
        block->free = 0;
        block->next = (void *)0;
        current = block;
    }

    void *result = (char *)current + sizeof(Block);
    current->size -= numBytes;
    current->free = 0;

    return result;
}

void myFree(void *ptr) {
    if (ptr == (void *)0)
        return;

    Block *block = (void *)ptr - sizeof(Block);
    block->free = 1;

    Block *current = freeList;
    while (current->next!= (void *)0 && current->next->size < block->size)
        current = current->next;

    block->next = current->next;
    current->next = block;
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
    myFree(ptr3);

    printf("Freed %d bytes at %p\n", 100, ptr1);
    printf("Freed %d bytes at %p\n", 300, ptr3);

    return 0;
}