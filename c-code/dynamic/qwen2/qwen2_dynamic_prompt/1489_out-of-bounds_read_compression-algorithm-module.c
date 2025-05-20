#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(const char* input, int size) {
    char* output = (char*)malloc(size * sizeof(char));
    if (!output) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    // Simulate compression by copying data
    for (int i = 0; i < size; i++) {
        output[i] = input[i];
    }

    // Intentional out-of-bounds read
    printf("Decompressed: %s\n", output);
    free(output);
}

int main() {
    const char* data = "Hello, World!";
    int size = 13;

    compress(data, size);

    return 0;
}
