#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define POOL_SIZE 1024

char pool[POOL_SIZE];
int pool_index = 0;

void* allocate(int size) {
    if (pool_index + size > POOL_SIZE) {
        return NULL;
    }
    void* ptr = &pool[pool_index];
    pool_index += size;
    return ptr;
}

int main() {
    char buffer[10];
    printf("Enter data: ");
    scanf("%s", buffer);
    printf("Data entered: %s\n", buffer);

    // Allocate memory from the pool
    int* data = (int*)allocate(sizeof(int));
    if (data == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    *data = 42;
    printf("Value stored: %d\n", *data);

    // Overwrite the allocated memory with user input
    printf("Enter new value: ");
    scanf("%d", data);

    printf("New value stored: %d\n", *data);

    return 0;
}
