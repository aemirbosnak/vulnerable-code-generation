//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 0xAA // Simple XOR key

void encryptDecryptFile(const char *inputFile, const char *outputFile) {
    FILE *inFile = fopen(inputFile, "rb");
    if (!inFile) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    FILE *outFile = fopen(outputFile, "wb");
    if (!outFile) {
        fclose(inFile);
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    int c;
    while ((c = fgetc(inFile)) != EOF) {
        // Simple XOR encryption/decryption
        fputc(c ^ KEY, outFile);
    }

    fclose(inFile);
    fclose(outFile);
    printf("Encryption/Decryption complete. File saved as '%s'.\n", outputFile);
}

void displayMenu() {
    printf("\n--- File Encryptor/Decryptor ---\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("Please select an option: ");
}

int main() {
    while (1) {
        displayMenu();
        
        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline character

        if (choice == 3) {
            printf("Exiting the program.\n");
            break; 
        }

        char inputFile[256], outputFile[256];

        printf("Enter the input filename: ");
        fgets(inputFile, sizeof(inputFile), stdin);
        inputFile[strcspn(inputFile, "\n")] = 0; // Remove newline

        printf("Enter the output filename: ");
        fgets(outputFile, sizeof(outputFile), stdin);
        outputFile[strcspn(outputFile, "\n")] = 0; // Remove newline

        if (choice == 1) {
            encryptDecryptFile(inputFile, outputFile);
        } else if (choice == 2) {
            encryptDecryptFile(inputFile, outputFile);
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}