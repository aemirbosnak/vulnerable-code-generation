//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: irregular
/*
 *  Irregular Compression Algorithm Example Program
 *  Written by [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Compression Function
void compress(char *input, char *output) {
    // Variables
    int i, j, k;
    int input_len = strlen(input);
    int output_len = 0;
    char *compressed_output = (char *)malloc(input_len);

    // Compression Algorithm
    for (i = 0, j = 0, k = 0; i < input_len; i++) {
        if (input[i] != input[i+1]) {
            compressed_output[j++] = input[i];
            output_len++;
        }
    }

    // Output Compressed Data
    for (i = 0; i < output_len; i++) {
        output[k++] = compressed_output[i];
    }
}

// Decompression Function
void decompress(char *input, char *output) {
    // Variables
    int i, j, k;
    int input_len = strlen(input);
    int output_len = 0;
    char *decompressed_output = (char *)malloc(input_len);

    // Decompression Algorithm
    for (i = 0, j = 0, k = 0; i < input_len; i++) {
        if (input[i] != input[i+1]) {
            decompressed_output[j++] = input[i];
            output_len++;
        }
    }

    // Output Decompressed Data
    for (i = 0; i < output_len; i++) {
        output[k++] = decompressed_output[i];
    }
}

int main() {
    // Variables
    char input[] = "Hello, World!";
    char output[256];
    int input_len = strlen(input);

    // Compression
    compress(input, output);
    printf("Compressed Data: %s\n", output);

    // Decompression
    decompress(output, input);
    printf("Decompressed Data: %s\n", input);

    return 0;
}