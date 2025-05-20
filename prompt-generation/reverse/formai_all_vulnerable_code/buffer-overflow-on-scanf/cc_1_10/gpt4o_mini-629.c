//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 1024

void encrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];
        
        // Encrypt uppercase characters
        if (ch >= 'A' && ch <= 'Z') {
            text[i] = (ch + key - 'A') % 26 + 'A';
        }
        // Encrypt lowercase characters
        else if (ch >= 'a' && ch <= 'z') {
            text[i] = (ch + key - 'a') % 26 + 'a';
        }
    }
}

void decrypt(char *text, int key) {
    // Decrypting is simply applying the negative of the key
    encrypt(text, 26 - (key % 26));
}

void writeToFile(const char *filename, const char *text) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s\n", text);
    fclose(file);
}

void readFromFile(const char *filename, char *text) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        exit(EXIT_FAILURE);
    }
    fgets(text, MAX_TEXT_SIZE, file);
    fclose(file);
}

int main() {
    char text[MAX_TEXT_SIZE];
    char filename[100];
    int key, choice;

    printf("Caesar Cipher Encryption/Decryption Program\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");

    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Clearing the input buffer
        while (getchar() != '\n');

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(text, sizeof(text), stdin);
                
                // Removing newline character
                text[strcspn(text, "\n")] = 0;

                printf("Enter the encryption key (1-25): ");
                scanf("%d", &key);
                
                // Encrypt the text
                encrypt(text, key);

                // Get filename and write encrypted text
                printf("Enter filename to save encrypted message: ");
                scanf("%s", filename);
                writeToFile(filename, text);

                printf("Encrypted message saved to %s\n", filename);
                break;

            case 2:
                printf("Enter the filename to decrypt: ");
                scanf("%s", filename);
                readFromFile(filename, text);

                printf("Enter the decryption key (1-25): ");
                scanf("%d", &key);
                
                // Decrypt the text
                decrypt(text, key);
                
                printf("Decrypted message: %s\n", text);
                break;

            case 3:
                exit(EXIT_SUCCESS);

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}