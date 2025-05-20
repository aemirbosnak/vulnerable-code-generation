#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

char pool[POOL_SIZE];
int pool_index = 0;

void* my_malloc(size_t size) {
    if (pool_index + size > POOL_SIZE) return NULL;
    void* ptr = &pool[pool_index];
    pool_index += size;
    return ptr;
}

void my_free(void* ptr) {
    // Incorrectly freeing the pointer to avoid use-after-free
    pool_index -= sizeof(ptr);
}

int main() {
    int* arr = (int*)my_malloc(10 * sizeof(int));
    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    my_free(arr); // Freeing the allocated memory
    // Use-after-free vulnerability: accessing arr after it has been freed
    printf("%d\n", arr[5]); // This line will cause undefined behavior
    return 0;
}
