//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a character using Caesar cipher
char encryptChar(char c, int shift) {
    if (c >= 'a' && c <= 'z') {
        return 'a' + (c - 'a' + shift) % 26;
    } else if (c >= 'A' && c <= 'Z') {
        return 'A' + (c - 'A' + shift) % 26;
    }
    return c; // Non-alphabetic characters remain unchanged
}

// Function to encrypt the contents of a file
void encryptFile(const char *inputFile, const char *outputFile, int shift) {
    FILE *inFile = fopen(inputFile, "r");
    if (!inFile) {
        perror("Error opening input file");
        return;
    }

    FILE *outFile = fopen(outputFile, "w");
    if (!outFile) {
        perror("Error opening output file");
        fclose(inFile);
        return;
    }

    char ch;
    while ((ch = fgetc(inFile)) != EOF) {
        fputc(encryptChar(ch, shift), outFile);
    }

    fclose(inFile);
    fclose(outFile);
    printf("File encrypted successfully! Output saved to %s\n", outputFile);
}

// Function to display instructions and take user input
void displayInstructions() {
    printf("Welcome to the File Encryptor!\n");
    printf("This program will encrypt your text files using a simple Caesar cipher.\n");
    printf("You will need to provide the input file name, output file name, and the shift value.\n\n");
}

int main() {
    displayInstructions();

    char inputFile[256];
    char outputFile[256];
    int shift;

    printf("Enter the input file name: ");
    fgets(inputFile, sizeof(inputFile), stdin);
    inputFile[strcspn(inputFile, "\n")] = 0; // Remove newline character

    printf("Enter the output file name: ");
    fgets(outputFile, sizeof(outputFile), stdin);
    outputFile[strcspn(outputFile, "\n")] = 0; // Remove newline character

    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);
    if (shift < 1 || shift > 25) {
        printf("Invalid shift value. Please run the program again.\n");
        return 1;
    }

    encryptFile(inputFile, outputFile, shift);
    return 0;
}