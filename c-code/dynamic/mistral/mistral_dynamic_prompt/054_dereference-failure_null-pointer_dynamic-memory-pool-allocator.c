#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Block {
    void *ptr;
    size_t size;
    struct Block *next;
} Block;

Block *head = NULL;

void allocate(size_t size) {
    Block *newBlock = malloc(sizeof(Block) + size);
    if (!newBlock) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newBlock->ptr = ((char *)newBlock + sizeof(Block));
    newBlock->size = size;
    newBlock->next = head;
    head = newBlock;
}

void* get_memory(size_t size) {
    Block *current = head;
    while (current && current->size < size) {
        current = current->next;
    }

    if (current && current->size >= size) {
        void *ptr = current->ptr;
        Block *temp = current;
        current->ptr = ((char *)current->ptr + current->size);
        temp->size -= size;
        return ptr;
    }

    return NULL;
}

int main() {
    allocate(100);
    allocate(200);
    allocate(300);

    char *a = (char *)get_memory(100);
    char *b = (char *)get_memory(200);
    char *c = (char *)get_memory(300);

    free(a); // Intentionally freeing memory allocated from another block

    printf("Attempting to access memory at address: %p\n", b);
    printf("Value: %c\n", *(char *)get_memory(1000)); // Accessing memory beyond allocated size

    return 0;
}
