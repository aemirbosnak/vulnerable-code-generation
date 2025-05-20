#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

typedef struct Pool {
    void* blocks[BUFFER_SIZE];
    int count;
} Pool;

void initPool(Pool* pool) {
    pool->count = 0;
}

void* allocate(Pool* pool, size_t size) {
    if (pool->count == BUFFER_SIZE) {
        fprintf(stderr, "Out of memory\n");
        return NULL;
    }

    void* mem = malloc(size);
    if (!mem) {
        fprintf(stderr, "Out of system memory\n");
        return NULL;
    }

    pool->blocks[pool->count] = mem;
    pool->count++;
    return mem;
}

void freeBlock(Pool* pool, void* block) {
    for (int i = 0; i < pool->count; ++i) {
        if (pool->blocks[i] == block) {
            pool->blocks[i] = NULL;
            pool->count--;
            break;
        }
    }
}

int main() {
    Pool memPool;
    initPool(&memPool);

    char* userInput;
    userInput = (char*)allocate(&memPool, 500);

    printf("Enter some input:\n");
    fgets(userInput, sizeof(userInput), stdin);

    // Intentionally vulnerable code - buffer overflow on gets function
    printf("Your input was: %s\n", userInput);

    freeBlock(&memPool, userInput);
    free(userInput);

    return 0;
}
