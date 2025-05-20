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
    // Intentionally do nothing to simulate a use-after-free vulnerability
}

int main() {
    int* data = (int*)my_malloc(sizeof(int));
    *data = 42;
    printf("Data: %d\n", *data);
    my_free(data); // Freeing the memory
    printf("Data after free: %d\n", *data); // Use-after-free vulnerability
    return 0;
}
