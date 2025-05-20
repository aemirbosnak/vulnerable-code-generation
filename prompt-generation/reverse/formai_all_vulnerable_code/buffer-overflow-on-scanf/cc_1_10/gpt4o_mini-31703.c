//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024 // Maximum buffer size for file reading
#define SHIFT 3         // Shift value for the Caesar cipher

// Function prototypes
void encryptFile(const char *inputFileName, const char *outputFileName);
void decryptFile(const char *inputFileName, const char *outputFileName);
void caesarCipher(char *buffer, int shift);
void welcomeMessage();
void farewellMessage();

int main() {
    char inputFile[MAX_BUFFER];
    char outputFile[MAX_BUFFER];
    int choice;

    welcomeMessage();

    while (1) {
        printf("\n1. Encrypt a file\n2. Decrypt a file\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);
        getchar(); // To consume the newline after the choice

        switch (choice) {
            case 1:
                printf("Enter the name of the file to encrypt: ");
                fgets(inputFile, MAX_BUFFER, stdin);
                strtok(inputFile, "\n"); // Remove newline character
                snprintf(outputFile, MAX_BUFFER, "encrypted_%s", inputFile);
                encryptFile(inputFile, outputFile);
                printf("Encryption complete! Output saved to '%s'\n", outputFile);
                break;
            case 2:
                printf("Enter the name of the file to decrypt: ");
                fgets(inputFile, MAX_BUFFER, stdin);
                strtok(inputFile, "\n"); // Remove newline character
                snprintf(outputFile, MAX_BUFFER, "decrypted_%s", inputFile);
                decryptFile(inputFile, outputFile);
                printf("Decryption complete! Output saved to '%s'\n", outputFile);
                break;
            case 3:
                farewellMessage();
                exit(0);
            default:
                printf("Invalid option, please try again!\n");
                break;
        }
    }

    return 0;
}

void encryptFile(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");
    char buffer[MAX_BUFFER];

    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, MAX_BUFFER, inputFile)) {
        caesarCipher(buffer, SHIFT);
        fputs(buffer, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void decryptFile(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");
    char buffer[MAX_BUFFER];

    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, MAX_BUFFER, inputFile)) {
        caesarCipher(buffer, -SHIFT); // Reverse shift for decryption
        fputs(buffer, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void caesarCipher(char *buffer, int shift) {
    for (int i = 0; buffer[i] != '\0'; ++i) {
        char c = buffer[i];

        if ('a' <= c && c <= 'z') {
            c = (c - 'a' + shift + 26) % 26 + 'a';
        } else if ('A' <= c && c <= 'Z') {
            c = (c - 'A' + shift + 26) % 26 + 'A';
        }
        buffer[i] = c;
    }
}

void welcomeMessage() {
    printf("======================================\n");
    printf("          C File Encryptor           \n");
    printf("======================================\n");
    printf("Welcome, noble traveler! Ready to\n");
    printf("encrypt or decrypt files with ease?\n");
    printf("======================================\n");
}

void farewellMessage() {
    printf("======================================\n");
    printf("       Thanks for using the tool!    \n");
    printf("        Until next time, farewell!   \n");
    printf("======================================\n");
}