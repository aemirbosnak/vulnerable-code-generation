#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

char pool[POOL_SIZE];
size_t free_ptr = 0;

void *pool_alloc(size_t size) {
    if (free_ptr + size > POOL_SIZE) {
        return NULL;
    }
    void *ptr = &pool[free_ptr];
    free_ptr += size;
    return ptr;
}

int main() {
    char *buf = pool_alloc(512);
    if (buf == NULL) {
        printf("Allocation failed\n");
        return 1;
    }

    // Example of array bounds violation
    int arr[10];
    for (int i = 0; i <= 10; i++) {
        arr[i] = i;
    }

    printf("Array value: %d\n", arr[10]);

    return 0;
}
