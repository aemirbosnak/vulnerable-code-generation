//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256

// Function prototypes
void encryptFile(const char *inputFile, const char *outputFile, char key);
void decryptFile(const char *inputFile, const char *outputFile, char key);
void handleFileOperation(char option);

// XOR encryption and decryption.
void xorCipher(char *buffer, size_t length, char key) {
    for (size_t i = 0; i < length; i++) {
        buffer[i] ^= key; // XOR operation
    }
}

// Main function
int main() {
    char option;
    
    printf("=== C File Encryptor ===\n");
    printf("Select an option:\n");
    printf("e - Encrypt a file\n");
    printf("d - Decrypt a file\n");
    printf("q - Quit\n");
    
    while (1) {
        printf("Option: ");
        scanf(" %c", &option); // Space before %c to consume any leftover newline

        if (option == 'q') break;

        handleFileOperation(option);
    }
    
    return 0;
}

// Handle file operations based on user input
void handleFileOperation(char option) {
    char inputFile[100], outputFile[100];
    char key;

    printf("Enter the input file name: ");
    scanf("%s", inputFile);
    printf("Enter the output file name: ");
    scanf("%s", outputFile);
    printf("Enter encryption/decryption key (single character): ");
    scanf(" %c", &key); // Space before %c to consume any leftover newline

    // Perform encryption or decryption based on user input
    if (option == 'e') {
        encryptFile(inputFile, outputFile, key);
    } else if (option == 'd') {
        decryptFile(inputFile, outputFile, key);
    } else {
        printf("Invalid option!\n");
    }
}

// Encrypt the file
void encryptFile(const char *inputFile, const char *outputFile, char key) {
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");
    
    if (!inFile) {
        perror("Error opening input file");
        return;
    }
    if (!outFile) {
        perror("Error opening output file");
        fclose(inFile);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, inFile)) > 0) {
        xorCipher(buffer, bytesRead, key);
        fwrite(buffer, sizeof(char), bytesRead, outFile);
    }

    fclose(inFile);
    fclose(outFile);
    printf("File encrypted successfully!\n");
}

// Decrypt the file
void decryptFile(const char *inputFile, const char *outputFile, char key) {
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");
    
    if (!inFile) {
        perror("Error opening input file");
        return;
    }
    if (!outFile) {
        perror("Error opening output file");
        fclose(inFile);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE, inFile)) > 0) {
        xorCipher(buffer, bytesRead, key);
        fwrite(buffer, sizeof(char), bytesRead, outFile);
    }

    fclose(inFile);
    fclose(outFile);
    printf("File decrypted successfully!\n");
}