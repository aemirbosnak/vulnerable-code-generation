//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024 * 1024 * 100 // 100MB

// Function to encrypt the file
void encryptFile(FILE *inputFile, FILE *outputFile, char *key) {
    char buffer[MAX_FILE_SIZE];
    int bufferSize = 0;

    while (fgets(buffer, MAX_FILE_SIZE, inputFile)!= NULL) {
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] = buffer[i] ^ key[i % strlen(key)];
        }
        fwrite(buffer, strlen(buffer), 1, outputFile);
        bufferSize += strlen(buffer);
    }

    printf("Encrypted file size: %d bytes\n", bufferSize);
}

// Function to decrypt the file
void decryptFile(FILE *inputFile, FILE *outputFile, char *key) {
    char buffer[MAX_FILE_SIZE];
    int bufferSize = 0;

    while (fread(buffer, 1, MAX_FILE_SIZE, inputFile)!= 0) {
        for (int i = 0; i < strlen(buffer); i++) {
            buffer[i] = buffer[i] ^ key[i % strlen(key)];
        }
        fwrite(buffer, strlen(buffer), 1, outputFile);
        bufferSize += strlen(buffer);
    }

    printf("Decrypted file size: %d bytes\n", bufferSize);
}

int main() {
    char inputFileName[100];
    char outputFileName[100];
    char key[100];

    // Get input file name
    printf("Enter input file name: ");
    scanf("%s", inputFileName);

    // Get output file name
    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    // Get encryption key
    printf("Enter encryption key: ");
    scanf("%s", key);

    // Open input and output files
    FILE *inputFile = fopen(inputFileName, "rb");
    FILE *outputFile = fopen(outputFileName, "wb");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    // Encrypt the file
    encryptFile(inputFile, outputFile, key);

    // Close input and output files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}