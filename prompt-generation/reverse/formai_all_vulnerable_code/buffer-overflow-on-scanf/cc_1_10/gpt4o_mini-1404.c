//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a character using the Caesar cipher technique
char encryptChar(char c, int shift) {
    if ('a' <= c && c <= 'z') {
        return 'a' + (c - 'a' + shift) % 26;
    } else if ('A' <= c && c <= 'Z') {
        return 'A' + (c - 'A' + shift) % 26;
    }
    return c; // Non-alphabetic characters are unchanged
}

// Function to encrypt the entire content of the file
void encryptFile(const char *inputFileName, const char *outputFileName, int shift) {
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(1);
    }
    
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        exit(1);
    }

    int c;
    while ((c = fgetc(inputFile)) != EOF) {
        fputc(encryptChar(c, shift), outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Encryption complete! Encrypted file: %s\n", outputFileName);
}

// Function to display a simple menu
void displayMenu() {
    printf("\n=================== File Encryptor ===================\n");
    printf("Welcome to the Artistic C File Encryptor!\n");
    printf("1. Encrypt a file\n");
    printf("2. Exit\n");
    printf("========================================================\n");
}

int main() {
    char inputFileName[256];
    char outputFileName[256];
    int shift;
    int choice;

    do {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter the name of the input file: ");
            scanf("%s", inputFileName);
            printf("Enter the name of the output file: ");
            scanf("%s", outputFileName);
            printf("Enter the shift value for encryption (1-25): ");
            scanf("%d", &shift);

            if (shift < 1 || shift > 25) {
                printf("Invalid shift value. Please enter a value between 1 and 25.\n");
                continue;
            }

            encryptFile(inputFileName, outputFileName, shift);
        } else if (choice == 2) {
            printf("Exiting the program. Thank you for using the Artistic C File Encryptor!\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 2);

    return 0;
}