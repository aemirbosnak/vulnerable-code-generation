//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(const char *inputFile, const char *outputFile, char key) {
    FILE *inFile = fopen(inputFile, "rb");
    if (inFile == NULL) {
        perror("Could not open input file");
        exit(EXIT_FAILURE);
    }

    FILE *outFile = fopen(outputFile, "wb");
    if (outFile == NULL) {
        perror("Could not open output file");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    char ch;
    while (fread(&ch, sizeof(char), 1, inFile)) {
        ch ^= key; // Simple XOR encryption
        fwrite(&ch, sizeof(char), 1, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

void decrypt(const char *inputFile, const char *outputFile, char key) {
    // Decryption is the same as encryption due to XOR's properties
    encrypt(inputFile, outputFile, key);
}

void displayMenu() {
    printf("Welcome to the Peaceful File Encryptor\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    int choice;
    char inputFile[256], outputFile[256], key;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the file to encrypt: ");
                scanf("%s", inputFile);
                printf("Enter the name of the output file: ");
                scanf("%s", outputFile);
                printf("Provide a single character key for encryption: ");
                scanf(" %c", &key);
                encrypt(inputFile, outputFile, key);
                printf("The file has been peacefully encrypted.\n\n");
                break;

            case 2:
                printf("Enter the name of the file to decrypt: ");
                scanf("%s", inputFile);
                printf("Enter the name of the output file: ");
                scanf("%s", outputFile);
                printf("Provide the same single character key for decryption: ");
                scanf(" %c", &key);
                decrypt(inputFile, outputFile, key);
                printf("The file has been peacefully decrypted.\n\n");
                break;

            case 3:
                printf("Thank you for using the Peaceful File Encryptor. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice, please select a valid option.\n\n");
        }
    }
}