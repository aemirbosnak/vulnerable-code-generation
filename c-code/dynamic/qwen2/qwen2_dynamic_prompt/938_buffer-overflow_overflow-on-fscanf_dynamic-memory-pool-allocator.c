#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

char pool[POOL_SIZE];
int pool_index = 0;

void* allocate(int size) {
    if (pool_index + size > POOL_SIZE) return NULL;
    void* ptr = &pool[pool_index];
    pool_index += size;
    return ptr;
}

int main() {
    char buffer[10];
    printf("Enter data: ");
    fscanf(stdin, "%s", buffer);
    printf("Data read: %s\n", buffer);

    // Allocate memory from the pool
    char* allocated_memory = allocate(100);
    if (allocated_memory == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Overwrite the allocated memory with user input
    printf("Enter more data to overwrite allocated memory: ");
    fscanf(stdin, "%s", allocated_memory);

    return 0;
}
