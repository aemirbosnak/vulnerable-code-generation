#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MEM_SIZE 1024

char mem[MEM_SIZE];
int free_ptr = 0;

void* my_malloc(size_t size) {
    if (free_ptr + size > MEM_SIZE) return NULL;
    void* ptr = &mem[free_ptr];
    free_ptr += size;
    return ptr;
}

void my_free(void* ptr) {
    // No-op in this simple example
}

void my_init() {
    free_ptr = 0;
}

int main() {
    int* arr = (int*)my_malloc(10 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    my_init();
    arr = (int*)my_malloc(5 * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
