#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(int* data, int size) {
    int* compressed = (int*)malloc(size * sizeof(int));
    if (compressed == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        compressed[i] = data[i];
    }

    // Simulating an invalid pointer dereference
    int* invalid_ptr = compressed + size;
    *invalid_ptr = 42;

    free(compressed);
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    compress(data, size);

    return 0;
}
