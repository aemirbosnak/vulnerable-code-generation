//Falcon-180B DATASET v1.0 Category: Memory management ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_MEMORY_BLOCK_SIZE 1024
#define MAX_MEMORY_BLOCK_SIZE 1048576
#define MIN_MEMORY_BLOCK_SIZE 64

typedef struct MemoryBlock {
    void *data;
    size_t size;
    struct MemoryBlock *next;
} MemoryBlock;

MemoryBlock *head = NULL;

void *myMalloc(size_t size) {
    void *result = NULL;
    MemoryBlock *current = head;

    while (current!= NULL) {
        if (current->size >= size) {
            result = current->data;
            current->size -= size;
            current->data = (char *)current->data + size;
            return result;
        }
        current = current->next;
    }

    if (size < MIN_MEMORY_BLOCK_SIZE) {
        size = MIN_MEMORY_BLOCK_SIZE;
    }

    if (head == NULL) {
        head = (MemoryBlock *)malloc(sizeof(MemoryBlock));
        head->data = (void *)malloc(size);
        head->size = size;
        head->next = NULL;
        result = head->data;
    } else {
        MemoryBlock *newBlock = (MemoryBlock *)malloc(sizeof(MemoryBlock));
        newBlock->data = (void *)malloc(size);
        newBlock->size = size;
        newBlock->next = head;
        head = newBlock;
        result = head->data;
    }

    return result;
}

void myFree(void *ptr) {
    if (ptr == NULL) {
        return;
    }

    MemoryBlock *current = head;
    while (current!= NULL) {
        if (current->data == ptr) {
            if (current->size > INITIAL_MEMORY_BLOCK_SIZE) {
                current->size = INITIAL_MEMORY_BLOCK_SIZE;
            }
            break;
        }
        current = current->next;
    }
}

int main() {
    int i;

    for (i = 0; i < 10; i++) {
        void *ptr = myMalloc(1024 * (i + 1));
        printf("Allocated %d bytes at %p\n", 1024 * (i + 1), ptr);
    }

    for (i = 9; i >= 0; i--) {
        myFree(head->data);
        printf("Freed %d bytes at %p\n", 1024 * (i + 1), head->data);
    }

    return 0;
}