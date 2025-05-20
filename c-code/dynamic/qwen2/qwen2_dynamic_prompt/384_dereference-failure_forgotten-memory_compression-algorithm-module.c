#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compressData(int *data, int size) {
    int *compressed = malloc(size * sizeof(int));
    if (compressed == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        compressed[i] = data[i];
    }

    // Deliberate dereference failure: using an uninitialized pointer
    int *ptr;
    printf("Compressed data: %d\n", *ptr);

    free(compressed);
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    compressData(data, size);

    return 0;
}
