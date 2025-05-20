//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input string
#define MAX_INPUT_SIZE 1024

// Function to compress a string using LZW algorithm
char *compress(char *input) {
    // Create a dictionary to store the codes for each unique substring
    int dictionary_size = 256;
    char **dictionary = malloc(sizeof(char *) * dictionary_size);
    for (int i = 0; i < dictionary_size; i++) {
        dictionary[i] = malloc(sizeof(char) * 2);
        dictionary[i][0] = i;
        dictionary[i][1] = '\0';
    }

    // Create an output buffer to store the compressed string
    int output_size = 0;
    char *output = malloc(sizeof(char) * MAX_INPUT_SIZE);

    // Initialize the code for the current substring to 256 (the code for the empty string)
    int code = 256;

    // Iterate over the input string
    int i = 0;
    while (input[i] != '\0') {
        // Find the longest substring that is already in the dictionary
        int j = 0;
        while (j < dictionary_size && strncmp(input + i, dictionary[j], j + 1) != 0) {
            j++;
        }

        // If the substring is in the dictionary, output its code
        if (j < dictionary_size) {
            output[output_size++] = j;
        } else {
            // If the substring is not in the dictionary, add it to the dictionary and output its code
            dictionary[code++] = malloc(sizeof(char) * (j + 2));
            strncpy(dictionary[code - 1], input + i, j + 1);
            dictionary[code - 1][j + 1] = '\0';
            output[output_size++] = code - 1;
        }

        // Increment the index of the input string
        i += j;
    }

    // Free the dictionary
    for (int i = 0; i < dictionary_size; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    // Return the compressed string
    return output;
}

// Function to decompress a compressed string using LZW algorithm
char *decompress(char *input) {
    // Create a dictionary to store the codes for each unique substring
    int dictionary_size = 256;
    char **dictionary = malloc(sizeof(char *) * dictionary_size);
    for (int i = 0; i < dictionary_size; i++) {
        dictionary[i] = malloc(sizeof(char) * 2);
        dictionary[i][0] = i;
        dictionary[i][1] = '\0';
    }

    // Create an output buffer to store the decompressed string
    int output_size = 0;
    char *output = malloc(sizeof(char) * MAX_INPUT_SIZE);

    // Initialize the code for the current substring to 256 (the code for the empty string)
    int code = 256;

    // Iterate over the input string
    int i = 0;
    while (input[i] != '\0') {
        // Get the code for the current substring
        int code = input[i++];

        // If the code is in the dictionary, output the corresponding substring
        if (code < dictionary_size) {
            strcat(output, dictionary[code]);
        } else {
            // If the code is not in the dictionary, add the previous substring plus the first character of the current substring to the dictionary and output the result
            char *substring = malloc(sizeof(char) * (strlen(dictionary[code - 1]) + 2));
            strcpy(substring, dictionary[code - 1]);
            substring[strlen(dictionary[code - 1])] = input[i - 1];
            substring[strlen(dictionary[code - 1]) + 1] = '\0';
            strcat(output, substring);
            dictionary[code++] = substring;
        }
    }

    // Free the dictionary
    for (int i = 0; i < dictionary_size; i++) {
        free(dictionary[i]);
    }
    free(dictionary);

    // Return the decompressed string
    return output;
}

// Main function
int main() {
    // Get the input string from the user
    char input[MAX_INPUT_SIZE];
    printf("Enter the string to be compressed: ");
    scanf("%s", input);

    // Compress the input string
    char *compressed_string = compress(input);

    // Print the compressed string
    printf("Compressed string: %s\n", compressed_string);

    // Decompress the compressed string
    char *decompressed_string = decompress(compressed_string);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressed_string);

    return 0;
}