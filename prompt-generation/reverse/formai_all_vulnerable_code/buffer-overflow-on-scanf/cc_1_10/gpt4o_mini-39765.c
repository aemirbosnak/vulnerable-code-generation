//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encryptDecryptFile(const char *inputFile, const char *outputFile, char key) {
    FILE *input, *output;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Open the input file for reading
    input = fopen(inputFile, "rb");
    if (!input) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open the output file for writing
    output = fopen(outputFile, "wb");
    if (!output) {
        fclose(input);
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Read from input file, encrypt/decrypt, and write to output file
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, input)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key;  // XOR operation for encryption/decryption
        }
        fwrite(buffer, 1, bytesRead, output);
    }

    // Close the opened files
    fclose(input);
    fclose(output);
}

// Function to read a single character from console
char readChar(const char *prompt) {
    char ch;
    printf("%s", prompt);
    scanf(" %c", &ch);
    return ch;
}

int main() {
    char inputFile[256], outputFile[256], key;

    // Get input file name
    printf("Enter the name of the file to encrypt/decrypt: ");
    scanf("%s", inputFile);

    // Get output file name
    printf("Enter the name of the output file: ");
    scanf("%s", outputFile);

    // Get encryption/decryption key
    key = readChar("Enter a single character key for encryption/decryption: ");

    // Perform the encryption/decryption process
    encryptDecryptFile(inputFile, outputFile, key);

    printf("Encryption/Decryption completed successfully!\n");
    return 0;
}