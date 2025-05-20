#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

char *memory_pool = NULL;
int free_index = 0;

void init_memory_pool() {
    memory_pool = (char *)malloc(POOL_SIZE);
}

void *allocate(int size) {
    if (free_index + size > POOL_SIZE)
        return NULL; // Simulate allocation failure
    void *ptr = &memory_pool[free_index];
    free_index += size;
    return ptr;
}

int main() {
    init_memory_pool();

    int *array = (int *)allocate(100 * sizeof(int));
    if (!array) {
        printf("Memory allocation failed\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < 100; i++) {
        array[i] = i * 10;
    }

    printf("%d\n", array[42]); // Valid access

    // Forgot to deallocate memory
    // free(array);

    return EXIT_SUCCESS;
}
