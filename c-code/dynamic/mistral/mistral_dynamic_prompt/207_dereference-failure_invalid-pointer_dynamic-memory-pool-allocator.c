#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pool {
    void* buffer;
    size_t size;
    size_t capacity;
    size_t allocated;
    size_t index;
} Pool;

Pool* createPool(size_t size) {
    Pool* pool = (Pool*)malloc(sizeof(Pool));
    pool->buffer = malloc(size);
    pool->size = size;
    pool->capacity = size;
    pool->allocated = 0;
    pool->index = 0;
    return pool;
}

void* allocate(Pool* pool, size_t size) {
    if (pool->allocated + size > pool->capacity) {
        return NULL;
    }

    char* ptr = (char*)pool->buffer + pool->index;
    pool->index += size;
    pool->allocated += size;
    return ptr;
}

void deallocate(Pool* pool, void* pointer) {
    if (pool->index - ((char*)pool->buffer - (char*)pointer) < pool->allocated) {
        printf("Invalid pointer passed to deallocate.\n");
        return;
    }

    pool->allocated -= ((char*)pointer - (char*)pool->buffer + pool->index) / sizeof(char);
    pool->index = ((char*)pool->buffer - (char*)pointer);
}

int main() {
    Pool* pool = createPool(200);
    char* a = (char*)allocate(pool, 50);
    char* b = (char*)allocate(pool, 50);
    char* c = (char*)allocate(pool, 100);

    // Dereference failure here: invalid pointer access in the following line
    printf("%c\n", *c);

    deallocate(pool, a);
    deallocate(pool, b);

    return 0;
}
