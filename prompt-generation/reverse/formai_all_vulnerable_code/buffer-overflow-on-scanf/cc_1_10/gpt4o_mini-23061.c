//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void encryptDecrypt(const char *inputFile, const char *outputFile, char key) {
    FILE *inFile, *outFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    inFile = fopen(inputFile, "rb");
    if (inFile == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    outFile = fopen(outputFile, "wb");
    if (outFile == NULL) {
        perror("Error opening output file");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, inFile)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            buffer[i] ^= key; // XOR operation for encryption and decryption
        }
        fwrite(buffer, 1, bytesRead, outFile);
    }

    fclose(inFile);
    fclose(outFile);
    printf("Operation completed successfully.\n");
}

void showMenu() {
    printf("\nFile Encryptor/Decryptor\n");
    printf("--------------------------\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("--------------------------\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char inputFile[256], outputFile[256], key;

    while (1) {
        showMenu();
        scanf("%d", &choice);
        getchar(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                printf("Enter the name of the file to encrypt: ");
                fgets(inputFile, sizeof(inputFile), stdin);
                inputFile[strcspn(inputFile, "\n")] = 0; // Remove newline
                
                printf("Enter the name of the output encrypted file: ");
                fgets(outputFile, sizeof(outputFile), stdin);
                outputFile[strcspn(outputFile, "\n")] = 0; // Remove newline
                
                printf("Enter encryption key (single character): ");
                key = getchar();
                
                encryptDecrypt(inputFile, outputFile, key);
                break;

            case 2:
                printf("Enter the name of the file to decrypt: ");
                fgets(inputFile, sizeof(inputFile), stdin);
                inputFile[strcspn(inputFile, "\n")] = 0; // Remove newline
                
                printf("Enter the name of the output decrypted file: ");
                fgets(outputFile, sizeof(outputFile), stdin);
                outputFile[strcspn(outputFile, "\n")] = 0; // Remove newline

                printf("Enter decryption key (single character): ");
                key = getchar();
                
                encryptDecrypt(inputFile, outputFile, key);
                break;

            case 3:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid option, please choose again.\n");
        }
    }

    return 0;
}