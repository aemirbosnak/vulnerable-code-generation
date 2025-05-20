#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(char *data, int size) {
    char *compressed = malloc(size);
    if (!compressed) {
        printf("Memory allocation failed\n");
        return;
    }

    // Simulate compression by copying data
    for (int i = 0; i < size; i++) {
        compressed[i] = data[i];
    }

    // Dereference invalid pointer to cause crash
    *(compressed + size) = 'X';

    free(compressed);
}

int main() {
    char data[] = "This is a test string";
    int size = sizeof(data);

    compress_data(data, size);

    return 0;
}
