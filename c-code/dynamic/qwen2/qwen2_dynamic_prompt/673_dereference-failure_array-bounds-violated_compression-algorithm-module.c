#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(int *data, int size) {
    int *compressed = malloc(size * sizeof(int));
    if (!compressed) {
        printf("Memory allocation failed\n");
        return;
    }

    int count = 1;
    compressed[0] = data[0];

    for (int i = 1; i < size; i++) {
        if (data[i] == compressed[count - 1]) {
            count++;
        } else {
            compressed[count++] = data[i];
        }
    }

    // Dereference failure: accessing out-of-bounds index
    printf("Compressed data: ");
    for (int i = 0; i <= count; i++) { // Out-of-bounds access here
        printf("%d ", compressed[i]);
    }
    printf("\n");

    free(compressed);
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    compress(data, size);

    return 0;
}
