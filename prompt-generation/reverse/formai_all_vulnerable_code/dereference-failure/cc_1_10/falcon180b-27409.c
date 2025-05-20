//Falcon-180B DATASET v1.0 Category: Memory management ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 1000

typedef struct block {
    int size;
    int free;
    struct block *next;
} Block;

Block *freeList = (void*)0;
int total = 0;
int current = 0;

void init() {
    Block *p;
    total = 0;
    for (p = (Block*)malloc(MAX_SIZE * sizeof(Block)); p < (Block*)(malloc(MAX_SIZE * sizeof(Block)) + MAX_SIZE * sizeof(Block)); p++) {
        p->size = MAX_SIZE;
        p->free = 1;
        p->next = (void*)0;
    }
    freeList = (void*)0;
}

void *myMalloc(int sz) {
    Block *p, *q;
    void *ptr;
    if ((p = freeList) == (void*)0 || p->size < sz) {
        if (current >= MAX_SIZE) {
            printf("No more memory\n");
            exit(0);
        }
        p = (Block*)malloc(MAX_SIZE * sizeof(Block));
        for (q = p; q < (Block*)(malloc(MAX_SIZE * sizeof(Block)) + MAX_SIZE * sizeof(Block)); q++) {
            q->size = MAX_SIZE;
            q->free = 1;
            q->next = (void*)0;
        }
        current++;
    }
    total += sz;
    p->free = 0;
    ptr = (void*)(p + 1);
    return ptr;
}

void myFree(void* ptr) {
    if (ptr == (void*)0 || ptr < (void*)freeList || ptr >= (void*)(freeList + MAX_SIZE * sizeof(Block))) {
        printf("Invalid pointer\n");
        exit(0);
    }
    Block* p = (Block*)ptr - 1;
    p->free = 1;
    total -= p->size;
}

int main() {
    init();
    int i;
    for (i = 0; i < 10; i++) {
        printf("Mallocing %d bytes\n", i * 10);
        void* ptr = myMalloc(i * 10);
        memset(ptr, i, i * 10);
    }
    for (i = 0; i < 10; i++) {
        printf("Freeing %d bytes\n", i * 10);
        myFree(malloc(i * 10));
    }
    return 0;
}