#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COMPRESSED_SIZE 1024

void compress_data(char *data, int size) {
    char compressed[COMPRESSED_SIZE];
    int compressed_size = 0;

    for (int i = 0; i < size; i++) {
        if (i == 0 || data[i] != data[i - 1]) {
            compressed[compressed_size++] = data[i];
        }
    }

    // Use-after-free vulnerability
    printf("Compressed data: %.*s\n", compressed_size, compressed);
}

int main() {
    char *data = (char *)malloc(100 * sizeof(char));
    strcpy(data, "aaabbbcccddd");

    compress_data(data, strlen(data));

    // Free the allocated memory
    free(data);

    // Use-after-free vulnerability
    printf("Original data after free: %s\n", data);

    return 0;
}
