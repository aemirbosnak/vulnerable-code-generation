//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Compress function
void compress(char *input, char *output) {
    // Variables
    int input_size = strlen(input);
    int output_size = 0;
    char *buffer = malloc(BUFFER_SIZE);

    // Compression algorithm
    for (int i = 0; i < input_size; i++) {
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
            buffer[output_size++] = input[i];
        }
    }

    // Write to output file
    FILE *out = fopen(output, "w");
    fwrite(buffer, sizeof(char), output_size, out);
    fclose(out);

    // Free memory
    free(buffer);
}

// Decompress function
void decompress(char *input, char *output) {
    // Variables
    int input_size = strlen(input);
    int output_size = 0;
    char *buffer = malloc(BUFFER_SIZE);

    // Decompression algorithm
    for (int i = 0; i < input_size; i++) {
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u') {
            buffer[output_size++] = input[i];
        }
    }

    // Write to output file
    FILE *out = fopen(output, "w");
    fwrite(buffer, sizeof(char), output_size, out);
    fclose(out);

    // Free memory
    free(buffer);
}

int main() {
    // Compress example
    char *input = "hello world";
    char *output = "output.txt";
    compress(input, output);

    // Decompress example
    input = "output.txt";
    output = "decompressed.txt";
    decompress(input, output);

    return 0;
}