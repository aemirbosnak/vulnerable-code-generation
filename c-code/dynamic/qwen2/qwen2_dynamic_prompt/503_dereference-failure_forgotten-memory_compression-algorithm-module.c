#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compressData(char *data, int size) {
    char *compressed = malloc(size); // Allocate memory for compressed data
    if (!compressed) {
        printf("Memory allocation failed\n");
        return;
    }

    int j = 0;
    for (int i = 0; i < size; i++) {
        compressed[j++] = data[i];
        while (i + 1 < size && data[i] == data[i + 1]) {
            i++;
        }
    }

    free(compressed); // Free allocated memory
}

int main() {
    char data[] = "aaabbbcc";
    int size = sizeof(data) / sizeof(data[0]);

    compressData(data, size);

    return 0;
}
