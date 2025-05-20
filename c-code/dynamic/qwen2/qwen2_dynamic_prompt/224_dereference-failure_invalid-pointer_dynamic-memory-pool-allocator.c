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

void deallocate(void* ptr) {
    // No-op in this unsafe version
}

int main() {
    int* arr = (int*)allocate(10 * sizeof(int));
    if (!arr) {
        printf("Allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        arr[i] = i * 10;
    }

    printf("Array elements: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Dereference failure example
    int* invalid_ptr = (int*)((char*)arr + POOL_SIZE);
    printf("Value at invalid pointer: %d\n", *invalid_ptr); // Invalid access

    return 0;
}
