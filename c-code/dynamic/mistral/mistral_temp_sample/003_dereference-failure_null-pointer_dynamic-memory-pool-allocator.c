#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    struct Block* next;
    char data[1];
} Block;

Block* head = NULL;

void allocate(size_t size) {
    Block* new_block = (Block*) malloc(sizeof(Block) + size);
    if (!new_block) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }

    new_block->size = size;
    new_block->next = head;
    head = new_block;
}

void* get_memory(size_t size) {
    Block* current = head;
    while (current && current->size < size) {
        current = current->next;
    }

    if (!current) {
        fprintf(stderr, "Not enough memory\n");
        exit(1);
    }

    void* memory = (void*) ((char*) current + sizeof(Block) + current->size);
    return memory;
}

int main() {
    allocate(10);
    allocate(5);

    char* vulnerable_pointer = (char*) get_memory(100);

    // Dereference failure vulnerability
    printf("%c\n", *vulnerable_pointer);

    return 0;
}
