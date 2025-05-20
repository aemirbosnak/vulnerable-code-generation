//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function to compress a string
char *compress(char *str) {
    // Get the length of the string
    int len = strlen(str);

    // Create a buffer to store the compressed string
    char *buffer = malloc(BUFFER_SIZE);

    // Initialize the buffer index
    int i = 0;

    // Loop through the string
    for (int j = 0; j < len; j++) {
        // Get the current character
        char c = str[j];

        // If the current character is the same as the previous character
        if (j > 0 && c == str[j - 1]) {
            // Increment the count of the previous character
            buffer[i - 1]++;
        } else {
            // Add the current character to the buffer
            buffer[i++] = c;

            // Add the count of the current character to the buffer
            buffer[i++] = 1;
        }
    }

    // Return the compressed string
    return buffer;
}

// Function to decompress a string
char *decompress(char *str) {
    // Get the length of the string
    int len = strlen(str);

    // Create a buffer to store the decompressed string
    char *buffer = malloc(BUFFER_SIZE);

    // Initialize the buffer index
    int i = 0;

    // Loop through the string
    for (int j = 0; j < len; j += 2) {
        // Get the current character
        char c = str[j];

        // Get the count of the current character
        int count = str[j + 1];

        // Add the current character to the buffer count times
        for (int k = 0; k < count; k++) {
            buffer[i++] = c;
        }
    }

    // Return the decompressed string
    return buffer;
}

// Main function
int main() {
    // Get the input string
    char *str = malloc(BUFFER_SIZE);
    printf("Enter the string to compress: ");
    scanf("%s", str);

    // Compress the string
    char *compressedStr = compress(str);

    // Print the compressed string
    printf("Compressed string: %s\n", compressedStr);

    // Decompress the string
    char *decompressedStr = decompress(compressedStr);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressedStr);

    // Free the memory allocated for the strings
    free(str);
    free(compressedStr);
    free(decompressedStr);

    return 0;
}