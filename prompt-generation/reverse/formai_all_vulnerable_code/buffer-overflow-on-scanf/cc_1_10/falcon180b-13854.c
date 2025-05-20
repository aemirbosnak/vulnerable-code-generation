//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key used for encryption
#define KEY "MySecretKey"

// Function to encrypt a file
void encryptFile(FILE *inputFile, FILE *outputFile) {
    char ch;
    while ((ch = fgetc(inputFile))!= EOF) {
        ch ^= KEY[0];
        for (int i = 1; i < strlen(KEY); i++) {
            ch = ch ^ KEY[i];
        }
        fputc(ch, outputFile);
    }
}

// Function to decrypt a file
void decryptFile(FILE *inputFile, FILE *outputFile) {
    char ch;
    while ((ch = fgetc(inputFile))!= EOF) {
        ch ^= KEY[0];
        for (int i = 1; i < strlen(KEY); i++) {
            ch = ch ^ KEY[i];
        }
        fputc(ch, outputFile);
    }
}

int main() {
    char inputFileName[100];
    char outputFileName[100];

    // Get input file name from user
    printf("Enter the name of the input file: ");
    scanf("%s", inputFileName);

    // Get output file name from user
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);

    // Open input file
    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Error: Input file not found.\n");
        exit(1);
    }

    // Open output file
    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Error: Output file not found.\n");
        exit(1);
    }

    // Encrypt the file
    encryptFile(inputFile, outputFile);

    // Close input and output files
    fclose(inputFile);
    fclose(outputFile);

    printf("File encryption completed successfully!\n");

    return 0;
}