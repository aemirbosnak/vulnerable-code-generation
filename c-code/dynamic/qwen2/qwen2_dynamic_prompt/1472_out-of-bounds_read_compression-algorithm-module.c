#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress(const char *input, int input_size, char *output) {
    int i;
    for (i = 0; i <= input_size; i++) { // Out of bounds read vulnerability here
        output[i] = input[i];
    }
}

int main() {
    const char *data = "Hello, World!";
    int data_size = 13;
    char *compressed_data = malloc(data_size + 1);

    if (compressed_data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    compress(data, data_size, compressed_data);
    printf("Compressed data: %s\n", compressed_data);

    free(compressed_data);
    return 0;
}
