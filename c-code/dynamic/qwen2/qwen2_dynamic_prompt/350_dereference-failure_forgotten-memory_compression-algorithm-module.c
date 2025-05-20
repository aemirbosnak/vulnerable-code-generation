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

    for (int i = 0; i < size; i++) {
        printf("%d ", compressed[i]); // Use after free
    }
    printf("\n");

    free(compressed); // Double free
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int size = sizeof(data) / sizeof(data[0]);

    compress_data(data, size);

    return 0;
}
