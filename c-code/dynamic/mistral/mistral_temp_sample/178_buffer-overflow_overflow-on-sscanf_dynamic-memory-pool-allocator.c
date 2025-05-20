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

Block* pool;
size_t pool_size = 0;

void allocate(size_t size) {
    if (pool_size == 0 || pool[pool_size - 1].size <= size) {
        pool_size++;
        pool = (Block*)realloc(pool, pool_size * sizeof(Block));
    }
    pool[pool_size - 1].size = size;
}

void* get_memory(size_t size) {
    if (pool_size == 0) {
        return NULL;
    }
    if (pool[0].size < size) {
        return NULL;
    }
    void* result = &pool[0].data;
    pool[0].size -= size;
    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    allocate(100);
    char* buffer = (char*)get_memory(200);

    if (!buffer) {
        printf("Out of memory\n");
        return 1;
    }

    sscanf(argv[1], "%s%s", buffer, buffer + 100);

    return 0;
}
