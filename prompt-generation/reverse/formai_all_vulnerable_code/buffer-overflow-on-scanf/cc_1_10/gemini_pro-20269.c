//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file
void encryptFile(char *fileName, char *key) {
    // Open the file to be encrypted
    FILE *inputFile = fopen(fileName, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Create a new file to store the encrypted data
    char encryptedFileName[strlen(fileName) + 5];
    strcpy(encryptedFileName, fileName);
    strcat(encryptedFileName, ".enc");
    FILE *outputFile = fopen(encryptedFileName, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Get the length of the key
    int keyLength = strlen(key);

    // Read the input file character by character
    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        // Encrypt the character using the key
        ch = ch ^ key[ch % keyLength];

        // Write the encrypted character to the output file
        fputc(ch, outputFile);
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);
}

// Function to decrypt a file
void decryptFile(char *fileName, char *key) {
    // Open the file to be decrypted
    FILE *inputFile = fopen(fileName, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Create a new file to store the decrypted data
    char decryptedFileName[strlen(fileName) - 4];
    strncpy(decryptedFileName, fileName, strlen(fileName) - 4);
    FILE *outputFile = fopen(decryptedFileName, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        exit(1);
    }

    // Get the length of the key
    int keyLength = strlen(key);

    // Read the input file character by character
    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        // Decrypt the character using the key
        ch = ch ^ key[ch % keyLength];

        // Write the decrypted character to the output file
        fputc(ch, outputFile);
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);
}

// Main function
int main() {
    // Get the file name and key from the user
    char fileName[100];
    char key[100];
    printf("Enter the file name: ");
    scanf("%s", fileName);
    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the file
    encryptFile(fileName, key);

    // Decrypt the file
    decryptFile(fileName, key);

    return 0;
}