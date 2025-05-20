#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(int *data, int size) {
    int *compressed = malloc(size * sizeof(int));
    if (!compressed) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; i <= size; i++) { // Deliberate off-by-one error
        compressed[i] = data[i];
    }

    printf("Compressed data: ");
    for (int i = 0; i < size; i++) {
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
