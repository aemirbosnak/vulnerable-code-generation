#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 100
#define NUM_BLOCKS 1000

typedef struct Block {
    char data[BLOCK_SIZE];
    struct Block* next;
} Block;

Block* head = NULL;

void allocate_block(size_t size) {
    Block* new_block = (Block*) malloc(sizeof(Block) + size);
    if (!new_block) {
        printf("Out of memory\n");
        return;
    }

    new_block->next = head;
    head = new_block;
}

void free_memory() {
    Block* current = head;
    Block* next;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }

    head = NULL;
}

void usage() {
    printf("Usage: dynamic_mempool <number_of_strings_to_allocate>\n");
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        usage();
        return 1;
    }

    int num_strings = atoi(argv[1]);

    for (int i = 0; i < num_strings; i++) {
        allocate_block(1025);
        scanf("%s", ((Block*)head)->data);
    }

    free_memory();

    return 0;
}
