//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptDecryptFile(const char *inputFile, const char *outputFile, char key) {
    FILE *input, *output;
    char ch;

    // Open the input file in read mode
    input = fopen(inputFile, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    // Open the output file in write mode
    output = fopen(outputFile, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    // Read characters from input file, encrypt/decrypt, and write to output file
    while ((ch = fgetc(input)) != EOF) {
        fputc(ch ^ key, output); // XOR operation for encryption/decryption
    }

    // Close files
    fclose(input);
    fclose(output);
}

void displayMenu() {
    printf("File Encryptor/Decryptor\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char inputFile[256], outputFile[256];
    char key;

    while (1) {
        displayMenu();
        if (scanf(" %d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the input file name for encryption: ");
                scanf("%s", inputFile);
                printf("Enter the output file name for encryption: ");
                scanf("%s", outputFile);
                printf("Enter a single character key for encryption: ");
                scanf(" %c", &key);
                encryptDecryptFile(inputFile, outputFile, key);
                printf("File encrypted successfully.\n");
                break;

            case 2:
                printf("Enter the input file name for decryption: ");
                scanf("%s", inputFile);
                printf("Enter the output file name for decryption: ");
                scanf("%s", outputFile);
                printf("Enter the same key used for encryption: ");
                scanf(" %c", &key);
                encryptDecryptFile(inputFile, outputFile, key);
                printf("File decrypted successfully.\n");
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    }

    return 0;
}