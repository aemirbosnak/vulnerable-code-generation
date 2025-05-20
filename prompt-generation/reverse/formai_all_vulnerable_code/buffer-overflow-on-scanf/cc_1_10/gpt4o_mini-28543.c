//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encryptDecryptFile(const char *filePath, char key) {
    FILE *file = fopen(filePath, "r+b"); // Open file for reading and writing in binary mode
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(file)) != EOF) {
        // XOR each character with the key to encrypt/decrypt
        fseek(file, -1, SEEK_CUR);
        fputc(ch ^ key, file);
        fflush(file);
        fseek(file, 0, SEEK_CUR);
    }

    fclose(file);
}

void promptUserForFile(const char *mode) {
    char filePath[256];
    printf("Enter the path of the file to %s: ", mode);
    scanf("%255s", filePath); // Limiting input to avoid buffer overflow

    if (strcmp(mode, "encrypt") == 0) {
        printf("Encrypting the file...\n");
        encryptDecryptFile(filePath, 'K'); // Using 'K' as a simple encryption key
        printf("Encryption completed.\n");
    } else if (strcmp(mode, "decrypt") == 0) {
        printf("Decrypting the file...\n");
        encryptDecryptFile(filePath, 'K'); // Using the same key for decryption
        printf("Decryption completed.\n");
    } else {
        fprintf(stderr, "Unknown mode: %s\n", mode);
        exit(EXIT_FAILURE);
    }
}

int main() {
    printf("Welcome to the C File Encryptor!\n");
    char choice;

    while (1) {
        printf("Choose an operation:\n");
        printf("1. Encrypt a file\n");
        printf("2. Decrypt a file\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice); // space before %c ensures it skips whitespace

        switch (choice) {
            case '1':
                promptUserForFile("encrypt");
                break;
            case '2':
                promptUserForFile("decrypt");
                break;
            case '3':
                printf("Exiting the program. Stay safe!\n");
                exit(EXIT_SUCCESS);
            default:
                fprintf(stderr, "Invalid choice! Please try again.\n");
        }
    }

    return 0;
}