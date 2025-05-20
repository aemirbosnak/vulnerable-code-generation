//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
void encryptFile(char *fileName, char *key) {
    // Open the file to be encrypted in read mode
    FILE *inputFile = fopen(fileName, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open a new file to store the encrypted data in write mode
    char encryptedFileName[strlen(fileName) + 5];
    strcpy(encryptedFileName, fileName);
    strcat(encryptedFileName, ".enc");
    FILE *outputFile = fopen(encryptedFileName, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Get the length of the key
    int keyLength = strlen(key);

    // Read the input file character by character
    char ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        // Encrypt the character using the XOR operation
        ch ^= key[ch % keyLength];

        // Write the encrypted character to the output file
        fputc(ch, outputFile);
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    printf("File encrypted successfully!\n");
}

// Function to decrypt a file
void decryptFile(char *fileName, char *key) {
    // Open the file to be decrypted in read mode
    FILE *inputFile = fopen(fileName, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open a new file to store the decrypted data in write mode
    char decryptedFileName[strlen(fileName) - 4];
    strncpy(decryptedFileName, fileName, strlen(fileName) - 4);
    FILE *outputFile = fopen(decryptedFileName, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    // Get the length of the key
    int keyLength = strlen(key);

    // Read the input file character by character
    char ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        // Decrypt the character using the XOR operation
        ch ^= key[ch % keyLength];

        // Write the decrypted character to the output file
        fputc(ch, outputFile);
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    printf("File decrypted successfully!\n");
}

// Main function
int main() {
    // Get the file name and key from the user
    char fileName[100];
    printf("Enter the file name to be encrypted/decrypted: ");
    scanf("%s", fileName);

    char key[100];
    printf("Enter the encryption/decryption key: ");
    scanf("%s", key);

    // Get the encryption/decryption option from the user
    int option;
    printf("Enter 1 to encrypt the file or 2 to decrypt the file: ");
    scanf("%d", &option);

    // Encrypt or decrypt the file based on the user's choice
    if (option == 1) {
        encryptFile(fileName, key);
    } else if (option == 2) {
        decryptFile(fileName, key);
    } else {
        printf("Invalid option. Please enter 1 to encrypt or 2 to decrypt.\n");
    }

    return 0;
}