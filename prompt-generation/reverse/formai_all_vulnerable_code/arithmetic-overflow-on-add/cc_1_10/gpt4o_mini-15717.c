//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Encrypt uppercase characters
        if (ch >= 'A' && ch <= 'Z') {
            message[i] = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase characters
        else if (ch >= 'a' && ch <= 'z') {
            message[i] = (ch - 'a' + shift) % 26 + 'a';
        }
    }
}

void decrypt(char *message, int shift) {
    // Decrypt by shifting in the opposite direction
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Decrypt uppercase characters
        if (ch >= 'A' && ch <= 'Z') {
            message[i] = (ch - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase characters
        else if (ch >= 'a' && ch <= 'z') {
            message[i] = (ch - 'a' - shift + 26) % 26 + 'a';
        }
    }
}

int main() {
    char message[256];
    int shift;
    int choice;

    printf("Welcome to Caesar Cipher Encryption/Decryption Program!\n");
    
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        
        // Read user choice
        scanf("%d", &choice);
        getchar(); // To clear the newline character after reading choice

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(message, sizeof(message), stdin);
                printf("Enter the shift value (0-25): ");
                scanf("%d", &shift);
                getchar(); // Clear newline character

                encrypt(message, shift);
                printf("Encrypted Message: %s", message);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                fgets(message, sizeof(message), stdin);
                printf("Enter the shift value (0-25): ");
                scanf("%d", &shift);
                getchar(); // Clear newline character

                decrypt(message, shift);
                printf("Decrypted Message: %s", message);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}