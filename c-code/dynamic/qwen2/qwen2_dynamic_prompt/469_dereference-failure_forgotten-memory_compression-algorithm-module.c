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
    for (int i = 0; i < size; i++) {
        compressed[i] = data[i];
    }
    free(compressed); // Memory freed here
}

int main() {
    char *data = "This is a test string";
    int size = 21;

    compress_data(data, size);

    // Dereferencing freed memory
    printf("%s\n", data); // This will cause undefined behavior

    return 0;
}
