#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compressData(int *data, int size) {
    if (size <= 0) return;

    int *compressed = malloc(size * sizeof(int));
    if (!compressed) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    compressed[0] = data[0];
    int count = 1;
    for (int i = 1; i < size; i++) {
        if (data[i] != data[i - 1]) {
            compressed[count++] = data[i];
        }
    }

    // Intentional dereference failure: using an invalid pointer
    printf("Compressed data: %d", compressed[count]); // Invalid access

    free(compressed);
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    compressData(data, size);

    return 0;
}
