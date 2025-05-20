//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void xorCipher(const char *inputBuffer, char *outputBuffer, const char *key, size_t length) {
    size_t keyLength = strlen(key);
    for (size_t i = 0; i < length; ++i) {
        outputBuffer[i] = inputBuffer[i] ^ key[i % keyLength];
    }
}

void encryptFile(const char *inputFilePath, const char *outputFilePath, const char *key) {
    FILE *inputFile = fopen(inputFilePath, "rb");
    if (!inputFile) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFilePath, "wb");
    if (!outputFile) {
        fclose(inputFile);
        perror("Failed to open output file");
        exit(EXIT_FAILURE);
    }

    char inputBuffer[BUFFER_SIZE];
    char outputBuffer[BUFFER_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(inputBuffer, 1, BUFFER_SIZE, inputFile)) > 0) {
        xorCipher(inputBuffer, outputBuffer, key, bytesRead);
        fwrite(outputBuffer, 1, bytesRead, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void decryptFile(const char *inputFilePath, const char *outputFilePath, const char *key) {
    // Decryption is the same as encryption for XOR
    encryptFile(inputFilePath, outputFilePath, key);
}

int main() {
    char inputFilePath[256];
    char encryptedFilePath[256];
    char decryptedFilePath[256];
    char key[256];

    printf("Enter the path of the file to encrypt: ");
    scanf("%s", inputFilePath);
    printf("Enter the path to save the encrypted file: ");
    scanf("%s", encryptedFilePath);
    printf("Enter a password (key) for encryption: ");
    scanf("%s", key);

    encryptFile(inputFilePath, encryptedFilePath, key);
    printf("File encrypted successfully!\n");

    printf("Enter the path to save the decrypted file: ");
    scanf("%s", decryptedFilePath);
    
    decryptFile(encryptedFilePath, decryptedFilePath, key);
    printf("File decrypted successfully! Check the output at: %s\n", decryptedFilePath);

    return 0;
}