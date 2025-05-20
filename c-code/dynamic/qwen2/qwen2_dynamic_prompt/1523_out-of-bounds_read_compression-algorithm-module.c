#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(const char* input, int size) {
    char* output = (char*)malloc(size * sizeof(char));
    if (!output) {
        printf("Memory allocation failed\n");
        return;
    }

    // Simulate compression by copying data
    for (int i = 0; i < size; i++) {
        output[i] = input[i];
    }

    // Intentional out-of-bounds read
    printf("%c\n", output[size]); // This will cause an out-of-bounds read

    free(output);
}

int main() {
    const char* data = "Hello, World!";
    int dataSize = 13;

    compress(data, dataSize);

    return 0;
}
