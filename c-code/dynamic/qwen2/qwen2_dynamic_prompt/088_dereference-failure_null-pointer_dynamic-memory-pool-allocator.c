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

int main() {
    int* ptr1 = (int*)allocate(sizeof(int));
    *ptr1 = 42;

    int* ptr2 = (int*)allocate(sizeof(int));
    *ptr2 = 99;

    printf("Value at ptr1: %d\n", *ptr1);
    printf("Value at ptr2: %d\n", *ptr2);

    // Dereference failure example
    int* null_ptr = NULL;
    printf("Value at null_ptr: %d\n", *null_ptr); // This will cause a segmentation fault

    return 0;
}
