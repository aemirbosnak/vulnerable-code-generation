//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

// Function to compress the input string
void compress(char* input, char* output) {
    int i = 0, j = 0;
    char current_char = input[i];
    char prev_char = '\0';
    while (current_char!= '\0') {
        // Check for consecutive occurrences of the same character
        while (current_char == prev_char && i < strlen(input) - 1) {
            i++;
            current_char = input[i];
        }
        // Write the current character to the output buffer
        output[j++] = current_char;
        // Update the previous character
        prev_char = current_char;
        // Move to the next character
        i++;
        current_char = input[i];
    }
    // Add a special marker to indicate the end of the compressed string
    output[j++] = '\0';
    output[j] = '\0';
}

// Function to decompress the input string
void decompress(char* input, char* output) {
    int i = 0, j = 0;
    char current_char = input[i];
    while (current_char!= '\0') {
        // Check for consecutive occurrences of the same character
        int count = 1;
        while (i < strlen(input) - 1 && input[i] == current_char) {
            i++;
            count++;
        }
        // Write the current character multiple times to the output buffer
        for (int k = 0; k < count; k++) {
            output[j++] = current_char;
        }
        // Move to the next character
        i++;
        current_char = input[i];
    }
    // Add a special marker to indicate the end of the decompressed string
    output[j++] = '\0';
    output[j] = '\0';
}

int main() {
    char input[MAX_BUFFER_SIZE];
    char compressed_output[MAX_BUFFER_SIZE];
    char decompressed_output[MAX_BUFFER_SIZE];

    // Get input string from the user
    printf("Enter a string to compress: ");
    scanf("%s", input);

    // Compress the input string
    compress(input, compressed_output);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed_output);

    // Decompress the compressed string
    decompress(compressed_output, decompressed_output);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed_output);

    return 0;
}