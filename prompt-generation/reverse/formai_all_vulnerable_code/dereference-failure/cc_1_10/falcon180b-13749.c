//Falcon-180B DATASET v1.0 Category: Memory management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void *ptr;
    size_t size;
} Block;

Block *freeList = NULL;

void init() {
    freeList = (Block *)malloc(sizeof(Block));
    freeList->ptr = NULL;
    freeList->size = 0;
}

void *myMalloc(size_t size) {
    Block *curr = freeList;
    while (curr!= NULL && curr->size < size) {
        curr = curr->ptr;
    }

    if (curr == NULL) {
        curr = (Block *)malloc(sizeof(Block) + size);
        curr->ptr = NULL;
        curr->size = size;
    } else {
        Block *temp = (Block *)malloc(sizeof(Block) + size);
        temp->ptr = curr->ptr;
        curr->ptr = temp;
        curr->size += size;
    }

    return curr->ptr;
}

void myFree(void *ptr) {
    Block *curr = (Block *)ptr;
    curr--;

    while (curr->ptr!= NULL) {
        curr--;
    }

    curr->ptr = NULL;
    curr->size = 0;
}

int main() {
    init();

    int *a = myMalloc(sizeof(int));
    *a = 10;

    int *b = myMalloc(sizeof(int));
    *b = 20;

    int *c = myMalloc(sizeof(int));
    *c = 30;

    printf("%d %d %d\n", *a, *b, *c);

    myFree(a);
    myFree(b);
    myFree(c);

    return 0;
}