//Falcon-180B DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *data;
    int size;
} MemoryBlock;

MemoryBlock *memoryPool = NULL;
int currentBlock = 0;
int totalMemory = 0;

void initMemoryPool() {
    memoryPool = (MemoryBlock *) malloc(sizeof(MemoryBlock) * MAX_SIZE);
    for (int i = 0; i < MAX_SIZE; i++) {
        memoryPool[i].data = NULL;
        memoryPool[i].size = 0;
    }
    totalMemory = 0;
    currentBlock = 0;
}

void *myMalloc(int size) {
    if (currentBlock == MAX_SIZE) {
        printf("Out of memory!\n");
        return NULL;
    }
    while (currentBlock < MAX_SIZE && memoryPool[currentBlock].size < size) {
        currentBlock++;
    }
    if (currentBlock == MAX_SIZE) {
        printf("Out of memory!\n");
        return NULL;
    }
    totalMemory += size;
    memoryPool[currentBlock].size = size;
    memoryPool[currentBlock].data = (char *) malloc(size);
    return memoryPool[currentBlock].data;
}

void myFree(void *ptr) {
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        if (memoryPool[i].data == ptr) {
            free(memoryPool[i].data);
            memoryPool[i].data = NULL;
            memoryPool[i].size = 0;
            totalMemory -= memoryPool[i].size;
            break;
        }
    }
}

int main() {
    initMemoryPool();
    char *str1 = myMalloc(10);
    char *str2 = myMalloc(20);
    char *str3 = myMalloc(30);
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