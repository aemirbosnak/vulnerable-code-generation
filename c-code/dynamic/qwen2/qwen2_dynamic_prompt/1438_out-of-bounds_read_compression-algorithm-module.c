#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void compress_data(const char *input, size_t input_size, char *output, size_t output_size) {
    if (output_size < input_size) {
        fprintf(stderr, "Output buffer too small\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i <= input_size; i++) { // Out of bounds read vulnerability
        output[i] = input[i];
    }
}

int main() {
    const char *input = "This is a test string";
    size_t input_size = strlen(input);

    char *output = malloc(input_size + 1);
    if (!output) {
        perror("Failed to allocate memory");
        return EXIT_FAILURE;
    }

    compress_data(input, input_size, output, input_size); // Vulnerable call

    printf("Compressed data: %s\n", output);

    free(output);
    return EXIT_SUCCESS;
}
