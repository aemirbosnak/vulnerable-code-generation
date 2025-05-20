//Code Llama-13B DATASET v1.0 Category: Compression algorithms ; Style: peaceful
// Unique C Compression Algorithm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the input string
#define MAX_INPUT_LEN 1000

// Define the maximum length of the output string
#define MAX_OUTPUT_LEN 1000

// Function to compress the input string
char* compress(char* input) {
    // Create a new string to store the compressed data
    char* output = (char*)malloc(sizeof(char) * MAX_OUTPUT_LEN);
    // Initialize the compressed data string to an empty string
    strcpy(output, "");
    // Loop through each character in the input string
    for (int i = 0; i < strlen(input); i++) {
        // Check if the character is a letter
        if (isalpha(input[i])) {
            // If the character is a letter, add it to the compressed data
            strncat(output, &input[i], 1);
        } else {
            // If the character is not a letter, add a space to the compressed data
            strncat(output, " ", 1);
        }
    }
    // Return the compressed data
    return output;
}

// Function to decompress the input string
char* decompress(char* input) {
    // Create a new string to store the decompressed data
    char* output = (char*)malloc(sizeof(char) * MAX_OUTPUT_LEN);
    // Initialize the decompressed data string to an empty string
    strcpy(output, "");
    // Loop through each character in the input string
    for (int i = 0; i < strlen(input); i++) {
        // Check if the character is a space
        if (input[i] == ' ') {
            // If the character is a space, add a space to the decompressed data
            strncat(output, " ", 1);
        } else {
            // If the character is not a space, add the previous character to the decompressed data
            strncat(output, &input[i - 1], 1);
        }
    }
    // Return the decompressed data
    return output;
}

int main() {
    // Prompt the user for input
    char input[MAX_INPUT_LEN];
    printf("Enter a string to compress: ");
    fgets(input, MAX_INPUT_LEN, stdin);
    // Compress the input string
    char* compressed = compress(input);
    printf("Compressed string: %s\n", compressed);
    // Decompress the compressed string
    char* decompressed = decompress(compressed);
    printf("Decompressed string: %s\n", decompressed);
    // Free the memory allocated for the compressed and decompressed strings
    free(compressed);
    free(decompressed);
    return 0;
}