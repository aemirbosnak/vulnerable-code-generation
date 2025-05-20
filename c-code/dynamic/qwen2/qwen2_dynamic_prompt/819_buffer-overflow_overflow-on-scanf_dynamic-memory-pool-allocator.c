#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

char *memory_pool = NULL;
int pool_index = 0;

void init_memory_pool() {
    memory_pool = (char *)malloc(POOL_SIZE);
    if (!memory_pool) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
}

void *allocate_memory(int size) {
    if (pool_index + size > POOL_SIZE) {
        fprintf(stderr, "Out of memory\n");
        return NULL;
    }
    char *ptr = &memory_pool[pool_index];
    pool_index += size;
    return ptr;
}

int main() {
    init_memory_pool();

    int size;
    printf("Enter the size of the memory block to allocate: ");
    scanf("%d", &size);

    char *block = (char *)allocate_memory(size);
    if (!block) {
        return EXIT_FAILURE;
    }

    printf("Enter data into the allocated block:\n");
    scanf("%s", block); // Vulnerability here

    printf("Data stored in the block: %s\n", block);

    free(memory_pool);
    return EXIT_SUCCESS;
}
