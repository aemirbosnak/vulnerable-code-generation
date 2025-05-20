#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

typedef struct {
    char data[POOL_SIZE];
} MemoryPool;

MemoryPool* pool;
int next_free = 0;

void init_pool() {
    pool = (MemoryPool*)malloc(POOL_SIZE);
}

char* allocate(int size) {
    if (next_free + size > POOL_SIZE) return NULL;
    char* ptr = &pool[next_free].data;
    next_free += size;
    return ptr;
}

void free_pool() {
    free(pool);
}

int main() {
    init_pool();

    char* ptr = allocate(500);
    if (ptr == NULL) {
        printf("Allocation failed\n");
        free_pool();
        return 1;
    }

    // Intentional null pointer dereference vulnerability
    *ptr = 'X';

    printf("Value: %c\n", *ptr);

    free_pool();
    return 0;
}
