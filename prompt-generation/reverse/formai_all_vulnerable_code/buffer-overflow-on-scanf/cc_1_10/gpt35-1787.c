//FormAI DATASET v1.0 Category: Compression algorithms ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the maximum length of a string
#define MAX_LENGTH 1000

// structure for a compressed element
struct CompressedElement {
    char value;
    int count;
};

// function to compress the input string using RLE compression
char* RLECompress(char* input) {
    // allocate memory for the output string
    char* output = (char*) malloc(2 * MAX_LENGTH * sizeof(char));
    memset(output, 0, 2 * MAX_LENGTH * sizeof(char));
    
    // initialize the compressed element array
    struct CompressedElement compressed[MAX_LENGTH];
    memset(compressed, 0, MAX_LENGTH * sizeof(struct CompressedElement));
    
    // initialize the index variables
    int inputIndex = 0;
    int outputIndex = 0;
    int compressedIndex = 0;
    
    // loop through the input string
    while (input[inputIndex] != '\0') {
        // get the current character and count
        char currentChar = input[inputIndex];
        int currentCount = 1;
        
        // loop through the string to count the number of consecutive characters
        while (input[++inputIndex] == currentChar) {
            currentCount++;
        }
        
        // add the compressed element to the array
        compressed[compressedIndex].value = currentChar;
        compressed[compressedIndex].count = currentCount;
        compressedIndex++;
    }
    
    // loop through the compressed element array and add the compressed data to the output string
    for (int i = 0; i < compressedIndex; i++) {
        // add the compressed element to the output string
        output[outputIndex++] = compressed[i].value;
        output[outputIndex++] = (char) compressed[i].count;
    }
    
    // add the null terminator to the output string
    output[outputIndex] = '\0';
    
    // return the compressed data
    return output;
}

// function to decompress the RLE compressed string
char* RLEDecompress(char* input) {
    // allocate memory for the output string
    char* output = (char*) malloc(MAX_LENGTH * sizeof(char));
    memset(output, 0, MAX_LENGTH * sizeof(char));
    
    // initialize the index variables
    int inputIndex = 0;
    int outputIndex = 0;
    
    // loop through the compressed string
    while (input[inputIndex] != '\0') {
        // get the current character and count
        char currentChar = input[inputIndex++];
        int currentCount = (int) input[inputIndex++];
        
        // loop through the string to add the decompressed characters to the output string
        for (int i = 0; i < currentCount; i++) {
            output[outputIndex++] = currentChar;
        }
    }
    
    // add the null terminator to the output string
    output[outputIndex] = '\0';
    
    // return the decompressed string
    return output;
}

// main function
int main(void) {
    // initialize the input string
    char input[MAX_LENGTH];
    memset(input, 0, MAX_LENGTH * sizeof(char));
    
    // get the input string from the user
    printf("Enter a string to compress: ");
    scanf("%s", input);
    
    // compress and output the compressed string
    char* compressed = RLECompress(input);
    printf("Compressed String: %s\n", compressed);
    
    // decompress and output the decompressed string
    char* decompressed = RLEDecompress(compressed);
    printf("Decompressed String: %s\n", decompressed);
    
    // free memory
    free(compressed);
    free(decompressed);
    
    return 0;
}