//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0x5A  // Simple XOR key for encryption

// Function to encrypt or decrypt the content of a file
void processFile(const char *inputFileName, const char *outputFileName) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    // Read contents from input file and process
    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        // XOR with the key for encryption/decryption
        fputc(ch ^ KEY, outputFile);
    }

    // Clean up resources
    fclose(inputFile);
    fclose(outputFile);
}

// Function to display the main menu
void displayMenu() {
    printf("##########################\n");
    printf("#   Simple File Encryptor #\n");
    printf("##########################\n");
    printf("1. Encrypt a File\n");
    printf("2. Decrypt a File\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

// Function to handle user choice
void handleChoice(int choice) {
    char inputFile[256];
    char outputFile[256];

    switch (choice) {
        case 1:
            printf("Enter the name of the file to encrypt: ");
            scanf("%255s", inputFile);
            snprintf(outputFile, sizeof(outputFile), "%s.enc", inputFile);
            processFile(inputFile, outputFile);
            printf("File encrypted successfully as %s.\n", outputFile);
            break;

        case 2:
            printf("Enter the name of the file to decrypt: ");
            scanf("%255s", inputFile);
            snprintf(outputFile, sizeof(outputFile), "%s.dec", inputFile);
            processFile(inputFile, outputFile);
            printf("File decrypted successfully as %s.\n", outputFile);
            break;

        case 3:
            printf("Exiting the program. Thank you!\n");
            exit(EXIT_SUCCESS);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
    }
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        handleChoice(choice);
        printf("\n");
    }

    return 0;
}