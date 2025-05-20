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
    if (free_index + size > POOL_SIZE) return NULL;
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
    int alloc_size = sizeof(buffer);
    void* allocated_ptr = allocate(alloc_size);
    if (allocated_ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Overwrite the allocated memory with user input
    strcpy((char*)allocated_ptr, buffer);

    printf("Allocated memory content: %s\n", (char*)allocated_ptr);

    return 0;
}
