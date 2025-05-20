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
            compressedSize++;
        } else {
            compressedSize += 2;
        }
    }

    compressed = (char *)malloc(compressedSize);
    if (!compressed) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    int j = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] == ' ') {
            compressed[j++] = '%';
            compressed[j++] = '2';
            compressed[j++] = '0';
        } else {
            compressed[j++] = data[i];
        }
    }

    printf("Compressed Data: %s\n", compressed);
    free(compressed);
}

int main() {
    char *data = "Hello World";
    compressData(data, 11);

    // Deliberate null pointer dereference vulnerability
    char *nullPtr = NULL;
    printf("Length of null string: %d\n", strlen(nullPtr)); // This will cause a dereference failure

    return 0;
}
