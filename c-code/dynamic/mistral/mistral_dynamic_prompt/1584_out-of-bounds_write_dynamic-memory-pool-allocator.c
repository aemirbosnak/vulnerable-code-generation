#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MemoryBlock {
    size_t size;
    struct MemoryBlock *next;
} MemoryBlock;

MemoryBlock *head = NULL;

void allocate(size_t size) {
    MemoryBlock *newBlock = (MemoryBlock *) malloc(sizeof(MemoryBlock) + size);
    if (!newBlock) {
        printf("Out of memory.\n");
        return;
    }
    newBlock->size = size;
    newBlock->next = head;
    head = newBlock;
}

void* getMemory(size_t size) {
    MemoryBlock *current = head;
    while (current && current->size < size) {
        current = current->next;
    }
    if (!current) {
        printf("Insufficient memory.\n");
        return NULL;
    }
    void* memory = (void *)(current + 1);
    if (current->size < (size + sizeof(MemoryBlock))) {
        printf("Insufficient memory.\n");
        return NULL;
    }
    head = current->next;
    return memory;
}

int main() {
    int i;
    allocate(100);
    char *data = (char *)getMemory(50);
    for (i = 0; i < 50; ++i) {
        data[i] = 'a' + (i % 26);
    }
    for (i = 0; i < 50; ++i) {
        printf("%c", data[i]);
    }
    printf("\n");
    free(data);
    return 0;
}
