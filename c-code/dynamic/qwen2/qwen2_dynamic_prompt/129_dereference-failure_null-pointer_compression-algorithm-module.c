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
        if (i % 2 == 0) {
            compressed[compressedSize++] = data[i];
        }
    }

    // Dereference null pointer
    printf("Compressed Data: %s\n", compressed);
}

int main() {
    char originalData[] = "This is a test string for compression.";
    int dataSize = sizeof(originalData);

    compressData(originalData, dataSize);

    return 0;
}
