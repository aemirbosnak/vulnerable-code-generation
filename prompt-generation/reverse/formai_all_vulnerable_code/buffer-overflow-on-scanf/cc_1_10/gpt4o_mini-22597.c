//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void encryptFile(const char *inputFile, const char *outputFile, unsigned char key);
void decryptFile(const char *inputFile, const char *outputFile, unsigned char key);
void displayMenu();

int main() {
    char inputFile[256], outputFile[256];
    unsigned char key;
    int choice;

    displayMenu();

    while (1) {
        printf("\nEnter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the file to encrypt: ");
                scanf("%s", inputFile);
                printf("Enter the name of the output file: ");
                scanf("%s", outputFile);
                printf("Enter a single character key for encryption: ");
                key = getchar(); // Clear the newline character
                key = getchar(); // Read the character key
                encryptFile(inputFile, outputFile, key);
                printf("File encrypted successfully!\n");
                break;
            case 2:
                printf("Enter the name of the file to decrypt: ");
                scanf("%s", inputFile);
                printf("Enter the name of the output file: ");
                scanf("%s", outputFile);
                printf("Enter the same single character key used for encryption: ");
                key = getchar(); // Clear the newline character
                key = getchar(); // Read the character key
                decryptFile(inputFile, outputFile, key);
                printf("File decrypted successfully!\n");
                break;
            case 3:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void encryptFile(const char *inputFile, const char *outputFile, unsigned char key) {
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");
    if (!inFile || !outFile) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch ^ key, outFile); // XOR operation for encryption
    }

    fclose(inFile);
    fclose(outFile);
}

void decryptFile(const char *inputFile, const char *outputFile, unsigned char key) {
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");
    if (!inFile || !outFile) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch ^ key, outFile); // XOR operation for decryption
    }

    fclose(inFile);
    fclose(outFile);
}

void displayMenu() {
    printf("=== Simple File Encryptor ===\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("==============================\n");
}