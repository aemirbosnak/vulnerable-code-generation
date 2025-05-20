#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void compress(char *data, int size) {
    char *compressed = (char *)malloc(size);
    if (compressed == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    memcpy(compressed, data, size);
    free(data); // Freeing the original data pointer

    // Using freed memory here
    compressed[0] = 'C';
    printf("Compressed data: %s\n", compressed);
}

int main() {
    char *original = "This is a sample string to compress";
    compress(original, strlen(original) + 1);
    return 0;
}
