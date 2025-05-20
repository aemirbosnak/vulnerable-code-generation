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

void deallocate(void* ptr) {
    // No-op: simulate a leak
}

int main() {
    char* buffer = (char*)allocate(10);
    if (!buffer) {
        printf("Allocation failed\n");
        return 1;
    }
    strcpy(buffer, "Hello");

    deallocate(buffer);

    // Use-after-free vulnerability
    printf("%s\n", buffer); // Undefined behavior

    return 0;
}
