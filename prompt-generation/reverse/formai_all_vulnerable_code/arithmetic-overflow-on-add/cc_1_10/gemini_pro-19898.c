//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt a character
char encrypt(char c, int key) {
    return (c + key) % 128;
}

// Function to decrypt a character
char decrypt(char c, int key) {
    return (c - key) % 128;
}

// Function to encrypt a file
void encryptFile(FILE *inputFile, FILE *outputFile, int key) {
    char c;
    while ((c = getc(inputFile)) != EOF) {
        putc(encrypt(c, key), outputFile);
    }
}

// Function to decrypt a file
void decryptFile(FILE *inputFile, FILE *outputFile, int key) {
    char c;
    while ((c = getc(inputFile)) != EOF) {
        putc(decrypt(c, key), outputFile);
    }
}

int main() {
    // Get the input and output file names
    char inputFileName[256];
    char outputFileName[256];
    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    // Get the encryption key
    int key;
    printf("Enter the encryption key (0-127): ");
    scanf("%d", &key);

    // Open the input and output files
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    // Encrypt the file
    encryptFile(inputFile, outputFile, key);

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    // Print a success message
    printf("File encrypted successfully!\n");

    return 0;
}