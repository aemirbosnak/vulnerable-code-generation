#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

char mempool[POOL_SIZE];
int free_index = 0;

void* allocate(int size) {
    if (free_index + size > POOL_SIZE) return NULL;
    void* ptr = &mempool[free_index];
    free_index += size;
    return ptr;
}

void initialize_pool() {
    free_index = 0;
}

int main() {
    initialize_pool();

    char* buffer = (char*)allocate(512);
    if (buffer == NULL) {
        printf("Allocation failed\n");
        return 1;
    }

    strcpy(buffer, "Hello, world!");
    printf("%s\n", buffer);

    // Intentional buffer overflow
    strcpy((buffer + 512), "This should cause an overflow");

    return 0;
}
