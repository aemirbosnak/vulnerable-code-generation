#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

typedef struct {
    void* start;
    size_t size;
} MemoryPool;

MemoryPool pool = {NULL, POOL_SIZE};

void init_pool() {
    pool.start = malloc(POOL_SIZE);
    if (!pool.start) {
        fprintf(stderr, "Failed to allocate memory pool\n");
        exit(EXIT_FAILURE);
    }
}

void* allocate(size_t size) {
    if (size > pool.size) {
        return NULL;
    }
    void* ptr = pool.start;
    pool.start = ((char*)pool.start) + size;
    pool.size -= size;
    return ptr;
}

void free_pool() {
    free(pool.start);
    pool.start = NULL;
    pool.size = POOL_SIZE;
}

int main() {
    init_pool();

    char buffer[20];
    int num;
    printf("Enter an integer: ");
    sscanf(buffer, "%d", &num);

    // Intentional buffer overflow vulnerability
    scanf("%99s", buffer);  // This line overflows the buffer by one byte

    printf("Buffer content: %s\n", buffer);

    free_pool();
    return 0;
}
