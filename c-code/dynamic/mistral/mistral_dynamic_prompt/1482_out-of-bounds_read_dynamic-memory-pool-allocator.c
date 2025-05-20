#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POOL_SIZE 10000
typedef struct Block {
    void *ptr;
    size_t size;
    struct Block *next;
} Block;

Block *head = NULL;

Block *new_block(size_t size) {
    Block *new_block = (Block *) malloc(sizeof(Block));
    new_block->ptr = malloc(size);
    new_block->size = size;
    new_block->next = head;
    head = new_block;
    return new_block;
}

void *alloc(size_t size) {
    if (head == NULL) {
        return NULL;
    }

    Block *current = head;
    Block *previous = NULL;

    while (current != NULL && current->size < size) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        Block *to_allocate = current;
        if (current->next != NULL) {
            previous->next = current->next;
        } else {
            head = NULL;
        }

        to_allocate->next = head;
        head = to_allocate;

        return to_allocate->ptr;
    }

    return new_block(size);
}

int main() {
    char *vulnerable_data = (char *) alloc(100);

    memset(vulnerable_data, 'A', 100);
    printf("Reading out of bounds: %s\n", vulnerable_data + 100);

    // Free all blocks when done
    while (head != NULL) {
        Block *current = head;
        head = head->next;
        free(current->ptr);
        free(current);
    }

    return 0;
}
