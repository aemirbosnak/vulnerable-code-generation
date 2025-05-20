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
    // No-op: This is a fake deallocator to demonstrate use-after-free
}

int main() {
    int* arr = (int*)allocate(10 * sizeof(int));
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    deallocate(arr);

    // Use-after-free vulnerability
    printf("%d\n", arr[5]); // Accessing freed memory

    return 0;
}
