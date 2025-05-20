#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pool {
    char *buffer;
    size_t capacity;
    size_t position;
} Pool;

Pool* createPool(size_t size) {
    Pool *pool = (Pool *)malloc(sizeof(Pool));
    pool->buffer = malloc(size);
    pool->capacity = size;
    pool->position = 0;
    return pool;
}

void destroyPool(Pool *pool) {
    free(pool->buffer);
    free(pool);
}

char* allocate(Pool *pool, size_t length) {
    if (pool->position + length > pool->capacity) {
        fprintf(stderr, "Error: Insufficient space in the pool.\n");
        return NULL;
    }
    pool->position += length;
    return pool->buffer;
}

int main(int argc, char **argv) {
    Pool *pool = createPool(100);
    char input[10];

    while (1) {
        printf("Enter string (or type 'exit' to quit):\n");
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, "exit\n") == 0) {
            break;
        }

        size_t len = strlen(input);
        char *buffer = allocate(pool, len);
        if (!buffer) {
            fprintf(stderr, "Error: Pool is full.\n");
            continue;
        }

        strcpy(buffer, input);
    }

    destroyPool(pool);
    return 0;
}
