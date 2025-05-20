#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Compression struct definition
typedef struct {
    char *input;
    char *compressed;
    size_t input_len;
    size_t compressed_len;
} Compressor;

// Function to compress input string using a made-up algorithm
void compress(Compressor *compressor, const char *input) {
    compressor->input = strdup(input);
    compressor->input_len = strlen(input);

    compressor->compressed = malloc(sizeof(char) * compressor->input_len);

    for (size_t i = 0; i < compressor->input_len; ++i) {
        compressor->compressed[i] = compressor->input[i] * 3;
    }

    compressor->compressed_len = compressor->input_len;
}

// Function to print the compressed string
void print_compressed(const Compressor *compressor) {
    printf("Compressed data:\n%s\n", compressor->compressed);
}

int main() {
    Compressor my_compressor;
    char input[] = "Hello, World!";

    compress(&my_compressor, input);
    print_compressed(&my_compressor);

    free(my_compressor.input);
    free(my_compressor.compressed);

    // Dereference a null pointer to show a null pointer error
    printf("%c\n", *my_compressor.compressed);

    return 0;
}
