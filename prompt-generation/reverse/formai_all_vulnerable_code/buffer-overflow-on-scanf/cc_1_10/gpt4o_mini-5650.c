//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encrypt_decrypt(FILE *inputFile, FILE *outputFile, char key) {
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    size_t i;

    // Read the file in chunks and apply XOR encryption
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), inputFile)) > 0) {
        for (i = 0; i < bytesRead; i++) {
            buffer[i] ^= key;  // XOR operation for encryption/decryption
        }
        fwrite(buffer, 1, bytesRead, outputFile);  // Write output
    }
}

void displayMenu() {
    printf("File Encryptor/Decryptor\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

void performEncryption() {
    char inputFileName[100];
    char outputFileName[100];
    char key;

    printf("Enter the name of the file to encrypt: ");
    scanf("%s", inputFileName);
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);
    printf("Enter the encryption key (single character): ");
    getchar();  // To consume the newline character
    scanf("%c", &key);

    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return;
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return;
    }

    encrypt_decrypt(inputFile, outputFile, key);

    fclose(inputFile);
    fclose(outputFile);
    printf("File encrypted successfully!\n");
}

void performDecryption() {
    char inputFileName[100];
    char outputFileName[100];
    char key;

    printf("Enter the name of the file to decrypt: ");
    scanf("%s", inputFileName);
    printf("Enter the name of the output file: ");
    scanf("%s", outputFileName);
    printf("Enter the encryption key (single character): ");
    getchar();  // To consume the newline character
    scanf("%c", &key);

    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return;
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return;
    }

    encrypt_decrypt(inputFile, outputFile, key);

    fclose(inputFile);
    fclose(outputFile);
    printf("File decrypted successfully!\n");
}

int main() {
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                performEncryption();
                break;
            case 2:
                performDecryption();
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}