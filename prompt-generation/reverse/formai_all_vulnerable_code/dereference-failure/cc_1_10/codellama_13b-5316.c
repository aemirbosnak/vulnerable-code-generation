//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: medieval
/*
 * Medieval Compression Algorithm
 *
 * This algorithm is based on the idea of compressing a string by
 * replacing consecutive identical characters with a single character
 * followed by a count of the number of times that character appears.
 *
 * For example, the string "aaabbbccc" would be compressed to "a3b3c3".
 *
 * This algorithm is similar to the run-length encoding algorithm,
 * but with a twist. Instead of only compressing consecutive
 * identical characters, it also compresses consecutive identical
 * characters with different case.
 *
 * For example, the string "AaBbCc" would be compressed to "A2b2C2".
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string using the medieval compression algorithm
char *medieval_compress(char *str) {
    // Initialize variables
    char *compressed = malloc(strlen(str) + 1);
    int i, j, count = 1;

    // Iterate through the string
    for (i = 0, j = 0; str[i] != '\0'; i++) {
        // If the current character is the same as the previous character
        if (str[i] == str[i - 1]) {
            // Increment the count
            count++;
        } else {
            // If the count is greater than 1, write the count to the compressed string
            if (count > 1) {
                compressed[j++] = count + '0';
            }

            // Write the character to the compressed string
            compressed[j++] = str[i];

            // Reset the count
            count = 1;
        }
    }

    // If the count is greater than 1, write the count to the compressed string
    if (count > 1) {
        compressed[j++] = count + '0';
    }

    // Add a null terminator to the compressed string
    compressed[j] = '\0';

    return compressed;
}

// Function to decompress a string using the medieval compression algorithm
char *medieval_decompress(char *compressed) {
    // Initialize variables
    char *decompressed = malloc(strlen(compressed) + 1);
    int i, j, count = 0;

    // Iterate through the compressed string
    for (i = 0, j = 0; compressed[i] != '\0'; i++) {
        // If the current character is a digit, parse the count
        if (compressed[i] >= '0' && compressed[i] <= '9') {
            count = compressed[i] - '0';
        } else {
            // Write the character to the decompressed string count times
            for (int k = 0; k < count; k++) {
                decompressed[j++] = compressed[i];
            }

            // Reset the count
            count = 0;
        }
    }

    // Add a null terminator to the decompressed string
    decompressed[j] = '\0';

    return decompressed;
}

int main() {
    // Test the compression and decompression functions
    char *str = "Hello, World!";
    char *compressed = medieval_compress(str);
    char *decompressed = medieval_decompress(compressed);

    printf("Compressed: %s\n", compressed);
    printf("Decompressed: %s\n", decompressed);

    return 0;
}