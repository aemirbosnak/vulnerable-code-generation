//FormAI DATASET v1.0 Category: File Encyptor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000 // Maximum file size that can be encrypted

// Function to encrypt a file
void encryptFile(char* inputFile, char* outputFile, char* key) {
    FILE* inputFilePointer, * outputFilePointer;
    char byte, keyByte;
    long count = 0;

    inputFilePointer = fopen(inputFile, "rb");
    outputFilePointer = fopen(outputFile, "wb");

    // Check if files were opened successfully
    if(inputFilePointer == NULL || outputFilePointer == NULL) {
        printf("Error: Unable to open files.");
        exit(1);
    }

    // Encrypt each byte of the file
    while(!feof(inputFilePointer)) {
        byte = getc(inputFilePointer);
        keyByte = key[count % strlen(key)];
        byte = byte ^ keyByte; // Perform XOR operation
        putc(byte, outputFilePointer);
        count++;
    }

    fclose(inputFilePointer);
    fclose(outputFilePointer);

    printf("File encrypted successfully.\n");
}

// Function to decrypt a file
void decryptFile(char* inputFile, char* outputFile, char* key) {
    FILE* inputFilePointer, * outputFilePointer;
    char byte, keyByte;
    long count = 0;

    inputFilePointer = fopen(inputFile, "rb");
    outputFilePointer = fopen(outputFile, "wb");

    // Check if files were opened successfully
    if(inputFilePointer == NULL || outputFilePointer == NULL) {
        printf("Error: Unable to open files.");
        exit(1);
    }

    // Decrypt each byte of the file
    while(!feof(inputFilePointer)) {
        byte = getc(inputFilePointer);
        keyByte = key[count % strlen(key)];
        byte = byte ^ keyByte; // Perform XOR operation
        putc(byte, outputFilePointer);
        count++;
    }

    fclose(inputFilePointer);
    fclose(outputFilePointer);

    printf("File decrypted successfully.\n");
}

int main() {
    char option, inputFile[100], outputFile[100], key[100];

    printf("Select an option:\n1. Encrypt file\n2. Decrypt file\n");
    scanf("%c", &option);
    fflush(stdin); // Clear input buffer

    if(option == '1') {
        printf("Enter the name of the file to be encrypted: ");
        gets(inputFile);
        printf("Enter the name of the encrypted file: ");
        gets(outputFile);
        printf("Enter the encryption key: ");
        gets(key);

        encryptFile(inputFile, outputFile, key);
    }
    else if(option == '2') {
        printf("Enter the name of the file to be decrypted: ");
        gets(inputFile);
        printf("Enter the name of the decrypted file: ");
        gets(outputFile);
        printf("Enter the decryption key: ");
        gets(key);

        decryptFile(inputFile, outputFile, key);
    }
    else {
        printf("Invalid option selected.");
    }

    return 0;
}