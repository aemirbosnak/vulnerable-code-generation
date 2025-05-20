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

void allocate_memory(int size) {
    if (pool_index + size > POOL_SIZE) {
        fprintf(stderr, "Out of memory\n");
        return;
    }
    char *ptr = &memory_pool[pool_index];
    pool_index += size;
    printf("Allocated %d bytes at address %p\n", size, ptr);
}

void free_memory(char *ptr) {
    // Simulate freeing by setting pointer to null
    printf("Freed memory at address %p\n", ptr);
}

int main() {
    init_memory_pool();

    char buffer[10];
    printf("Enter a string: ");
    scanf("%s", buffer); // Vulnerability here

    printf("You entered: %s\n", buffer);

    allocate_memory(100);
    free_memory(buffer);

    free(memory_pool);
    return 0;
}
