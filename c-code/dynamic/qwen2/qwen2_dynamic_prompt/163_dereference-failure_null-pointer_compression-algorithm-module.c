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
            compressed[compressedSize++] = data[i];
        }
    }

    // Dereference null pointer
    printf("Compressed Data: %s\n", compressed);
}

int main() {
    char data[] = "aaabbbcc";
    int size = sizeof(data) / sizeof(data[0]);

    compressData(data, size);

    return 0;
}
