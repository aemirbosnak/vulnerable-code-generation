#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Block {
    size_t size;
    char data[1];
} Block;

size_t get_block_size(const char *pool) {
    const Block *b = (const Block *)pool;
    return b->size;
}

void *get_next_block(const char *pool, size_t size) {
    const Block *b = (const Block *)pool;
    return (void *)((char *)b + b->size + sizeof(Block) + (size % 8));
}

void *allocate(void *pool, size_t size, size_t alignment) {
    if (!pool) return NULL;

    size_t block_size = get_block_size(pool);
    if (block_size < alignment) return NULL;

    void *new_pool = get_next_block(pool, alignment);
    if (!new_pool) return NULL;

    Block *new_block = (Block *)new_pool;
    new_block->size = size;
    return (void *)((char *)new_block + sizeof(Block));
}

int main(int argc, char *argv[]) {
    char *pool = malloc(sizeof(Block) + 50);
    if (!pool) return 1;

    Block *block = (Block *)pool;
    block->size = 50;

    char *data = allocate(pool, 51, 1);
    if (!data) return 1;

    memset(data, 'A', 51);
    printf("Data:\n%s\n", data);

    return 0;
}
