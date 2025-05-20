#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

char *pool;
int pool_index;

void init_pool() {
    pool = malloc(POOL_SIZE);
    if (!pool) exit(1);
    pool_index = 0;
}

void *allocate(int size) {
    if (pool_index + size > POOL_SIZE) return NULL;
    char *ptr = &pool[pool_index];
    pool_index += size;
    return ptr;
}

int main() {
    init_pool();

    int *a = allocate(sizeof(int));
    *a = 42;

    int *b = allocate(sizeof(int) * 3);
    *b = 7;
    *(b+1) = 8;
    *(b+2) = 9;

    printf("a: %d\n", *a);
    printf("b: %d, %d, %d\n", *b, *(b+1), *(b+2));

    // Dereference failure (forgotten memory)
    int *c = allocate(sizeof(int) * 10); // This should fail silently
    printf("c: %d\n", *c); // Undefined behavior

    free(pool);

    return 0;
}
