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
    // No-op: This is intentionally left empty to simulate a leaky allocator
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

    // Dereference failure: Accessing freed memory
    int* invalid_ptr = (int*)((char*)arr + 10 * sizeof(int));
    printf("Invalid access: %d\n", *invalid_ptr);

    return 0;
}
