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

    int num;
    printf("Enter a number: ");
    fscanf(stdin, "%d", &num); // Vulnerability here

    printf("You entered: %d\n", num);

    free(memory_pool);
    return 0;
}
