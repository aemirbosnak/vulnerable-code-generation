//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 32
#define BUFFER_SIZE 256

// Function to encrypt and write to a new file
void encryptFile(const char *inputFileName, const char *outputFileName, const char *password) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Error creating output file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    size_t passwordLength = strlen(password);
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    size_t i = 0;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, inputFile)) > 0) {
        for (size_t j = 0; j < bytesRead; j++) {
            buffer[j] ^= password[i % passwordLength]; // XOR operation
            i++;
        }
        fwrite(buffer, 1, bytesRead, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("File \"%s\" has been encrypted as \"%s\"!\n", inputFileName, outputFileName);
}

// Function to decrypt the file using the same XOR operation
void decryptFile(const char *inputFileName, const char *outputFileName, const char *password) {
    encryptFile(inputFileName, outputFileName, password); // Same function for encryption and decryption
}

// Function to handle the menu
void displayMenu() {
    printf("************************************\n");
    printf("       File Encryptor/Decryptor     \n");
    printf("************************************\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("************************************\n");
}

int main() {
    int choice;
    char inputFileName[BUFFER_SIZE];
    char outputFileName[BUFFER_SIZE];
    char password[MAX_PASSWORD_LENGTH];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the file to encrypt: ");
                scanf("%s", inputFileName);
                printf("Enter the output file name: ");
                scanf("%s", outputFileName);
                printf("Enter your password (max %d characters): ", MAX_PASSWORD_LENGTH - 1);
                scanf("%s", password);
                encryptFile(inputFileName, outputFileName, password);
                break;

            case 2:
                printf("Enter the name of the file to decrypt: ");
                scanf("%s", inputFileName);
                printf("Enter the output file name: ");
                scanf("%s", outputFileName);
                printf("Enter your password (max %d characters): ", MAX_PASSWORD_LENGTH - 1);
                scanf("%s", password);
                decryptFile(inputFileName, outputFileName, password);
                break;

            case 3:
                printf("Exiting the program. Have a nice day!\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}