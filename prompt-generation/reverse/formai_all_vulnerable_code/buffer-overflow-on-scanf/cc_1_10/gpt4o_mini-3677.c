//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptDecrypt(FILE *inputFile, FILE *outputFile, char key) {
    char buffer;

    while (fread(&buffer, sizeof(char), 1, inputFile) == 1) {
        buffer ^= key; // XOR encryption/decryption
        fwrite(&buffer, sizeof(char), 1, outputFile);
    }
}

void handleFile(const char *inputFileName, const char *outputFileName, char key, int mode) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        perror("Error creating output file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    if (mode == 1) {
        printf("Encrypting file %s to %s with key '%c'\n", inputFileName, outputFileName, key);
    } else {
        printf("Decrypting file %s to %s with key '%c'\n", inputFileName, outputFileName, key);
    }

    encryptDecrypt(inputFile, outputFile, key);

    fclose(inputFile);
    fclose(outputFile);
    printf("Operation completed successfully.\n");
}

int main() {
    char inputFileName[256];
    char outputFileName[256];
    char key;
    int mode;

    printf("Welcome to the Simple C File Encryptor!\n");
    printf("Please select an operation:\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &mode);

    if (mode != 1 && mode != 2) {
        fprintf(stderr, "Invalid choice! Please run the program again.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the input filename: ");
    scanf("%s", inputFileName);

    printf("Enter the output filename: ");
    scanf("%s", outputFileName);

    printf("Enter the encryption/decryption key (single character): ");
    getchar(); // Consume newline left by scanf
    scanf("%c", &key);

    handleFile(inputFileName, outputFileName, key, mode);

    return EXIT_SUCCESS;
}