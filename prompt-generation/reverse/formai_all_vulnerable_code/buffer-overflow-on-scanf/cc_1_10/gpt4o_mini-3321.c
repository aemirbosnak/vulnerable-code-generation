//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void clearBuffer() {
    while (getchar() != '\n');
}

void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }

        message[i] = ch;  // Update the character in the message
    }
}

void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - shift + 26) % 26 + 'a';
        }

        message[i] = ch;  // Update the character in the message
    }
}

int main() {
    int choice, shift;
    char message[256];

    printf("Welcome to the Peaceful C Encryption Program!\n");
    printf("Select an option:\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 3.\n");
            clearBuffer();
            continue;
        }
        clearBuffer();

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(message, sizeof(message), stdin);
                // Remove newline character
                message[strcspn(message, "\n")] = 0;

                printf("Enter shift value (1-25): ");
                if (scanf("%d", &shift) != 1 || shift < 1 || shift > 25) {
                    printf("Invalid shift value. Please enter a number between 1 and 25.\n");
                    clearBuffer();
                    continue;
                }
                clearBuffer();

                encrypt(message, shift);
                printf("Encrypted message: %s\n", message);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                fgets(message, sizeof(message), stdin);
                // Remove newline character
                message[strcspn(message, "\n")] = 0;

                printf("Enter shift value (1-25): ");
                if (scanf("%d", &shift) != 1 || shift < 1 || shift > 25) {
                    printf("Invalid shift value. Please enter a number between 1 and 25.\n");
                    clearBuffer();
                    continue;
                }
                clearBuffer();

                decrypt(message, shift);
                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                printf("Thank you for using the Peaceful C Encryption Program! Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please select 1, 2, or 3.\n");
        }
    }

    return 0;  // Program will never reach here
}