//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

void encryptDecrypt(FILE *inputFile, FILE *outputFile, char key) {
    char buffer[MAX_BUFFER];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, sizeof(char), MAX_BUFFER, inputFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key; // XOR encryption
        }
        fwrite(buffer, sizeof(char), bytesRead, outputFile);
    }
}

void processFile(const char *inputFilename, const char *outputFilename, char key) {
    FILE *inputFile = fopen(inputFilename, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return;
    }

    FILE *outputFile = fopen(outputFilename, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return;
    }

    encryptDecrypt(inputFile, outputFile, key);

    fclose(inputFile);
    fclose(outputFile);
}

void displayMenu() {
    printf("File Encryptor/Decryptor\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("Please choose an option: ");
}

int main() {
    int choice;
    char inputFilename[256], outputFilename[256], key;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter input filename to encrypt: ");
                scanf("%s", inputFilename);
                printf("Enter output filename for encrypted file: ");
                scanf("%s", outputFilename);
                printf("Enter a single character key for encryption: ");
                scanf(" %c", &key);
                processFile(inputFilename, outputFilename, key);
                printf("File encrypted successfully!\n");
                break;

            case 2:
                printf("Enter input filename to decrypt: ");
                scanf("%s", inputFilename);
                printf("Enter output filename for decrypted file: ");
                scanf("%s", outputFilename);
                printf("Enter the same character key for decryption: ");
                scanf(" %c", &key);
                processFile(inputFilename, outputFilename, key);
                printf("File decrypted successfully!\n");
                break;

            case 3:
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}