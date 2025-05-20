//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0xAB  // Simple key for XOR operation
#define BUFFER_SIZE 512

// Function declarations
void encryptFile(const char *inputFile, const char *outputFile);
void decryptFile(const char *inputFile, const char *outputFile);
void processFile(const char *inputFile, const char *outputFile, int mode);

int main() {
    int choice;
    char inputFile[256], outputFile[256];

    printf("Welcome to Peaceful File Encryptor!\n");
    printf("1. Encrypt a File\n");
    printf("2. Decrypt a File\n");
    printf("3. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the name of the file to encrypt: ");
                scanf("%s", inputFile);
                printf("Enter the name of the output file: ");
                scanf("%s", outputFile);
                encryptFile(inputFile, outputFile);
                break;

            case 2:
                printf("Enter the name of the file to decrypt: ");
                scanf("%s", inputFile);
                printf("Enter the name of the output file: ");
                scanf("%s", outputFile);
                decryptFile(inputFile, outputFile);
                break;

            case 3:
                printf("Thank you for using the Peaceful File Encryptor. Goodbye!\n");
                exit(0);
            
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

// Function to encrypt the contents of a file
void encryptFile(const char *inputFile, const char *outputFile) {
    printf("Encrypting file: %s\n", inputFile);
    processFile(inputFile, outputFile, 1);
    printf("Encryption completed. Output saved to: %s\n", outputFile);
}

// Function to decrypt the contents of a file
void decryptFile(const char *inputFile, const char *outputFile) {
    printf("Decrypting file: %s\n", inputFile);
    processFile(inputFile, outputFile, 0);
    printf("Decryption completed. Output saved to: %s\n", outputFile);
}

// Function to process the file for encryption or decryption
void processFile(const char *inputFile, const char *outputFile, int mode) {
    FILE *input = fopen(inputFile, "rb");
    FILE *output = fopen(outputFile, "wb");

    if (!input) {
        perror("Error opening input file");
        return;
    }
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return;
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, input)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= KEY;  // XOR operation for encryption/decryption
        }
        fwrite(buffer, 1, bytesRead, output);
    }

    fclose(input);
    fclose(output);
}