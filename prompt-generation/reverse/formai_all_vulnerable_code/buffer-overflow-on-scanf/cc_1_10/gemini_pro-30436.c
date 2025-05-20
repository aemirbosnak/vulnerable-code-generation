//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defines the maximum size of the input data
#define MAX_INPUT_SIZE 1024

// The compression function
int compress(char *input, char *output) {
    // Initialize the compression state
    int in_count = 0;
    int out_count = 0;
    char prev_char = '\0';
    int repeat_count = 0;

    // Iterate through the input string
    while (*input != '\0') {
        // If the current character is the same as the previous character, increment the repeat count
        if (*input == prev_char) {
            repeat_count++;
        // Otherwise, output the previous character and its repeat count
        } else {
            if (prev_char != '\0') {
                output[out_count++] = prev_char;
                output[out_count++] = repeat_count;
            }
            prev_char = *input;
            repeat_count = 1;
        }

        // Increment the input counter
        input++;
        in_count++;
    }

    // Output the last character and its repeat count
    if (prev_char != '\0') {
        output[out_count++] = prev_char;
        output[out_count++] = repeat_count;
    }

    // Return the size of the compressed string
    return out_count;
}

// The decompression function
int decompress(char *input, char *output) {
    // Initialize the decompression state
    int in_count = 0;
    int out_count = 0;
    char prev_char = '\0';
    int repeat_count = 0;

    // Iterate through the input string
    while (*input != '\0') {
        // If the current character is a character, output it
        if (prev_char != '\0') {
            output[out_count++] = prev_char;
        }

        // Get the repeat count
        repeat_count = *input++;

        // Output the character repeat_count times
        for (int i = 0; i < repeat_count; i++) {
            output[out_count++] = prev_char;
        }

        // Increment the input counter
        in_count++;

        // Update the previous character
        prev_char = *input++;
    }

    // Return the size of the decompressed string
    return out_count;
}

// The main function
int main() {
    // Define the input and output strings
    char input[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE];

    // Get the input string
    printf("Enter the input string: ");
    scanf("%s", input);

    // Compress the input string
    int compressed_size = compress(input, output);

    // Output the compressed string
    printf("Compressed string: ");
    for (int i = 0; i < compressed_size; i++) {
        printf("%c", output[i]);
    }
    printf("\n");

    // Decompress the compressed string
    int decompressed_size = decompress(output, input);

    // Output the decompressed string
    printf("Decompressed string: ");
    for (int i = 0; i < decompressed_size; i++) {
        printf("%c", input[i]);
    }
    printf("\n");

    return 0;
}