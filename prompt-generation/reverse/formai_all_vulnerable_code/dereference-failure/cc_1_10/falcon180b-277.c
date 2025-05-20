//Falcon-180B DATASET v1.0 Category: Memory management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEAP_SIZE 10000

typedef struct Block {
    size_t size;
    int free;
    struct Block *next;
} Block;

Block *freeList = (void*)0;
char heap[HEAP_SIZE];

void init() {
    freeList = (Block*)heap;
    freeList->size = HEAP_SIZE - sizeof(Block);
    freeList->free = 1;
    freeList->next = (void*)0;
}

void *myMalloc(size_t numBytes) {
    Block *current, *prev;
    void *result;

    current = freeList;
    while ((((current->size) < numBytes) || ((current->free) == 0)) && (current!= freeList)) {
        prev = current;
        current = current->next;
    }

    if (current->size == numBytes) {
        current->free = 0;
        result = (void*)(++current);
        return result;
    } else if (current->size > numBytes + sizeof(Block)) {
        Block *newBlock = (void*)((void*)current + numBytes + sizeof(Block));
        newBlock->size = current->size - numBytes - sizeof(Block);
        newBlock->free = 1;
        newBlock->next = current->next;
        current->size = numBytes;
        current->free = 0;
        current->next = newBlock;
        result = (void*)(++current);
        return result;
    }

    return (void*)0;
}

void myFree(void* ptr) {
    if (ptr!= (void*)0 && ptr!= (void*)(--freeList)) {
        Block* blk = (Block*)ptr;
        --blk;
        blk->free = 1;
    }
}

int main() {
    char* ptr1 = (char*)myMalloc(10);
    char* ptr2 = (char*)myMalloc(20);
    char* ptr3 = (char*)myMalloc(30);

    printf("ptr1: %p\n", ptr1);
    printf("ptr2: %p\n", ptr2);
    printf("ptr3: %p\n", ptr3);

    myFree(ptr1);
    myFree(ptr2);
    myFree(ptr3);

    return 0;
}