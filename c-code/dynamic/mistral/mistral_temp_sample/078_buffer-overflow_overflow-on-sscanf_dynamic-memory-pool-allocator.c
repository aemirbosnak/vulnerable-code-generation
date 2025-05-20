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

void add_block(size_t size) {
    Block *new_block = (Block *)malloc(sizeof(Block));
    new_block->size = size;
    new_block->data = (char *)malloc(size);
    new_block->next = head;
    head = new_block;
}

void free_block(Block *block) {
    free(block->data);
    free(block);
}

void print_pool() {
    Block *current = head;
    printf("Memory Pool:\n");
    while (current != NULL) {
        printf("Size: %zu, Data: %s\n", current->size, current->data);
        current = current->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <size>\n", argv[0]);
        return 1;
    }

    add_block(atoi(argv[1]));

    char input[10];
    printf("Enter data to store in the allocated block (up to 10 characters): ");
    fgets(input, sizeof(input), stdin);

    sscanf(input, "%s%n", input, (size_t *)&(input[10]));

    print_pool();

    return 0;
}
