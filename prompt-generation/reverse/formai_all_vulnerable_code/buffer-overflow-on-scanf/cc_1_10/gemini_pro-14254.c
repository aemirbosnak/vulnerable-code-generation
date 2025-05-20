//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input string
#define MAX_INPUT_SIZE 1024

// Define the maximum size of the compressed string
#define MAX_COMPRESSED_SIZE 1024

// Function to compress a string using Lempel-Ziv-Welch (LZW) algorithm
int compress(char *input, char *compressed) {
    // Create a dictionary to store the codes for each substring
    char dictionary[4096][256];
    int dictionary_size = 0;

    // Initialize the compressed string
    int compressed_length = 0;

    // Iterate over the input string
    int i = 0;
    while (input[i] != '\0') {
        // Check if the current substring is already in the dictionary
        int found = 0;
        for (int j = 0; j < dictionary_size; j++) {
            if (strcmp(dictionary[j], input + i) == 0) {
                // If the substring is found, add its code to the compressed string
                compressed[compressed_length++] = j;
                found = 1;
                break;
            }
        }

        // If the substring is not found, add it to the dictionary and add its code to the compressed string
        if (!found) {
            strcpy(dictionary[dictionary_size++], input + i);
            compressed[compressed_length++] = dictionary_size - 1;
        }

        // Increment the index of the input string
        i++;
    }

    // Return the length of the compressed string
    return compressed_length;
}

// Function to decompress a string using LZW algorithm
int decompress(char *compressed, char *decompressed) {
    // Create a dictionary to store the substrings for each code
    char dictionary[4096][256];
    int dictionary_size = 0;

    // Initialize the decompressed string
    int decompressed_length = 0;

    // Iterate over the compressed string
    int i = 0;
    while (i < strlen(compressed)) {
        // Get the code from the compressed string
        int code = compressed[i++];

        // If the code is less than the dictionary size, add the corresponding substring to the decompressed string
        if (code < dictionary_size) {
            strcat(decompressed, dictionary[code]);
        } else {
            // If the code is not in the dictionary, add the last character of the decompressed string to itself
            strcat(decompressed, decompressed + decompressed_length - 1);
        }

        // Add the current substring to the dictionary
        strcpy(dictionary[dictionary_size++], decompressed + decompressed_length - 1);

        // Increment the index of the decompressed string
        decompressed_length += strlen(decompressed + decompressed_length - 1);
    }

    // Return the length of the decompressed string
    return decompressed_length;
}

// Main function
int main() {
    // Get the input string from the user
    char input[MAX_INPUT_SIZE];
    printf("Enter the string to be compressed: ");
    scanf("%s", input);

    // Compress the input string
    char compressed[MAX_COMPRESSED_SIZE];
    int compressed_length = compress(input, compressed);

    // Print the compressed string
    printf("Compressed string: ");
    for (int i = 0; i < compressed_length; i++) {
        printf("%c", compressed[i]);
    }
    printf("\n");

    // Decompress the compressed string
    char decompressed[MAX_INPUT_SIZE];
    int decompressed_length = decompress(compressed, decompressed);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}