#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(const char* input, int size) {
    char output[size];
    for (int i = 0; i <= size; i++) { // Out-of-bounds read vulnerability
        output[i] = input[i];
    }
    printf("Compressed data: %s\n", output);
}

int main() {
    const char* data = "Hello, World!";
    int dataSize = 13;
    compress(data, dataSize);
    return 0;
}
