//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: happy
#include <stdio.h>
#include <string.h>

// A happy little function to compress a string
char* compress(char* str) {
    // Initialize the compressed string
    char* compressed = malloc(strlen(str) + 1);
    int compressed_length = 0;

    // Iterate over the original string
    int i = 0;
    while (str[i] != '\0') {
        // Get the current character and its count
        char c = str[i];
        int count = 1;
        while (str[i + count] == c) {
            count++;
        }

        // Append the character and its count to the compressed string
        compressed[compressed_length++] = c;
        compressed[compressed_length++] = count + '0';

        // Move to the next character
        i += count;
    }

    // Terminate the compressed string
    compressed[compressed_length] = '\0';

    // Return the compressed string
    return compressed;
}

// A happy little function to decompress a string
char* decompress(char* str) {
    // Initialize the decompressed string
    char* decompressed = malloc(strlen(str) * 2 + 1);
    int decompressed_length = 0;

    // Iterate over the compressed string
    int i = 0;
    while (str[i] != '\0') {
        // Get the current character and its count
        char c = str[i++];
        int count = str[i++] - '0';

        // Append the character to the decompressed string the specified number of times
        for (int j = 0; j < count; j++) {
            decompressed[decompressed_length++] = c;
        }
    }

    // Terminate the decompressed string
    decompressed[decompressed_length] = '\0';

    // Return the decompressed string
    return decompressed;
}

int main() {
    // Get the input string
    char str[100];
    printf("Enter a string to compress: ");
    scanf("%s", str);

    // Compress the string
    char* compressed = compress(str);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed);

    // Decompress the string
    char* decompressed = decompress(compressed);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    // Free the allocated memory
    free(compressed);
    free(decompressed);

    return 0;
}