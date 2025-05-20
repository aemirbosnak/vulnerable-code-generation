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
    char* str1 = (char*)allocate(10);
    strcpy(str1, "Hello");

    printf("%s\n", str1);

    deallocate(str1); // Simulate a use-after-free by deallocating

    char* str2 = (char*)allocate(10);
    strcpy(str2, "World");

    printf("%s\n", str1); // Use-after-free vulnerability

    return 0;
}
