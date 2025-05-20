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
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    compressData(data, size);

    return 0;
}
