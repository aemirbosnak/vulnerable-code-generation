#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 1024

typedef struct {
    int size;
    int free;
} Block;

Block *memory_pool = NULL;
int pool_size = 0;

void init_memory_pool(int size) {
    pool_size = size / BLOCK_SIZE + (size % BLOCK_SIZE != 0);
    memory_pool = (Block *)malloc(pool_size * sizeof(Block));
    for (int i = 0; i < pool_size; i++) {
        memory_pool[i].size = BLOCK_SIZE;
        memory_pool[i].free = 1;
    }
}

void *custom_malloc(int size) {
    if (memory_pool == NULL) return NULL;
    for (int i = 0; i < pool_size; i++) {
        if (memory_pool[i].free && memory_pool[i].size >= size) {
            memory_pool[i].free = 0;
            return (char *)(memory_pool + i) + sizeof(Block);
        }
    }
    return NULL;
}

void custom_free(void *ptr) {
    if (ptr == NULL) return;
    ptr = (char *)ptr - sizeof(Block);
    ((Block *)ptr)->free = 1;
}

int main() {
    init_memory_pool(8192);

    void *block1 = custom_malloc(512);
    void *block2 = custom_malloc(1024);
    void *block3 = custom_malloc(2048);

    printf("Allocated block1 at: %p\n", block1);
    printf("Allocated block2 at: %p\n", block2);
    printf("Allocated block3 at: %p\n", block3);

    custom_free(block2);
    custom_free(block1);
    custom_free(block3);

    // Potential use-after-free vulnerability
    printf("Trying to access freed block2: %d\n", *(int *)block2);

    return 0;
}
