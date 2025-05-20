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
    char* data = (char*)allocate(10);
    if (!data) {
        printf("Allocation failed\n");
        return 1;
    }
    strcpy(data, "Hello, World!");
    printf("%s\n", data);

    // Dereference failure: null pointer
    char* null_ptr = NULL;
    *null_ptr = 'A'; // This will cause a segmentation fault

    return 0;
}
