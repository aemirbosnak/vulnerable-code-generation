#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct block {
    size_t size;
    char *data;
    struct block *next;
} Block;

Block *pool = NULL;

void allocate(size_t size) {
    Block *new_block = (Block *) malloc(sizeof(Block));
    if (!new_block) {
        fprintf(stderr, "Out of memory!\n");
        exit(1);
    }

    new_block->size = size;
    new_block->data = (char *) malloc(size);
    if (!new_block->data) {
        fprintf(stderr, "Out of memory!\n");
        free(new_block);
        exit(1);
    }

    new_block->next = pool;
    pool = new_block;
}

void *get_data(size_t index) {
    Block *current = pool;
    for (size_t i = 0; i < index && current != NULL; ++i)
        current = current->next;

    if (current == NULL) {
        fprintf(stderr, "Invalid index\n");
        return NULL;
    }

    return current->data;
}

int main() {
    allocate(100);
    char *str = (char *) get_data(0);

    printf("Enter a string to overflow:\n");
    gets(str);

    return 0;
}
