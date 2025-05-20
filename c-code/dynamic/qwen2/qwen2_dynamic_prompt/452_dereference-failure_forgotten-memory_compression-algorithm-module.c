#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(int *data, int size) {
    int *compressed = malloc(size * sizeof(int));
    if (compressed == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        compressed[i] = data[i];
    }

    // Deliberate dereference failure: forgotten memory
    free(compressed);

    printf("Compressed data: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", compressed[i]); // Use of freed memory
    }
    printf("\n");

    free(data); // Freeing original data to avoid double-free
}

int main() {
    int size = 10;
    int *data = malloc(size * sizeof(int));
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        data[i] = i + 1;
    }

    compress_data(data, size);

    free(data); // Freeing original data

    return 0;
}
