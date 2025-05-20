//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Function to compress a string
char* compress(char* input) {
    // Get the length of the input string
    int input_len = strlen(input);

    // Create a new string to hold the compressed data
    char* compressed = malloc(input_len * sizeof(char));

    // Initialize a variable to keep track of the current position in the compressed data
    int compressed_pos = 0;

    // Iterate over the input string
    for (int i = 0; i < input_len; i++) {
        // Get the current character
        char current_char = input[i];

        // Check if the current character is the same as the previous character
        if (i == 0 || input[i - 1] != current_char) {
            // If the current character is the same as the previous character,
            // increment the number of times the character appears
            int count = 1;

            // Iterate over the remaining characters in the input string
            for (int j = i + 1; j < input_len; j++) {
                // Check if the current character is the same as the next character
                if (input[j] == current_char) {
                    // If the current character is the same as the next character,
                    // increment the number of times the character appears
                    count++;
                } else {
                    // If the current character is not the same as the next character,
                    // break the loop
                    break;
                }
            }

            // Add the current character to the compressed data
            compressed[compressed_pos++] = current_char;

            // Add the number of times the character appears to the compressed data
            compressed[compressed_pos++] = count;
        }
    }

    // Return the compressed data
    return compressed;
}

// Function to decompress a string
char* decompress(char* compressed) {
    // Get the length of the compressed data
    int compressed_len = strlen(compressed);

    // Create a new string to hold the decompressed data
    char* decompressed = malloc(compressed_len * sizeof(char));

    // Initialize a variable to keep track of the current position in the decompressed data
    int decompressed_pos = 0;

    // Iterate over the compressed data
    for (int i = 0; i < compressed_len; i += 2) {
        // Get the current character and the number of times it appears
        char current_char = compressed[i];
        int count = compressed[i + 1] - '0';

        // Add the current character to the decompressed data count times
        for (int j = 0; j < count; j++) {
            decompressed[decompressed_pos++] = current_char;
        }
    }

    // Return the decompressed data
    return decompressed;
}

int main() {
    // Test the compression and decompression functions
    char* input = "hello world";
    char* compressed = compress(input);
    char* decompressed = decompress(compressed);

    // Print the original input, the compressed data, and the decompressed data
    printf("Original input: %s\n", input);
    printf("Compressed data: %s\n", compressed);
    printf("Decompressed data: %s\n", decompressed);

    // Free the memory allocated for the compressed and decompressed data
    free(compressed);
    free(decompressed);

    return 0;
}