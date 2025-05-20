//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY "mysecretkey"

// Function to encrypt the file
void encryptFile(FILE *inputFile, FILE *outputFile) {
    char ch;
    while ((ch = fgetc(inputFile))!= EOF) {
        ch ^= KEY[0];
        for (int i = 0; i < strlen(KEY) - 1; i++) {
            ch ^= KEY[i];
        }
        fputc(ch, outputFile);
    }
}

// Function to decrypt the file
void decryptFile(FILE *inputFile, FILE *outputFile) {
    char ch;
    while ((ch = fgetc(inputFile))!= EOF) {
        ch ^= KEY[0];
        for (int i = 0; i < strlen(KEY) - 1; i++) {
            ch ^= KEY[i];
        }
        fputc(ch, outputFile);
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[100], outputFileName[100];

    printf("Enter input file name: ");
    scanf("%s", inputFileName);
    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    // Open input and output files
    inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }
    outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Encrypt the file
    encryptFile(inputFile, outputFile);

    // Close input and output files
    fclose(inputFile);
    fclose(outputFile);

    printf("File encrypted successfully!\n");
    return 0;
}