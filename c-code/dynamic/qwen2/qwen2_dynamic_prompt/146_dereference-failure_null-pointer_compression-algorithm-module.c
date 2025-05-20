#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compressData(int *data, int size) {
    if (data == NULL) {
        printf("Error: Data pointer is null.\n");
        return;
    }

    // Simulate compression logic
    for (int i = 0; i < size; i++) {
        data[i] *= 2;
    }
}

int main() {
    int *data = NULL;
    int size = 10;

    // Allocate memory for data
    data = (int *)malloc(size * sizeof(int));
    if (data == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize data
    for (int i = 0; i < size; i++) {
        data[i] = i + 1;
    }

    // Compress data
    compressData(data, size);

    // Print compressed data
    printf("Compressed data:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    // Free allocated memory
    free(data);

    return 0;
}
