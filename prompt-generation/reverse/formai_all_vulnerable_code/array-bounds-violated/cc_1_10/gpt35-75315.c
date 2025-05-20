//FormAI DATASET v1.0 Category: File Encyptor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 100
#define ENCRYPTION_KEY 5 // Change this to any integer value

void encryptFile(char* fileName) {
    FILE *originalFile, *encryptedFile;
    char originalChar, encryptedChar;
    char encryptedFileName[MAX_FILENAME_SIZE];
    int i;

    // Create encrypted file name
    strcpy(encryptedFileName, fileName);
    strcat(encryptedFileName, ".enc");

    // Open original file and encrypted file
    originalFile = fopen(fileName, "r");
    if (!originalFile) {
        printf("Error: Unable to open file %s\n", fileName);
        return;
    }
    encryptedFile = fopen(encryptedFileName, "w");
    if (!encryptedFile) {
        printf("Error: Unable to create encrypted file %s\n", encryptedFileName);
        return;
    }

    // Encrypt the contents of the original file and write it to the encrypted file
    i = 0;
    while ((originalChar = fgetc(originalFile)) != EOF) {
        encryptedChar = originalChar + ENCRYPTION_KEY;
        fputc(encryptedChar, encryptedFile);
        i++;
    }

    printf("Successfully encrypted file %s with key %d\n", fileName, ENCRYPTION_KEY);

    // Close files
    fclose(originalFile);
    fclose(encryptedFile);
}

void decryptFile(char* encryptedFileName) {
    FILE *encryptedFile, *decryptedFile;
    char originalChar, encryptedChar;
    char decryptedFileName[MAX_FILENAME_SIZE];
    int i;

    // Create decrypted file name
    strcpy(decryptedFileName, encryptedFileName);
    decryptedFileName[strlen(decryptedFileName) - 4] = '\0';

    // Open encrypted file and decrypted file
    encryptedFile = fopen(encryptedFileName, "r");
    if (!encryptedFile) {
        printf("Error: Unable to open encrypted file %s\n", encryptedFileName);
        return;
    }
    decryptedFile = fopen(decryptedFileName, "w");
    if (!decryptedFile) {
        printf("Error: Unable to create decrypted file %s\n", decryptedFileName);
        return;
    }

    // Decrypt the contents of the encrypted file and write it to the decrypted file
    i = 0;
    while ((encryptedChar = fgetc(encryptedFile)) != EOF) {
        originalChar = encryptedChar - ENCRYPTION_KEY;
        fputc(originalChar, decryptedFile);
        i++;
    }

    printf("Successfully decrypted file %s with key %d\n", encryptedFileName, ENCRYPTION_KEY);

    // Close files
    fclose(encryptedFile);
    fclose(decryptedFile);
}

int main() {
    int choice;
    char fileName[MAX_FILENAME_SIZE], encryptedFileName[MAX_FILENAME_SIZE];

    while (1) {
        printf("\nOptions:\n");
        printf("1. Encrypt a file\n");
        printf("2. Decrypt a file\n");
        printf("3. Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
                printf("Enter the name of the file to encrypt: ");
                scanf("%s", fileName);
                encryptFile(fileName);
                break;
            case 2:
                printf("Enter the name of the encrypted file to decrypt: ");
                scanf("%s", encryptedFileName);
                decryptFile(encryptedFileName);
                break;
            case 3:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }

    return 0;
}