#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

char pool[POOL_SIZE];
int pool_index = 0;

void* my_malloc(size_t size) {
    if (pool_index + size > POOL_SIZE) {
        return NULL;
    }
    void* ptr = &pool[pool_index];
    pool_index += size;
    return ptr;
}

void my_free(void* ptr) {
    // No-op in this simple allocator
}

int main() {
    char* buffer = (char*)my_malloc(10);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter a string: ");
    fgets(buffer, 15, stdin); // Buffer overflow here

    printf("You entered: %s", buffer);

    my_free(buffer);

    return 0;
}
