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

void deallocate(void* ptr) {
    // No-op in this unsafe implementation
}

int main() {
    char* buffer = (char*)allocate(10);
    if (buffer == NULL) {
        printf("Allocation failed\n");
        return 1;
    }

    strcpy(buffer, "Hello, World!");
    printf("%s\n", buffer);

    // Buffer overflow vulnerability
    char* large_buffer = (char*)allocate(1024);
    if (large_buffer != NULL) {
        strcpy(large_buffer, "This will cause an overflow");
    }

    return 0;
}
