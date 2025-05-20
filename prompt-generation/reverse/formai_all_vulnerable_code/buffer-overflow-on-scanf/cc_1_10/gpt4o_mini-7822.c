//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SHIFT 4 // How much to shift the letters
#define BUFFER_SIZE 1024

void encryptFile(const char* inputFileName, const char* outputFileName) {
    FILE* inputFile = fopen(inputFileName, "r");
    FILE* outputFile = fopen(outputFileName, "w");
    if (!inputFile || !outputFile) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, inputFile) != NULL) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] = (buffer[i] - 'a' + SHIFT) % 26 + 'a';
            } else if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                buffer[i] = (buffer[i] - 'A' + SHIFT) % 26 + 'A';
            }
        }
        fprintf(outputFile, "%s", buffer);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void decryptFile(const char* inputFileName, const char* outputFileName) {
    FILE* inputFile = fopen(inputFileName, "r");
    FILE* outputFile = fopen(outputFileName, "w");
    if (!inputFile || !outputFile) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, inputFile) != NULL) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] >= 'a' && buffer[i] <= 'z') {
                buffer[i] = (buffer[i] - 'a' - SHIFT + 26) % 26 + 'a';
            } else if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
                buffer[i] = (buffer[i] - 'A' - SHIFT + 26) % 26 + 'A';
            }
        }
        fprintf(outputFile, "%s", buffer);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void displayMenu() {
    printf("=== File Encryptor ===\n");
    printf("[1] Encrypt a file\n");
    printf("[2] Decrypt a file\n");
    printf("[0] Exit\n");
    printf("======================\n");
}

int main() {
    int choice;
    char inputFileName[256];
    char outputFileName[256];

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                printf("Enter the input file name: ");
                fgets(inputFileName, sizeof(inputFileName), stdin);
                inputFileName[strcspn(inputFileName, "\n")] = 0; // Remove the newline
                printf("Enter the output file name: ");
                fgets(outputFileName, sizeof(outputFileName), stdin);
                outputFileName[strcspn(outputFileName, "\n")] = 0; // Remove the newline
                encryptFile(inputFileName, outputFileName);
                printf("File encrypted successfully!\n");
                break;
            case 2:
                printf("Enter the input file name: ");
                fgets(inputFileName, sizeof(inputFileName), stdin);
                inputFileName[strcspn(inputFileName, "\n")] = 0; // Remove the newline
                printf("Enter the output file name: ");
                fgets(outputFileName, sizeof(outputFileName), stdin);
                outputFileName[strcspn(outputFileName, "\n")] = 0; // Remove the newline
                decryptFile(inputFileName, outputFileName);
                printf("File decrypted successfully!\n");
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}