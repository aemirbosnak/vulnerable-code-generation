//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 100
#define ENCRYPTION_KEY 'K' // Simple XOR key

void encryptDecryptFile(const char *inputFile, const char *outputFile, char key) {
    FILE *fIn, *fOut;
    char ch;

    // Open the input file
    fIn = fopen(inputFile, "rb");
    if (fIn == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open/create the output file
    fOut = fopen(outputFile, "wb");
    if (fOut == NULL) {
        perror("Error opening output file");
        fclose(fIn);
        exit(EXIT_FAILURE);
    }

    // Read and encrypt/decrypt each character
    while ((ch = fgetc(fIn)) != EOF) {
        fputc(ch ^ key, fOut);
    }

    // Close files
    fclose(fIn);
    fclose(fOut);
    printf("File '%s' encrypted/decrypted and saved as '%s'.\n", inputFile, outputFile);
}

void displayMenu() {
    printf("\n");
    printf("===================================\n");
    printf("       FILE ENCRYPTOR 1.0         \n");
    printf("===================================\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("===================================\n");
}

int main() {
    int choice;
    char inputFile[MAX_FILENAME], outputFile[MAX_FILENAME];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter input file name to encrypt: ");
                scanf("%s", inputFile);
                printf("Enter output file name for encrypted data: ");
                scanf("%s", outputFile);
                encryptDecryptFile(inputFile, outputFile, ENCRYPTION_KEY);
                break;
                
            case 2:
                printf("Enter input file name to decrypt: ");
                scanf("%s", inputFile);
                printf("Enter output file name for decrypted data: ");
                scanf("%s", outputFile);
                encryptDecryptFile(inputFile, outputFile, ENCRYPTION_KEY);
                break;
                
            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(EXIT_SUCCESS);
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}