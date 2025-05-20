//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt(const char *inputFile, const char *outputFile, int key);
void decrypt(const char *inputFile, const char *outputFile, int key);
void displayMenu();
void performFileOperation(int choice);

// The peaceful journey of file encrypting and decrypting
int main() {
    int choice;

    // Begin the serene adventure
    do {
        displayMenu();
        printf("Choose an operation: ");
        scanf("%d", &choice);

        if (choice == 1 || choice == 2) {
            performFileOperation(choice);
        } else if (choice != 0) {
            printf("Invalid choice! Please choose again.\n");
        }

    } while (choice != 0);

    printf("Thank you for using the file encryptor. Have a peaceful day!\n");
    return 0;
}

// Function to display the menu options
void displayMenu() {
    printf("\n--- File Encryptor Menu ---\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("0. Exit\n");
}

// Function to perform the selected file operation
void performFileOperation(int choice) {
    char inputFile[256], outputFile[256];
    int key;

    // Simple key request for the serene journey
    printf("Enter the key for encryption/decryption (1-255): ");
    scanf("%d", &key);

    if (key < 1 || key > 255) {
        printf("Invalid key! Please choose a key between 1 and 255.\n");
        return;
    }

    printf("Enter the input filename: ");
    scanf("%s", inputFile);
    printf("Enter the output filename: ");
    scanf("%s", outputFile);

    if (choice == 1) {
        encrypt(inputFile, outputFile, key);
    } else if (choice == 2) {
        decrypt(inputFile, outputFile, key);
    }
}

// Function for file encryption
void encrypt(const char *inputFile, const char *outputFile, int key) {
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");
    int ch;

    if (!inFile || !outFile) {
        printf("Error opening files. Please check the filenames and try again.\n");
        return;
    }

    // Transformation begins with peaceful intentions
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch + key, outFile);
    }

    fclose(inFile);
    fclose(outFile);
    printf("Encryption completed successfully. The output is calm in %s.\n", outputFile);
}

// Function for file decryption
void decrypt(const char *inputFile, const char *outputFile, int key) {
    FILE *inFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");
    int ch;

    if (!inFile || !outFile) {
        printf("Error opening files. Please check the filenames and try again.\n");
        return;
    }

    // A gentle return to tranquility
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(ch - key, outFile);
    }

    fclose(inFile);
    fclose(outFile);
    printf("Decryption completed successfully. The output is peaceful in %s.\n", outputFile);
}