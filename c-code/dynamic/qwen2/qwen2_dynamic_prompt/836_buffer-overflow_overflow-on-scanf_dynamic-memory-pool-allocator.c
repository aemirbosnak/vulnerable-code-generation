#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

char pool[POOL_SIZE];
int free_index = 0;

void* allocate(int size) {
    if (free_index + size > POOL_SIZE) {
        return NULL;
    }
    void* ptr = &pool[free_index];
    free_index += size;
    return ptr;
}

int main() {
    char buffer[10];
    printf("Enter data: ");
    scanf("%s", buffer);
    printf("Data entered: %s\n", buffer);

    // Allocate memory from the pool
    int size = sizeof(buffer);
    void* allocated_ptr = allocate(size);
    if (allocated_ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Copy data to allocated memory
    memcpy(allocated_ptr, buffer, size);

    // Overwrite allocated memory with user input
    printf("Enter more data to overwrite allocated memory: ");
    scanf("%s", (char*)allocated_ptr);

    printf("Overwritten data: %s\n", (char*)allocated_ptr);

    return 0;
}
