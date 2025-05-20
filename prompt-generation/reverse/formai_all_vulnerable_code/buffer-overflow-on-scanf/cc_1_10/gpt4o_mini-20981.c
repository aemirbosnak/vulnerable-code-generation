//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptDecrypt(const char *inputFile, const char *outputFile, char key) {
    FILE *input, *output;
    int ch;

    input = fopen(inputFile, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }

    output = fopen(outputFile, "wb");
    if (output == NULL) {
        fclose(input);
        perror("Error opening output file");
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(input)) != EOF) {
        fputc(ch ^ key, output); // XOR encryption/decryption
    }

    fclose(input);
    fclose(output);
}

void displayMenu() {
    printf("=== File Encryptor/Decryptor ===\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;
    char inputFile[256], outputFile[256], key;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter input file name: ");
                scanf("%s", inputFile);
                printf("Enter output file name: ");
                scanf("%s", outputFile);
                printf("Enter encryption key (single character): ");
                scanf(" %c", &key);
                encryptDecrypt(inputFile, outputFile, key);
                printf("File encrypted successfully!\n\n");
                break;

            case 2:
                printf("Enter input file name: ");
                scanf("%s", inputFile);
                printf("Enter output file name: ");
                scanf("%s", outputFile);
                printf("Enter decryption key (single character): ");
                scanf(" %c", &key);
                encryptDecrypt(inputFile, outputFile, key);
                printf("File decrypted successfully!\n\n");
                break;

            case 3:
                printf("Exiting the program...\n");
                exit(EXIT_SUCCESS);
                break;

            default:
                printf("Invalid choice! Please try again.\n\n");
                break;
        }
    }

    return 0;
}