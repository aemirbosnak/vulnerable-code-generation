//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

void encryptDecrypt(FILE *inputFile, FILE *outputFile, char key) {
    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch ^ key, outputFile);
    }
}

void processFiles(char *inputFilename, char *outputFilename, char key) {
    FILE *inputFile = fopen(inputFilename, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    encryptDecrypt(inputFile, outputFile, key);

    printf("File encrypted successfully to: %s\n", outputFilename);

    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    char inputFilename[256], outputFilename[256], key;

    printf("Welcome to the C File Encryptor!\n");
    printf("Please enter the name of the input file: ");
    fgets(inputFilename, sizeof(inputFilename), stdin);
    // Remove newline character from fgets
    inputFilename[strcspn(inputFilename, "\n")] = 0;

    printf("Please enter the desired name for the output file: ");
    fgets(outputFilename, sizeof(outputFilename), stdin);
    // Remove newline character from fgets
    outputFilename[strcspn(outputFilename, "\n")] = 0;

    printf("Please enter a single character as the encryption key: ");
    scanf(" %c", &key);

    // Confirm with the user before proceeding
    printf("You are about to encrypt \"%s\" into \"%s\" using the key: '%c'\n", inputFilename, outputFilename, key);
    printf("Are you sure? (y/n): ");
    char confirmation;
    scanf(" %c", &confirmation);

    if (confirmation == 'y' || confirmation == 'Y') {
        processFiles(inputFilename, outputFilename, key);
    } else {
        printf("Operation cancelled.\n");
    }

    return 0;
}