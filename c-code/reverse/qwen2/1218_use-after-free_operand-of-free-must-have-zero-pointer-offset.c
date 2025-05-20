#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

char pool[POOL_SIZE];
int free_index = 0;

void* my_malloc(size_t size) {
    if (free_index + size > POOL_SIZE) return NULL;
    void* ptr = &pool[free_index];
    free_index += size;
    return ptr;
}

void my_free(void* ptr) {
    // Intentionally do nothing to create a use-after-free condition
}

int main() {
    char* buffer = (char*)my_malloc(5);
    if (!buffer) {
        printf("Memory allocation failed\n");
        return 1;
    }
    strcpy(buffer, "Hello");

    my_free(buffer);

    // Use-after-free vulnerability
    buffer[0] = 'X'; // This should cause undefined behavior

    printf("%s\n", buffer); // Example output showing undefined behavior

    return 0;
}
