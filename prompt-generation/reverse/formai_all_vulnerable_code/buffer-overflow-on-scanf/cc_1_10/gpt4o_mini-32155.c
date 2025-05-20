//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

// Function to compress data using RLE
void compressRLE(FILE *inputFile, FILE *outputFile) {
    char currentChar;
    int count;

    while ((currentChar = fgetc(inputFile)) != EOF) {
        count = 1;

        // Count occurrences of the current character
        while ((currentChar == fgetc(inputFile)) && count < 255) {
            count++;
        }

        // Write the character and its count to the output file
        fputc(currentChar, outputFile);
        fputc(count, outputFile);
        
        // If we hit end of file, break
        if (currentChar == EOF) {
            break;
        }
        
        // Move back one character in the input stream
        ungetc(currentChar, inputFile);
    }
}

// Function to decompress data from RLE
void decompressRLE(FILE *inputFile, FILE *outputFile) {
    char currentChar;
    int count;

    while ((currentChar = fgetc(inputFile)) != EOF) {
        count = fgetc(inputFile);
        
        // Write the character 'count' times
        for (int i = 0; i < count; i++) {
            fputc(currentChar, outputFile);
        }
    }
}

// Function to get the file name from user input
void getFileName(char *prompt, char *fileName) {
    printf("%s: ", prompt);
    scanf("%s", fileName);
}

// Main function
int main() {
    char inputFileName[MAX_LINE_LENGTH];
    char compressedFileName[MAX_LINE_LENGTH];
    char decompressedFileName[MAX_LINE_LENGTH];

    // Get input file name from the user
    getFileName("Enter the name of the file to compress", inputFileName);
    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    // Get output compressed file name from the user
    getFileName("Enter the name of the compressed output file", compressedFileName);
    FILE *outputFile = fopen(compressedFileName, "wb");
    if (outputFile == NULL) {
        perror("Error opening output compressed file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    // Perform compression
    compressRLE(inputFile, outputFile);
    printf("Compression complete. Compressed file created: %s\n", compressedFileName);

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    // Get decompressed file name from the user
    getFileName("Enter the name of the output file after decompression", decompressedFileName);
    outputFile = fopen(decompressedFileName, "wb");
    if (outputFile == NULL) {
        perror("Error opening output decompressed file");
        return EXIT_FAILURE;
    }

    // Reopen the compressed file for reading
    inputFile = fopen(compressedFileName, "rb");
    if (inputFile == NULL) {
        perror("Error reopening compressed file");
        fclose(outputFile);
        return EXIT_FAILURE;
    }

    // Perform decompression
    decompressRLE(inputFile, outputFile);
    printf("Decompression complete. Decompressed file created: %s\n", decompressedFileName);

    // Close files
    fclose(inputFile);
    fclose(outputFile);

    return EXIT_SUCCESS;
}