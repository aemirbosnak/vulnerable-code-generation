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
    if (free_index + size > POOL_SIZE) {
        return NULL;
    }
    void* ptr = &pool[free_index];
    free_index += size;
    return ptr;
}

void my_free(void* ptr) {
    // In a real scenario, this would reset the memory to zero or another state
    // For simplicity, we just move the free index back
    free_index = (char*)ptr - pool;
}

int main() {
    int* a = (int*)my_malloc(sizeof(int));
    *a = 10;
    printf("Value: %d\n", *a);
    my_free(a);

    int* b = (int*)my_malloc(sizeof(int));
    *b = 20;
    printf("Value: %d\n", *b);

    return 0;
}
