#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    size_t size;
    struct Block* next;
} Block;

Block* head = NULL;

void allocate(size_t size) {
    Block* newBlock = (Block*)malloc(sizeof(Block) + size);
    if (!newBlock) {
        fprintf(stderr, "Out of memory\n");
        return;
    }

    newBlock->size = size;
    newBlock->next = head;
    head = newBlock;
}

void* fetch(size_t size) {
    Block* current = head;
    while (current != NULL) {
        if (current->size >= size) {
            void* mem = (void*)((char*)current + sizeof(Block));
            if (current->size == size) {
                head = current->next;
                current->next = NULL;
            } else {
                current->size -= size;
                mem += current->size;
            }
            return mem;
        }
        current = current->next;
    }

    fprintf(stderr, "Out of available blocks\n");
    return NULL;
}

int main() {
    allocate(100);
    int* ptr1 = (int*)fetch(sizeof(int));
    *(ptr1) = 42;
    printf("Value at ptr1: %d\n", *(ptr1));

    allocate(200);
    int* ptr2 = (int*)fetch(sizeof(int));
    *(ptr2) = 24;
    printf("Value at ptr2: %d\n", *(ptr2));

    free(ptr1); // forgotten memory

    int* ptr3 = (int*)fetch(sizeof(int));
    *(ptr3) = 66;
    printf("Value at ptr3: %d\n", *(ptr3));

    return 0;
}
