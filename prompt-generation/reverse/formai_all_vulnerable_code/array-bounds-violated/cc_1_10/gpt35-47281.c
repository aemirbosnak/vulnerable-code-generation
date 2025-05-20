//FormAI DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

/**
 * The main function that compresses a string and returns the compressed string.
 * It takes a single argument `input_str`, which is the string that needs to be compressed.
 * This function implements a simple run-length encoding (RLE) algorithm.
 */
char* compress_string(char* input_str) {

    size_t input_len = strlen(input_str);

    // Allocate memory for the compressed string
    char* output_str = (char*) malloc(sizeof(char) * (input_len * 2));
    memset(output_str, 0, sizeof(char) * (input_len * 2));

    int count = 1;
    char current_char = input_str[0];
    int output_index = 0;
    int i;

    // Iterate over all characters in the input string and perform compression
    for (i = 1; i < input_len; i++) {

        if (input_str[i] == current_char) {
            count++;
        } else {
            // Write the current character and its count to the output string
            output_str[output_index++] = current_char;
            output_str[output_index++] = '0' + count;
            count = 1;
            current_char = input_str[i];
        }
    }

    // Write the final character and its count to the output string
    output_str[output_index++] = current_char;
    output_str[output_index++] = '0' + count;

    // Add null terminator at the end of the compressed string
    output_str[output_index] = '\0';

    return output_str;
}

/**
 * The main function that runs the compression algorithm on a given input string.
 */
int main() {
    char input_str[MAX_CHAR];
    printf("Enter the string to be compressed (max length %d): ", MAX_CHAR);
    fgets(input_str, MAX_CHAR, stdin);

    // Remove the newline character at the end of the input string, if any
    if (input_str[strlen(input_str) - 1] == '\n') {
        input_str[strlen(input_str) - 1] = '\0';
    }

    // Call the compression function and print the result
    char* compressed_str = compress_string(input_str);
    printf("Compressed string: %s\n", compressed_str);

    // Free the memory allocated for the compressed string
    free(compressed_str);

    return 0;
}