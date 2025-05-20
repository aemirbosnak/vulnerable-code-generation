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
        if (data[i] == ' ') {
            continue;
        }
        compressed[compressedSize++] = data[i];
    }

    // Null pointer dereference vulnerability
    printf("Compressed Data: %s\n", compressed);

    free(compressed);
}

int main() {
    char *inputData = "This is a test string.";
    compressData(inputData, strlen(inputData));
    return 0;
}
