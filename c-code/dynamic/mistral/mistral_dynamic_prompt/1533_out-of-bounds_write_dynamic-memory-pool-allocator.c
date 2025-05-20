#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 256

typedef struct Block {
    size_t size;
    char data[0];
} Block;

typedef struct Pool {
    Block* base;
    size_t count;
} Pool;

Pool* init_pool(size_t initial_blocks) {
    Pool* pool = (Pool*)malloc(sizeof(Pool));
    pool->base = (Block*)calloc(initial_blocks, sizeof(Block) + BUF_SIZE);
    pool->count = initial_blocks;
    return pool;
}

void* allocate(Pool* pool, size_t size) {
    Block* current = pool->base;
    size_t free_size;

    for (int i = 0; i < pool->count; i++) {
        free_size = sizeof(Block) + current->size;

        if (free_size >= size) {
            void* data = (void*)((char*)current + sizeof(Block));
            pool->base[i].size = size;
            return data;
        }
        current++;
    }

    return NULL;
}

int main() {
    Pool* pool = init_pool(10);

    char* my_data = (char*)allocate(pool, BUF_SIZE * 2);

    if (my_data) {
        for (size_t i = 0; i < BUF_SIZE * 2; i++) {
            my_data[i] = 'A' + (i % 26);
        }

        printf("First 100 characters of allocated memory:\n");
        for (size_t i = 0; i < 100; i++) {
            printf("%c", my_data[i]);
        }
        printf("\n");

        free(my_data);
    } else {
        printf("Failed to allocate memory.\n");
    }

    free(pool);

    return 0;
}
