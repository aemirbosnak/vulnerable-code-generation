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

Block *pool;
size_t num_blocks;

void extend_pool(size_t size) {
    pool = realloc(pool, (num_blocks + size) * sizeof(Block));
}

Block* alloc_block(size_t size) {
    if (num_blocks == 0 || pool[num_blocks - 1].size == 0) {
        extend_pool(10);
    }

    Block* block = &pool[num_blocks++];
    block->size = size;
    return block;
}

void free_block(Block* block) {
    block->size = 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: ./allocator <file>\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    Block* buffer_block = alloc_block(256);
    char* buffer = (char*)buffer_block + sizeof(Block);

    size_t n;
    while (sscanf(fgets(buffer, 256, file), "%s%n", buffer, &n) == 1) {
        // Vulnerability: No bounds checking on 'n'
    }

    free_block(buffer_block);
    fclose(file);
    free(pool);
    return 0;
}
