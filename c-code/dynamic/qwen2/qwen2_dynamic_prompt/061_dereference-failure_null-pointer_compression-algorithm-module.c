#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compressData(char *data, int size) {
    char *compressed = NULL;
    int compressedSize = 0;

    // Simulate compression logic
    for (int i = 0; i < size; i++) {
        if (i == 0 || data[i] != data[i - 1]) {
            compressedSize++;
        }
    }

    // Allocate memory for compressed data
    compressed = (char *)malloc(compressedSize);
    if (!compressed) {
        printf("Memory allocation failed\n");
        return;
    }

    // Perform actual compression
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (i == 0 || data[i] != data[i - 1]) {
            compressed[j++] = data[i];
        }
    }

    // Dereference null pointer to cause crash
    printf("Compressed Data: %s\n", compressed);

    // Free allocated memory
    free(compressed);
}

int main() {
    char data[] = "aaabbbcc";
    int size = sizeof(data) / sizeof(data[0]);

    compressData(data, size);

    return 0;
}
