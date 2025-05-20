//Falcon-180B DATASET v1.0 Category: Memory management ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    void *data;
    size_t size;
} Block;

Block *freeList = (void*)0;

void init() {
    freeList = (Block*)malloc(sizeof(Block));
    freeList->data = (void*)0;
    freeList->size = 0;
}

void *myMalloc(size_t numBytes) {
    Block *current, *prev;
    void *result;

    current = freeList;
    while ((((current->size) < numBytes) || ((current->size) == 0)) && (current!= freeList)) {
        prev = current;
        current = current->data;
    }

    if ((current->size) == numBytes) {
        result = current->data;
        current->data = (void*)0;
        current->size = 0;
    } else if ((current->size) > (numBytes + sizeof(Block))) {
        Block *newBlock = (void*)((char*)current + numBytes + sizeof(Block));
        newBlock->data = (void*)( (char*)current + sizeof(Block) + numBytes );
        newBlock->size = (current->size) - numBytes - sizeof(Block);
        current->size = numBytes;
        result = current->data;
    } else {
        result = (void*)0;
    }

    return result;
}

void myFree(void* ptr) {
    if (ptr!= (void*)0) {
        Block* blk = (Block*)ptr;
        --blk->size;
        blk->data = (void*)0;
    }
}

int main() {
    char* str1 = (char*)myMalloc(10);
    char* str2 = (char*)myMalloc(20);
    char* str3 = (char*)myMalloc(30);

    strcpy(str1, "Hello");
    strcpy(str2, "World");
    strcpy(str3, "How are you?");

    printf("%s\n", str1);
    printf("%s\n", str2);
    printf("%s\n", str3);

    myFree(str1);
    myFree(str2);
    myFree(str3);

    return 0;
}