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

void allocate(size_t size) {
    Block *new_block = (Block *) malloc(sizeof(Block));
    new_block->size = size;
    new_block->data = (char *) malloc(size);
    new_block->next = head;
    head = new_block;
}

void free_pool() {
    Block *current = head;
    while (head != NULL) {
        current = head;
        head = head->next;
        free(current->data);
        free(current);
    }
    head = NULL;
}

void usage() {
    printf("Usage: ./mempool <number_of_bytes_to_allocate> <input_string>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage();
        return 1;
    }

    size_t size = atoi(argv[1]);
    allocate(size);

    gets(head->data); // Buffer overflow vulnerability

    printf("Input string: %s\n", head->data);

    free_pool();

    return 0;
}
