#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pool_tag {
    void *buffer;
    size_t capacity;
    size_t used;
} Pool;

Pool *pool_create(size_t size) {
    Pool *pool = malloc(sizeof(Pool));
    pool->capacity = size;
    pool->used = 0;
    pool->buffer = malloc(size);
    return pool;
}

void *pool_alloc(Pool *pool) {
    if (pool->used == pool->capacity) {
        fprintf(stderr, "Error: Pool is full\n");
        return NULL;
    }
    void *ptr = &((char *)pool->buffer)[pool->used];
    pool->used++;
    return ptr;
}

int main(int argc, char *argv[]) {
    Pool *pool = pool_create(1024);
    char *input;
    int i;

    printf("Dynamic Memory Pool Allocator\n");
    printf("Enter input (to exit type 'quit'):\n");

    for (i = 0; i < 20; i++) {
        input = pool_alloc(pool);
        if (input == NULL) break;
        gets(input);
        if (strcmp(input, "quit") == 0) break;
    }

    free(pool->buffer);
    free(pool);

    return 0;
}
