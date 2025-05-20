//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size in bytes

// Function to encrypt the file contents
void encryptFile(FILE *inputFile, FILE *outputFile) {
    char buffer[1024]; // Buffer to store file contents
    int bufferIndex = 0; // Index to keep track of buffer position
    int fileIndex = 0; // Index to keep track of file position
    int fileSize = 0; // Size of the file in bytes
    char key = 'k'; // Encryption key

    // Read file size
    fseek(inputFile, 0, SEEK_END);
    fileSize = ftell(inputFile);
    rewind(inputFile);

    // Encrypt file contents
    while ((fileIndex < fileSize) && (bufferIndex < MAX_FILE_SIZE)) {
        fgets(buffer + bufferIndex, 1024 - bufferIndex, inputFile);
        fileIndex += strlen(buffer + bufferIndex);
        bufferIndex += strlen(buffer + bufferIndex);

        // Encrypt buffer contents
        for (int i = 0; i < bufferIndex; i++) {
            buffer[i] ^= key;
        }

        // Write encrypted buffer to output file
        fwrite(buffer, bufferIndex, 1, outputFile);
        bufferIndex = 0;
    }

    // Close files
    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];

    // Get input and output file names
    printf("Enter input file name: ");
    scanf("%s", inputFileName);
    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    // Open input and output files
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        exit(1);
    }

    // Encrypt file
    encryptFile(inputFile, outputFile);

    printf("File encryption successful!\n");

    return 0;
}