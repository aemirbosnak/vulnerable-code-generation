//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum size of the input string
#define MAX_SIZE 100

// Function to compress a string
char *compress(char *str) {
    // Create a new string to store the compressed string
    char *compressed = malloc(MAX_SIZE * sizeof(char));

    // Initialize the compressed string
    strcpy(compressed, "");

    // Initialize the previous character
    char prev = '\0';

    // Initialize the count of consecutive characters
    int count = 0;

    // Iterate over the input string
    for (int i = 0; i < strlen(str); i++) {
        // If the current character is the same as the previous character, increment the count
        if (str[i] == prev) {
            count++;
        }
        // If the current character is different from the previous character, append the count and the character to the compressed string
        else {
            // Convert the count to a string
            char count_str[10];
            sprintf(count_str, "%d", count);

            // Append the count and the character to the compressed string
            strcat(compressed, count_str);
            strcat(compressed, &str[i]);

            // Reset the count
            count = 0;

            // Update the previous character
            prev = str[i];
        }
    }

    // Return the compressed string
    return compressed;
}

// Function to decompress a string
char *decompress(char *str) {
    // Create a new string to store the decompressed string
    char *decompressed = malloc(MAX_SIZE * sizeof(char));

    // Initialize the decompressed string
    strcpy(decompressed, "");

    // Initialize the current character
    char curr = '\0';

    // Initialize the count of consecutive characters
    int count = 0;

    // Iterate over the compressed string
    for (int i = 0; i < strlen(str); i++) {
        // If the current character is a digit, increment the count
        if (str[i] >= '0' && str[i] <= '9') {
            count = count * 10 + (str[i] - '0');
        }
        // If the current character is a letter, append the count of consecutive characters to the decompressed string
        else {
            // Append the character to the decompressed string count number of times
            for (int j = 0; j < count; j++) {
                strcat(decompressed, &curr);
            }

            // Reset the count
            count = 0;

            // Update the current character
            curr = str[i];
        }
    }

    // Return the decompressed string
    return decompressed;
}

// Driver code
int main() {
    // Get the input string
    char str[MAX_SIZE];
    printf("Enter the string to be compressed: ");
    scanf("%s", str);

    // Compress the string
    char *compressed = compress(str);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed);

    // Decompress the string
    char *decompressed = decompress(compressed);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}