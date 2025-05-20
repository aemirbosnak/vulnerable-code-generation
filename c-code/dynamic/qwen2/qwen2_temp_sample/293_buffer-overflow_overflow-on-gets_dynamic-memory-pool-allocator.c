#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

typedef struct {
    char data[POOL_SIZE];
    int used;
} MemoryPool;

MemoryPool *pool = NULL;

void init_pool() {
    pool = malloc(sizeof(MemoryPool));
    if (!pool) {
        printf("Failed to allocate memory pool\n");
        exit(1);
    }
    pool->used = 0;
}

void* my_malloc(int size) {
    if (size + pool->used > POOL_SIZE) {
        printf("Out of memory\n");
        return NULL;
    }
    void *ptr = &pool->data[pool->used];
    pool->used += size;
    return ptr;
}

void my_free(void *ptr) {
    // No freeing needed in this simplified version
}

int main() {
    init_pool();

    char *buf = (char *)my_malloc(900);
    if (buf) {
        strcpy(buf, "This is a buffer that will overflow the allocated space.");
        buf[1000] = 'X'; // Buffer overflow
        printf("%s\n", buf);
    }

    my_free(buf);

    free(pool);
    return 0;
}
