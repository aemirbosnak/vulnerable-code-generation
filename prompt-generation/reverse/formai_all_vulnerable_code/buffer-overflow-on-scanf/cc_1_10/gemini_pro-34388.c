//GEMINI-pro DATASET v1.0 Category: Compression algorithms ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom data structure to store compressed data
typedef struct {
    unsigned char *data;
    int length;
} CompressedData;

// Function to compress a string using Lempel-Ziv-Welch (LZW) algorithm
CompressedData lzw_compress(const char *input) {
    // Initialize the dictionary
    int dictionarySize = 256;
    char dictionary[dictionarySize][10];
    for (int i = 0; i < dictionarySize; i++) {
        dictionary[i][0] = (char) i;
        dictionary[i][1] = '\0';
    }

    // Initialize the output buffer
    CompressedData output;
    output.data = (unsigned char *) malloc(sizeof(unsigned char) * strlen(input));
    output.length = 0;

    // Compress the input string
    int currentCode = dictionarySize;
    char currentSequence[10] = "";
    for (int i = 0; i < strlen(input); i++) {
        char currentChar = input[i];
        strcat(currentSequence, &currentChar);

        int found = 0;
        for (int j = 0; j < dictionarySize && !found; j++) {
            if (!strcmp(currentSequence, dictionary[j])) {
                found = 1;
                currentCode = j;
            }
        }

        if (!found) {
            output.data[output.length++] = (unsigned char) currentCode;
            strcpy(dictionary[dictionarySize++], currentSequence);
            currentSequence[0] = currentChar;
            currentSequence[1] = '\0';
        }
    }

    output.data[output.length++] = (unsigned char) currentCode;

    // Return the compressed data
    return output;
}

// Function to decompress a string using LZW algorithm
char *lzw_decompress(const CompressedData *input) {
    // Initialize the dictionary
    int dictionarySize = 256;
    char dictionary[dictionarySize][10];
    for (int i = 0; i < dictionarySize; i++) {
        dictionary[i][0] = (char) i;
        dictionary[i][1] = '\0';
    }

    // Initialize the output buffer
    char *output = (char *) malloc(sizeof(char) * input->length * 2);
    int outputIndex = 0;

    // Decompress the input data
    int currentCode = input->data[0];
    char currentSequence[10];
    strcpy(currentSequence, dictionary[currentCode]);
    output[outputIndex++] = currentSequence[0];

    for (int i = 1; i < input->length; i++) {
        currentCode = input->data[i];
        char *nextSequence;
        if (currentCode < dictionarySize) {
            nextSequence = dictionary[currentCode];
        } else {
            nextSequence = (char *) malloc(sizeof(char) * (strlen(currentSequence) + 2));
            strcpy(nextSequence, currentSequence);
            strcat(nextSequence, &currentSequence[0]);
        }

        output[outputIndex++] = nextSequence[0];
        strcpy(dictionary[dictionarySize++], nextSequence);
        strcpy(currentSequence, nextSequence);
    }

    output[outputIndex] = '\0';

    // Return the decompressed string
    return output;
}

int main() {
    // Get the input string
    char input[100];
    printf("Enter the string to compress: ");
    scanf("%s", input);

    // Compress the string
    CompressedData compressedData = lzw_compress(input);

    // Print the compressed data
    printf("Compressed data:\n");
    for (int i = 0; i < compressedData.length; i++) {
        printf("%d ", compressedData.data[i]);
    }
    printf("\n");

    // Decompress the compressed data
    char *decompressedString = lzw_decompress(&compressedData);

    // Print the decompressed string
    printf("Decompressed string: %s\n", decompressedString);

    // Free the allocated memory
    free(compressedData.data);
    free(decompressedString);

    return 0;
}