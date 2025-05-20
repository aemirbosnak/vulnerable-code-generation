//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: scientific
/*
 * C Compression Algorithm Example Program
 *
 * This program implements a simple compression algorithm that compresses
 * a string of characters by replacing repeated sequences of characters
 * with a single character and its count.
 */

#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

// Function to compress a string using the algorithm
char* compress(char* str) {
    // Initialize variables
    char* compressed = malloc(MAX_STRING_LENGTH);
    int compressed_length = 0;
    int i = 0;

    // Loop through the input string
    while (str[i] != '\0') {
        // Check if the current character is repeated
        int count = 1;
        while (str[i + count] == str[i]) {
            count++;
        }

        // If the character is repeated, add it to the compressed string
        if (count > 1) {
            compressed[compressed_length++] = str[i];
            compressed[compressed_length++] = count + '0';
        } else {
            compressed[compressed_length++] = str[i];
        }

        // Update the current index
        i += count;
    }

    // Terminate the compressed string
    compressed[compressed_length] = '\0';

    return compressed;
}

// Function to decompress a string using the algorithm
char* decompress(char* compressed) {
    // Initialize variables
    char* decompressed = malloc(MAX_STRING_LENGTH);
    int decompressed_length = 0;
    int i = 0;

    // Loop through the compressed string
    while (compressed[i] != '\0') {
        // Check if the current character is repeated
        int count = compressed[i + 1] - '0';

        // If the character is repeated, add it to the decompressed string
        if (count > 1) {
            decompressed[decompressed_length++] = compressed[i];
            for (int j = 0; j < count; j++) {
                decompressed[decompressed_length++] = compressed[i];
            }
        } else {
            decompressed[decompressed_length++] = compressed[i];
        }

        // Update the current index
        i += 2;
    }

    // Terminate the decompressed string
    decompressed[decompressed_length] = '\0';

    return decompressed;
}

int main() {
    // Test the compression and decompression functions
    char* str = "Hello, world!";
    char* compressed = compress(str);
    char* decompressed = decompress(compressed);

    // Print the original string and the compressed and decompressed strings
    printf("Original string: %s\n", str);
    printf("Compressed string: %s\n", compressed);
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}