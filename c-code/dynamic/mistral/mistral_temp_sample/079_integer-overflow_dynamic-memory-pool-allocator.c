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

Block* pool = NULL;
size_t pool_size = 0;
size_t block_size = 128;

void grow_pool() {
    pool = realloc(pool, pool_size + block_size);
    pool_size += block_size;
}

Block* allocate(size_t size) {
    if (pool_size == 0) grow_pool();
    Block* block = &pool[pool_size - block_size];
    pool_size -= block_size;
    block->size = size;
    return block;
}

void deallocate(Block* block) {
    if (pool_size + block->size >= pool_size) grow_pool();
    memcpy(&pool[pool_size], block, block->size + sizeof(Block));
    pool_size += block->size + sizeof(Block);
}

int main() {
    Block* a = allocate(10);
    Block* b = allocate(200);
    Block* c = allocate(1000);
    deallocate(a);
    deallocate(b);
    deallocate(c);

    Block* d = allocate(1000000); // Integer overflow

    return 0;
}
