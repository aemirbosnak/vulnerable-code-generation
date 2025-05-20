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

Block* allocate(size_t size) {
    Block *new_block = (Block *)malloc(sizeof(Block) + size);
    if (!new_block) return NULL;

    new_block->size = size;
    new_block->next = head;
    head = new_block;

    return new_block->data;
}

void deallocate(void *ptr) {
    Block *current = head;
    Block *prev = NULL;

    while (current && current->data != ptr) {
        prev = current;
        current = current->next;
    }

    if (!current) return;

    if (prev) prev->next = current->next;
    else head = current->next;

    free(current);
}

void* find_prev(void *ptr) {
    Block *current = head;
    Block *prev = NULL;

    while (current && current->data != ptr) {
        prev = current;
        current = current->next;
    }

    return prev;
}

void free_complex(void *ptr) {
    Block *prev = find_prev(ptr);
    Block *next = prev->next->next;

    if (next) next->size += prev->size + sizeof(Block);

    free(prev);
}

int main() {
    char *a = allocate(10);
    char *b = allocate(20);
    char *c = allocate(30);

    free_complex(a); // Use-after-free vulnerability here

    return 0;
}
