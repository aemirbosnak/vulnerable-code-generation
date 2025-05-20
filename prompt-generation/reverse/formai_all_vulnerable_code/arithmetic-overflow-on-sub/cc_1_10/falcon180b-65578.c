//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to encrypt the file
void encryptFile(FILE *input, FILE *output, int key) {
    char c;
    while ((c = fgetc(input))!= EOF) {
        c = (char) ((c + key - 65) % 26 + 65);
        fputc(c, output);
    }
}

// Function to decrypt the file
void decryptFile(FILE *input, FILE *output, int key) {
    char c;
    while ((c = fgetc(input))!= EOF) {
        c = (char) ((c - key - 65) % 26 + 65);
        fputc(c, output);
    }
}

int main() {
    char inputFileName[100], outputFileName[100];
    FILE *inputFile, *outputFile;
    int key;

    // Get the input file name
    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);

    // Open the input file for reading
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Get the output file name
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    // Open the output file for writing
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(inputFile);
        exit(1);
    }

    // Get the encryption/decryption key
    printf("Enter the encryption/decryption key: ");
    scanf("%d", &key);

    // Encrypt or decrypt the file based on user choice
    char choice;
    printf("Enter 'e' to encrypt or 'd' to decrypt: ");
    scanf(" %c", &choice);

    if (choice == 'e' || choice == 'E') {
        encryptFile(inputFile, outputFile, key);
    } else if (choice == 'd' || choice == 'D') {
        decryptFile(inputFile, outputFile, key);
    } else {
        printf("Invalid choice.\n");
        fclose(inputFile);
        fclose(outputFile);
        exit(1);
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    printf("File encryption/decryption completed successfully.\n");

    return 0;
}