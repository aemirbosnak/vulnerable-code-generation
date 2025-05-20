//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string using run-length encoding
char *compress(char *str) {
    int i, j, count;
    char *compressed;

    // Allocate memory for the compressed string
    compressed = malloc(strlen(str) + 1);

    // Initialize the compressed string
    compressed[0] = '\0';

    // Iterate over the input string
    for (i = 0; str[i] != '\0'; i++) {
        // Count the number of consecutive occurrences of the current character
        count = 1;
        while (str[i] == str[i + 1]) {
            count++;
            i++;
        }

        // If the count is greater than 1, append the character and the count to the compressed string
        if (count > 1) {
            sprintf(compressed, "%s%c%d", compressed, str[i], count);
        }
        // Otherwise, append the character to the compressed string
        else {
            sprintf(compressed, "%s%c", compressed, str[i]);
        }
    }

    // Return the compressed string
    return compressed;
}

// Function to decompress a string that was compressed using run-length encoding
char *decompress(char *str) {
    int i, j, count;
    char *decompressed;

    // Allocate memory for the decompressed string
    decompressed = malloc(strlen(str) + 1);

    // Initialize the decompressed string
    decompressed[0] = '\0';

    // Iterate over the compressed string
    for (i = 0; str[i] != '\0'; i++) {
        // If the current character is a digit, it represents the count of the following character
        if (str[i] >= '0' && str[i] <= '9') {
            count = str[i] - '0';
            i++;
        }
        // Otherwise, the current character is a character that is repeated count times
        else {
            count = 1;
        }

        // Append the character to the decompressed string count times
        for (j = 0; j < count; j++) {
            sprintf(decompressed, "%s%c", decompressed, str[i]);
        }
    }

    // Return the decompressed string
    return decompressed;
}

int main() {
    char *str, *compressed, *decompressed;

    // Get the input string from the user
    printf("Enter a string to compress: ");
    str = malloc(100);
    scanf("%s", str);

    // Compress the string
    compressed = compress(str);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed);

    // Decompress the string
    decompressed = decompress(compressed);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    // Free the allocated memory
    free(str);
    free(compressed);
    free(decompressed);

    return 0;
}