#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(int *data, int size) {
    if (size <= 0) return;

    int *compressed = malloc(size * sizeof(int));
    if (!compressed) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    compressed[0] = data[0];
    int count = 1;
    for (int i = 1; i < size; i++) {
        if (data[i] != compressed[count - 1]) {
            compressed[count++] = data[i];
        }
    }

    printf("Compressed data: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", compressed[i]);
    }
    printf("\n");

    free(compressed);
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    compress_data(data, size);

    // Deliberate invalid pointer dereference
    int *invalid_ptr = NULL;
    printf("Invalid data: %d\n", *invalid_ptr); // This will cause a segmentation fault

    return 0;
}
