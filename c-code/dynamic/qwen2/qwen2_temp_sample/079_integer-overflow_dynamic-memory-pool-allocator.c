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

void deallocate(void* ptr, int size) {
    // Intentionally left empty to simulate a vulnerability
}

int main() {
    int* large_array = (int*)allocate(POOL_SIZE);
    if (large_array == NULL) {
        printf("Allocation failed\n");
        return 1;
    }

    // Overwrite adjacent memory to demonstrate overflow
    int* next_int = (int*)((char*)large_array + POOL_SIZE);
    *next_int = 0xdeadbeef;

    printf("Adjacent memory overwritten: %p -> 0x%x\n", next_int, *next_int);

    deallocate(large_array, POOL_SIZE);

    return 0;
}
