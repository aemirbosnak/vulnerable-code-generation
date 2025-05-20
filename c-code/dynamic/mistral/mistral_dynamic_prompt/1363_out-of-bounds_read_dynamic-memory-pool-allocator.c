#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    char data[1];
    struct Block *next;
} Block;

Block *head = NULL;

void free_block(Block *block) {
    if (block->next) free(block->next);
    free(block);
}

void print_block(Block *block) {
    printf("Block size: %zu\n", block->size);
    char *data = (char *)block + sizeof(Block);
    size_t size = block->size - sizeof(Block);
    if (size) printf("Data: %.*s\n", (int)size, data);
}

void *allocate(size_t size) {
    Block *new_block = (Block *)malloc(sizeof(Block) + size);
    if (!new_block) return NULL;

    new_block->size = size + sizeof(Block);
    new_block->next = head;
    head = new_block;
    return (void *)((char *)new_block + sizeof(Block));
}

int main() {
    char input[100];

    printf("Enter a string to allocate:\n");
    fgets(input, 100, stdin);
    size_t size = strlen(input) + 1;
    void *data = allocate(size);
    if (!data) {
        fprintf(stderr, "Allocation failed.\n");
        return 1;
    }

    memcpy(data, input, size);

    printf("Allocated data:\n");
    print_block(head);

    free_block(head);
    head = NULL;

    return 0;
}
