//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the encryption key
#define KEY "MyEncryptionKey"

// Function to encrypt the file
int encryptFile(FILE *inputFile, FILE *outputFile) {
    char ch;
    int count = 0;

    // Loop through each character in the input file
    while ((ch = fgetc(inputFile))!= EOF) {
        // Encrypt the character using the encryption key
        ch = ch ^ KEY[count++ % strlen(KEY)];

        // Write the encrypted character to the output file
        fputc(ch, outputFile);
    }

    return 0;
}

// Function to decrypt the file
int decryptFile(FILE *inputFile, FILE *outputFile) {
    char ch;
    int count = 0;

    // Loop through each character in the input file
    while ((ch = fgetc(inputFile))!= EOF) {
        // Decrypt the character using the encryption key
        ch = ch ^ KEY[count++ % strlen(KEY)];

        // Write the decrypted character to the output file
        fputc(ch, outputFile);
    }

    return 0;
}

int main() {
    char inputFileName[100];
    char outputFileName[100];
    FILE *inputFile;
    FILE *outputFile;

    // Get the input file name from the user
    printf("Enter the input file name: ");
    scanf("%s", inputFileName);

    // Open the input file in read mode
    inputFile = fopen(inputFileName, "rb");

    // Check if the input file is opened successfully
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Get the output file name from the user
    printf("Enter the output file name: ");
    scanf("%s", outputFileName);

    // Open the output file in write mode
    outputFile = fopen(outputFileName, "wb");

    // Check if the output file is opened successfully
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Encrypt the input file and write the result to the output file
    encryptFile(inputFile, outputFile);

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    // Print success message
    printf("File encrypted successfully.\n");

    return 0;
}