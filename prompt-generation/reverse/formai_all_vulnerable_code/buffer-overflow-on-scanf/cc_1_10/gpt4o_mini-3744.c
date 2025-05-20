//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptFile(const char *inputFileName, const char *outputFileName, int key);
void decryptFile(const char *inputFileName, const char *outputFileName, int key);
void handleError(const char *message);
void printMenu();

int main() {
    int choice;
    char inputFileName[100];
    char outputFileName[100];
    int key;

    do {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter input file name: ");
                scanf("%s", inputFileName);
                printf("Enter output file name: ");
                scanf("%s", outputFileName);
                printf("Enter encryption key (integer): ");
                scanf("%d", &key);
                encryptFile(inputFileName, outputFileName, key);
                printf("File encrypted successfully!\n");
                break;
            case 2:
                printf("Enter input file name: ");
                scanf("%s", inputFileName);
                printf("Enter output file name: ");
                scanf("%s", outputFileName);
                printf("Enter decryption key (integer): ");
                scanf("%d", &key);
                decryptFile(inputFileName, outputFileName, key);
                printf("File decrypted successfully!\n");
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}

void encryptFile(const char *inputFileName, const char *outputFileName, int key) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) handleError("Error opening input file.");

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        fclose(inputFile);
        handleError("Error opening output file.");
    }

    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch ^ key, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void decryptFile(const char *inputFileName, const char *outputFileName, int key) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) handleError("Error opening input file.");

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        fclose(inputFile);
        handleError("Error opening output file.");
    }

    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        fputc(ch ^ key, outputFile); // same operation for encryption and decryption
    }

    fclose(inputFile);
    fclose(outputFile);
}

void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void printMenu() {
    printf("\n--- C File Encryptor ---\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
}