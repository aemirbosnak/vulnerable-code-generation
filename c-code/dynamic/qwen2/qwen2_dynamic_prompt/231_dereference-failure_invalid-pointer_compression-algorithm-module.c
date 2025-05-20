#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compressData(char *data, int size) {
    char *compressed = malloc(size);
    if (!compressed) {
        printf("Memory allocation failed\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        compressed[i] = data[i];
    }
    free(compressed);
}

int main() {
    char *data = "This is a test string";
    int size = 21;

    // Simulate invalid pointer usage
    char *invalidPtr = NULL;
    compressData(invalidPtr, size);

    return 0;
}
