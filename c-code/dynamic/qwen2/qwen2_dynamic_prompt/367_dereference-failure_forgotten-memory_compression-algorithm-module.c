#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(char *data, int size) {
    char *compressed = malloc(size);
    if (!compressed) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // Simulate compression by copying data
    for (int i = 0; i < size; i++) {
        compressed[i] = data[i];
    }

    // Dereference failure: using freed memory
    free(compressed);
    printf("Compressed data: %s\n", compressed); // Use after free

    free(data);
}

int main() {
    char *original_data = malloc(20);
    if (!original_data) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize original data
    for (int i = 0; i < 20; i++) {
        original_data[i] = 'A' + (i % 26);
    }

    compress_data(original_data, 20);

    free(original_data);
    return 0;
}
