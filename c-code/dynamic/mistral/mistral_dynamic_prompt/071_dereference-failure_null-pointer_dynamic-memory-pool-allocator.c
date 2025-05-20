#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    struct Block *next;
    char data[1];
} Block;

Block *head = NULL;

void allocate(size_t size) {
    if (size <= 0) {
        fprintf(stderr, "Invalid size.\n");
        return;
    }

    Block *new_block = (Block *)malloc(sizeof(Block) + size);
    if (!new_block) {
        fprintf(stderr, "Memory allocation failed.\n");
        return;
    }

    new_block->size = size;
    new_block->next = head;
    head = new_block;
}

void deallocate(Block *block) {
    if (!block || head == block) {
        fprintf(stderr, "Invalid block.\n");
        return;
    }

    if (head == block->next) {
        head = head->next;
    } else {
        Block *current = head;
        while (current->next != block) {
            current = current->next;
        }
        current->next = block->next;
    }

    free(block);
}

void *get_data(size_t index) {
    Block *current = head;
    while (current && index) {
        current = current->next;
        index--;
    }

    if (!current) {
        fprintf(stderr, "Out of bounds access.\n");
        return NULL;
    }

    return current->data;
}

int main() {
    allocate(5);
    allocate(10);
    char *data = get_data(3); // Dereference failure vulnerability
    *data = 'A';
    printf("Data: %c\n", *data);

    return 0;
}
