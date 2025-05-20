#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POOL_SIZE 4096
#define HEADER_SIZE 8
#define MAX_REQUEST 256

typedef struct Block {
    size_t size;
    char data[0];
} Block;

Block *pool;
size_t next_block = HEADER_SIZE;

void init_pool() {
    pool = (Block *) malloc(POOL_SIZE);
    pool[0].size = POOL_SIZE - HEADER_SIZE;
    next_block = HEADER_SIZE + POOL_SIZE - MAX_REQUEST;
}

Block* alloc(size_t size) {
    if (next_block < size) {
        printf("Error: Insufficient memory.\n");
        return NULL;
    }

    Block* block = (Block*)(pool + (next_block / sizeof(Block)));
    block->size = size;
    next_block -= size + HEADER_SIZE;

    return block;
}

void free_block(Block* block) {
    block->size = 0;
}

int main(int argc, char *argv[]) {
    init_pool();

    char input[10];
    printf("Enter the input: ");
    scanf("%s", input);

    // Vulnerable part of the code
    strcpy(input, argv[1]);

    // Rest of the program ...
    // (omitted for brevity)

    return 0;
}
