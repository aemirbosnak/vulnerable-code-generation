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

void free_all() {
    pool_index = 0;
}

int main() {
    char input[256];
    printf("Enter data to store: ");
    fgets(input, sizeof(input), stdin);

    int size;
    printf("Enter size of data: ");
    if (sscanf(input, "%d", &size) != 1) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    char* data = allocate(size);
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter data to store in allocated memory: ");
    fgets(data, size, stdin);

    printf("Data stored: %s\n", data);

    free_all();

    return 0;
}
