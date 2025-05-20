#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    char *data;
    struct Block *next;
} Block;

Block *head = NULL;

void alloc(size_t size) {
    Block *new_block = (Block *) malloc(sizeof(Block) + size);
    if (!new_block) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    new_block->size = size;
    new_block->data = (char *) ((char *) new_block + sizeof(Block));
    new_block->next = head;
    head = new_block;
}

void *get_data(size_t index) {
    Block *current = head;
    for (int i = 0; i < index && current != NULL; ++i) {
        current = current->next;
    }

    if (current == NULL) {
        fprintf(stderr, "Index out of range\n");
        return NULL;
    }

    return current->data;
}

int main() {
    int array_size = 10;
    alloc(array_size * sizeof(int));

    int *numbers = (int *) get_data(0);
    for (int i = 0; i < array_size; ++i) {
        numbers[i] = i * i;
    }

    // Use the array after the memory has been freed or overwritten
    int not_initialized = numbers[array_size];
    printf("Not initialized value: %d\n", not_initialized);

    return 0;
}
