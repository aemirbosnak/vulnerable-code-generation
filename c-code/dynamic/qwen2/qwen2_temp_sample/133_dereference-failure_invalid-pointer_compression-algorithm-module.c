#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void compressData(int *data, int size) {
    if (size <= 0) return;
    
    int *compressed = (int *)malloc(size * sizeof(int));
    if (!compressed) return;

    compressed[0] = data[0];
    int count = 1;

    for (int i = 1; i < size; i++) {
        if (data[i] != data[i - 1]) {
            compressed[count++] = data[i];
        }
    }

    printf("Compressed Data: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", compressed[i]);
    }
    printf("\n");

    free(compressed);
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    compressData(data, size);

    // Invalid pointer dereference
    int *invalidPtr = NULL;
    printf("Invalid Pointer Value: %d\n", *invalidPtr); // Dereferencing null pointer

    return 0;
}
