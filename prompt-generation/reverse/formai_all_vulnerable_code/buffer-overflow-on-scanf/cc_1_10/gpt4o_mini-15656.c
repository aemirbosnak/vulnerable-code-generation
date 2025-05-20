//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Function to encrypt the file using a simple Caesar cipher.
void encryptFile(const char *inputFileName, const char *outputFileName, int shift) {
    FILE *inputFile;
    FILE *outputFile;
    char ch;

    // Open the input file for reading.
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Alas! The input file could not be found.\n");
        exit(1);
    }

    // Open the output file for writing.
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        fclose(inputFile);
        fprintf(stderr, "Alas! The output file could not be created.\n");
        exit(1);
    }

    // Read each character from the input file and write its encrypted form to the output file.
    while ((ch = fgetc(inputFile)) != EOF) {
        // Shift characters based on their ASCII values.
        char encryptedChar = (char)(ch + shift);
        fputc(encryptedChar, outputFile);
    }

    // Close the files after use.
    fclose(inputFile);
    fclose(outputFile);

    printf("The scroll has been successfully encrypted! \n");
}

// Function to decrypt the file using the same shift.
void decryptFile(const char *inputFileName, const char *outputFileName, int shift) {
    FILE *inputFile;
    FILE *outputFile;
    char ch;

    // Open the input file for reading.
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Alas! The input file could not be found.\n");
        exit(1);
    }

    // Open the output file for writing.
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        fclose(inputFile);
        fprintf(stderr, "Alas! The output file could not be created.\n");
        exit(1);
    }

    // Read each character from the input file and write its decrypted form to the output file.
    while ((ch = fgetc(inputFile)) != EOF) {
        // Shift back characters based on their ASCII values.
        char decryptedChar = (char)(ch - shift);
        fputc(decryptedChar, outputFile);
    }

    // Close the files after use.
    fclose(inputFile);
    fclose(outputFile);

    printf("The scroll has been successfully decrypted! \n");
}

int main() {
    int choice, shift;
    char inputFile[100], outputFile[100];

    printf("Enter the shift value for your mystical incantation (1-25): ");
    scanf("%d", &shift);

    if (shift < 1 || shift > 25) {
        fprintf(stderr, "The shift value must be within the bounds of 1 to 25!\n");
        return 1;
    }

    printf("Art thou wishing to (1) encrypt or (2) decrypt a scroll? ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter the name of the scroll to encrypt: ");
        scanf("%s", inputFile);
        printf("Enter the name for the enchanted scroll of encryption: ");
        scanf("%s", outputFile);
        encryptFile(inputFile, outputFile, shift);
    } else if (choice == 2) {
        printf("Enter the name of the scroll to decrypt: ");
        scanf("%s", inputFile);
        printf("Enter the name for the enchanted scroll of decryption: ");
        scanf("%s", outputFile);
        decryptFile(inputFile, outputFile, shift);
    } else {
        fprintf(stderr, "Thou lackest the foresight to choose a correct option!\n");
    }

    return 0;
}