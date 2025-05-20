#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    struct Block *next;
    char data[1];
} Block;

Block* head = NULL;
unsigned int num_allocs = 0;

Block* create_block(size_t size) {
    Block* new_block = (Block*) malloc(sizeof(Block) + size);
    new_block->next = head;
    head = new_block;
    num_allocs++;
    return new_block;
}

void free_block(Block* block) {
    if (block->next) {
        head = block->next;
    }
}

void* get_memory(size_t size) {
    if (size == 0) {
        fprintf(stderr, "Invalid size\n");
        return NULL;
    }

    Block* block = create_block(size);
    return (void*) (block + 1);
}

void print_pool() {
    printf("Memory Pool:\n");
    Block* current = head;
    while (current != NULL) {
        printf("Block %p of size %zu\n", current, (size_t) ((char*) current - (char*) head + sizeof(Block)));
        current = current->next;
    }
    printf("\n");
}

int main() {
    char* buffer1 = (char*) get_memory(20);
    strcpy(buffer1, "This is a test buffer");

    char* buffer2 = (char*) get_memory(10);
    strcpy(buffer2, "Another test buffer");

    free_block((Block*) buffer1);

    // Use buffer1 after it has been freed
    printf("Using freed buffer1: %s\n", buffer1);

    print_pool();

    return 0;
}
