#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pool {
    size_t capacity;
    size_t allocated;
    void *data;
} Pool;

Pool *create_pool(size_t capacity) {
    Pool *pool = (Pool *)malloc(sizeof(Pool));
    if (!pool) return NULL;
    pool->capacity = capacity;
    pool->allocated = 0;
    pool->data = malloc(capacity);
    if (!pool->data) {
        free(pool);
        return NULL;
    }
    return pool;
}

void destroy_pool(Pool *pool) {
    if (pool->data) free(pool->data);
    free(pool);
}

void *allocate(Pool *pool, size_t size) {
    if (pool->allocated + size > pool->capacity) return NULL;
    void *ptr = (void *)(pool->data + pool->allocated);
    pool->allocated += size;
    return ptr;
}

int main() {
    Pool *pool = create_pool(1024);
    char *buf = (char *)allocate(pool, 40);

    char input[16];
    if (sscanf(getenv("USER"), "%s%n", input, &input[16]) != 1) {
        fprintf(stderr, "Invalid USER environment variable.\n");
        return 1;
    }

    strcat(buf, input); // Intentionally writes past the end of the allocated buffer

    destroy_pool(pool);
    return 0;
}
