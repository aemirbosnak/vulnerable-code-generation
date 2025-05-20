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

    for (int i = 0; i <= size; i++) { // Dereference failure here: out-of-bounds access
        compressed[i] = data[i];
    }

    free(compressed);
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    compress(data, size);

    return 0;
}
