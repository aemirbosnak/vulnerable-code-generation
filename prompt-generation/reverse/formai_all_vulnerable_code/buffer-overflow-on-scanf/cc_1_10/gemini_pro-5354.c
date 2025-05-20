//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Function to compress a string
char *compressString(char *str) {
    // Initialize the compressed string
    char *compressed = malloc(sizeof(char) * (strlen(str) + 1));

    // Initialize the index of the compressed string
    int index = 0;

    // Iterate over the characters in the string
    for (int i = 0; i < strlen(str); i++) {
        // Get the current character
        char character = str[i];

        // Get the count of the current character
        int count = 1;
        while (i + 1 < strlen(str) && str[i + 1] == character) {
            count++;
            i++;
        }

        // Append the character and its count to the compressed string
        sprintf(compressed + index, "%d%c", count, character);
        index += 2;
    }

    // Return the compressed string
    return compressed;
}

// Function to decompress a string
char *decompressString(char *str) {
    // Initialize the decompressed string
    char *decompressed = malloc(sizeof(char) * (strlen(str) + 1));

    // Initialize the index of the decompressed string
    int index = 0;

    // Iterate over the characters in the compressed string
    for (int i = 0; i < strlen(str); i++) {
        // Get the count of the current character
        int count = str[i] - '0';

        // Get the current character
        char character = str[i + 1];

        // Append the character to the decompressed string the specified number of times
        for (int j = 0; j < count; j++) {
            decompressed[index] = character;
            index++;
        }

        // Skip to the next character in the compressed string
        i++;
    }

    // Return the decompressed string
    return decompressed;
}

// Main function
int main() {
    // Get the input string from the user
    printf("Enter a string to compress: ");
    char *input = malloc(sizeof(char) * 100);
    scanf("%s", input);

    // Compress the string
    char *compressed = compressString(input);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed);

    // Decompress the string
    char *decompressed = decompressString(compressed);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    // Free the allocated memory
    free(input);
    free(compressed);
    free(decompressed);

    return 0;
}