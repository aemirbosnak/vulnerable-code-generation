//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string using run-length encoding
char* compress(char* str)
{
    // Allocate memory for the compressed string
    char* compressed = malloc(sizeof(char) * strlen(str) * 2);

    // Initialize the compressed string
    int compressed_index = 0;

    // Initialize the current character and its count
    char current_char = str[0];
    int count = 1;

    // Iterate over the remaining characters in the string
    for (int i = 1; i < strlen(str); i++)
    {
        // If the current character is the same as the previous character, increment the count
        if (str[i] == current_char)
        {
            count++;
        }
        // Otherwise, add the count and character to the compressed string and reset the count
        else
        {
            compressed[compressed_index++] = count + '0';
            compressed[compressed_index++] = current_char;

            current_char = str[i];
            count = 1;
        }
    }

    // Add the count and character for the last character
    compressed[compressed_index++] = count + '0';
    compressed[compressed_index++] = current_char;

    // Null-terminate the compressed string
    compressed[compressed_index] = '\0';

    // Return the compressed string
    return compressed;
}

// Function to decompress a string compressed using run-length encoding
char* decompress(char* compressed)
{
    // Allocate memory for the decompressed string
    char* decompressed = malloc(sizeof(char) * strlen(compressed) * 2);

    // Initialize the decompressed string
    int decompressed_index = 0;

    // Iterate over the characters in the compressed string
    for (int i = 0; i < strlen(compressed); i += 2)
    {
        // Get the count and character from the compressed string
        int count = compressed[i] - '0';
        char character = compressed[i + 1];

        // Append the character to the decompressed string the specified number of times
        for (int j = 0; j < count; j++)
        {
            decompressed[decompressed_index++] = character;
        }
    }

    // Null-terminate the decompressed string
    decompressed[decompressed_index] = '\0';

    // Return the decompressed string
    return decompressed;
}

// Main function
int main()
{
    // Get the input string from the user
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