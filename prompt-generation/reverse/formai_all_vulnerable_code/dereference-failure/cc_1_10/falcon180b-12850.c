//Falcon-180B DATASET v1.0 Category: Memory management ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *name;
    int size;
    void *ptr;
} block_t;

block_t *freeList = (void *)0;

void init() {
    freeList = (block_t *)malloc(sizeof(block_t));
    freeList->name = "Free List";
    freeList->size = MAX_SIZE - sizeof(block_t);
    freeList->ptr = (void *)((int)freeList + sizeof(block_t));
}

void *myMalloc(int size) {
    block_t *current, *prev;
    void *ptr;

    current = freeList;
    while ((current->size < size) && (current!= freeList)) {
        prev = current;
        current = current->ptr;
    }

    if (current->size == size) {
        current->name = "Allocated Memory";
        current->ptr = (void *)((int)current + sizeof(block_t));
        return current->ptr;
    } else {
        printf("Memory not available\n");
        return NULL;
    }
}

void myFree(void *ptr) {
    block_t *current, *prev;

    if (ptr == NULL) {
        printf("Invalid pointer\n");
        return;
    }

    current = (block_t *)ptr;
    prev = freeList;

    while ((current!= freeList) && (current->ptr!= ptr)) {
        prev = current;
        current = current->ptr;
    }

    if (current == freeList) {
        printf("Pointer not found in the free list\n");
        return;
    }

    current->name = "Free List";
    current->size = MAX_SIZE - sizeof(block_t);
    current->ptr = (void *)((int)current + sizeof(block_t));
}

int main() {
    char *ptr1, *ptr2, *ptr3;

    init();

    ptr1 = (char *)myMalloc(50);
    if (ptr1!= NULL)
        printf("50 bytes allocated at %p\n", ptr1);

    ptr2 = (char *)myMalloc(100);
    if (ptr2!= NULL)
        printf("100 bytes allocated at %p\n", ptr2);

    ptr3 = (char *)myMalloc(150);
    if (ptr3!= NULL)
        printf("150 bytes allocated at %p\n", ptr3);

    myFree(ptr1);
    myFree(ptr2);
    myFree(ptr3);

    return 0;
}