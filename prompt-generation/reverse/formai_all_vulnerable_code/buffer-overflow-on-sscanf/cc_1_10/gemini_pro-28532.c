//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

// Function to compress the string using Lempel-Ziv-Welch (LZW) algorithm
char *compress(char *input) {
    // Create a dictionary to store the compressed data
    char dictionary[MAX_INPUT_SIZE][MAX_INPUT_SIZE];
    int dictionary_size = 0;

    // Iterate over the input string
    int i = 0;
    char *compressed = malloc(sizeof(char) * MAX_INPUT_SIZE);
    int compressed_size = 0;
    while (input[i] != '\0') {
        // Check if the current string is already in the dictionary
        int j;
        for (j = 0; j < dictionary_size; j++) {
            if (strcmp(input + i, dictionary[j]) == 0) {
                break;
            }
        }

        // If the current string is not in the dictionary, add it and output its index
        if (j == dictionary_size) {
            strcpy(dictionary[dictionary_size], input + i);
            dictionary_size++;
            sprintf(compressed + compressed_size, "%d ", dictionary_size);
            compressed_size += strlen(compressed + compressed_size);
        }

        // Output the index of the current string in the dictionary
        else {
            sprintf(compressed + compressed_size, "%d ", j);
            compressed_size += strlen(compressed + compressed_size);
        }

        // Increment the index
        i++;
    }

    // Return the compressed string
    return compressed;
}

// Function to decompress the string using Lempel-Ziv-Welch (LZW) algorithm
char *decompress(char *compressed) {
    // Create a dictionary to store the decompressed data
    char dictionary[MAX_INPUT_SIZE][MAX_INPUT_SIZE];
    int dictionary_size = 0;

    // Iterate over the compressed string
    int i = 0;
    int index;
    char *decompressed = malloc(sizeof(char) * MAX_INPUT_SIZE);
    int decompressed_size = 0;
    while (compressed[i] != '\0') {
        // Read the index from the compressed string
        sscanf(compressed + i, "%d ", &index);

        // Append the corresponding string from the dictionary to the decompressed string
        if (index == dictionary_size) {
            strcat(decompressed, compressed + i + strlen(compressed + i) + 1);
            decompressed_size += strlen(decompressed + decompressed_size);
        }
        else {
            strcat(decompressed, dictionary[index]);
            decompressed_size += strlen(decompressed + decompressed_size);
        }

        // Add the current string to the dictionary
        strcpy(dictionary[dictionary_size], dictionary[index]);
        strcat(dictionary[dictionary_size], compressed + i + strlen(compressed + i) + 1);
        dictionary_size++;

        // Increment the index
        i += strlen(compressed + i) + 1;
    }

    // Return the decompressed string
    return decompressed;
}

int main() {
    // Get the input string from the user
    char input[MAX_INPUT_SIZE];
    printf("Enter the string to be compressed: ");
    gets(input);

    // Compress the input string
    char *compressed = compress(input);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed);

    // Decompress the compressed string
    char *decompressed = decompress(compressed);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}