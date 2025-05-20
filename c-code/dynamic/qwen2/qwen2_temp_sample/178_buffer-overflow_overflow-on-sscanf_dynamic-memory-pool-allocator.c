#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

char *memory_pool;
int pool_index = 0;

void init_memory_pool() {
    memory_pool = (char *)malloc(POOL_SIZE);
    if (!memory_pool) {
        fprintf(stderr, "Failed to allocate memory pool\n");
        exit(1);
    }
}

void *allocate(int size) {
    if (pool_index + size > POOL_SIZE) {
        fprintf(stderr, "Memory pool exhausted\n");
        return NULL;
    }
    char *ptr = &memory_pool[pool_index];
    pool_index += size;
    return ptr;
}

void free_memory(void *ptr) {
    // No actual freeing needed as it's a simulated pool
}

void vulnerable_function(char *input) {
    int num;
    char buffer[16];
    sscanf(input, "%d %s", &num, buffer);
    printf("Number: %d, String: %s\n", num, buffer);
}

int main() {
    init_memory_pool();
    char input[32] = "12345678901234567890";
    vulnerable_function(input);
    free_memory(NULL); // Simulated free
    return 0;
}
