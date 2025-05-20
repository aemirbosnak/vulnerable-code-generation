#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(const char *input, int length) {
    char output[length];
    for (int i = 0; i <= length; i++) { // Out of bounds read vulnerability
        output[i] = input[i];
    }
    printf("Compressed data: %s\n", output);
}

int main() {
    const char *data = "Hello, World!";
    int len = 13;
    compress(data, len);
    return 0;
}
