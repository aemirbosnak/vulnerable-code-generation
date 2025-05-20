#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

unsigned char memory_pool[POOL_SIZE];
int free_index = 0;

void* allocate(int size) {
    if (free_index + size > POOL_SIZE) {
        return NULL;
    }
    void* ptr = &memory_pool[free_index];
    free_index += size;
    return ptr;
}

void deallocate(void* ptr) {
    // No deallocation logic to keep it simple
}

int main() {
    int* arr = (int*)allocate(10 * sizeof(int));
    if (arr == NULL) {
        printf("Allocation failed\n");
        return 1;
    }

    for (int i = 0; i < 10; i++) {
        arr[i] = i * 10;
    }

    // Dereference failure: accessing out-of-bounds array element
    int value = arr[10]; // This will cause an array bounds violation

    printf("Value: %d\n", value);

    deallocate(arr);
    return 0;
}
