//Falcon-180B DATASET v1.0 Category: Compression algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_CODE 4096

// Function to compress the given string
void compress(char* input, char* output) {
    int i = 0, j = 0, k = 0;
    char code[MAX_CODE];
    memset(code, 0, MAX_CODE);

    // Initialize the code table
    for (i = 0; i < 256; i++) {
        code[i] = 1;
    }

    // Build the code table
    for (i = 0; i < strlen(input); i++) {
        if (code[input[i]] == 0) {
            strcat(code, &input[i]);
        }
    }

    // Compress the input string
    for (i = 0; i < strlen(input); i++) {
        for (j = 0; j < strlen(code); j++) {
            if (input[i] == code[j]) {
                output[k++] = j;
                break;
            }
        }
    }
}

// Function to decompress the compressed string
void decompress(char* input, char* output) {
    int i = 0, j = 0, k = 0;
    char code[MAX_CODE];
    memset(code, 0, MAX_CODE);

    // Initialize the code table
    for (i = 0; i < 256; i++) {
        code[i] = 1;
    }

    // Build the code table
    for (i = 0; i < strlen(input); i++) {
        if (code[input[i]] == 0) {
            strcat(code, &input[i]);
        }
    }

    // Decompress the input string
    for (i = 0; i < strlen(input); i++) {
        output[k++] = code[input[i]];
    }
}

int main() {
    char input[MAX_LENGTH], output[MAX_LENGTH];

    // Get the input string from the user
    printf("Enter the string to compress: ");
    scanf("%s", input);

    // Compress the input string
    compress(input, output);

    // Print the compressed string
    printf("Compressed string: %s\n", output);

    // Decompress the compressed string
    decompress(output, input);

    // Print the decompressed string
    printf("Decompressed string: %s\n", input);

    return 0;
}