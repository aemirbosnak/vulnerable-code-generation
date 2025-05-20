//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string using a simple Caesar Cipher
void encrypt(char *input, int shift) {
    for (int i = 0; input[i] != '\0'; i++) {
        char current = input[i];
        // Check if it's a lowercase letter
        if (current >= 'a' && current <= 'z') {
            input[i] = (current - 'a' + shift) % 26 + 'a';
        }
        // Check if it's an uppercase letter
        else if (current >= 'A' && current <= 'Z') {
            input[i] = (current - 'A' + shift) % 26 + 'A';
        }
    }
}

// Function to decrypt a string using a simple Caesar Cipher
void decrypt(char *input, int shift) {
    for (int i = 0; input[i] != '\0'; i++) {
        char current = input[i];
        // Check if it's a lowercase letter
        if (current >= 'a' && current <= 'z') {
            input[i] = (current - 'a' - shift + 26) % 26 + 'a';
        }
        // Check if it's an uppercase letter
        else if (current >= 'A' && current <= 'Z') {
            input[i] = (current - 'A' - shift + 26) % 26 + 'A';
        }
    }
}

// Function to display menu
void displayMenu() {
    printf("===== C Encryption Program =====\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("===============================\n");
}

// Main function
int main() {
    int choice;
    const int maxLength = 256;
    char message[maxLength];
    int shift;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(message, maxLength, stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline if present
                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Shift value must be between 1 and 25.\n");
                    break;
                }
                encrypt(message, shift);
                printf("Encrypted message: %s\n", message);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                fgets(message, maxLength, stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline if present
                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Shift value must be between 1 and 25.\n");
                    break;
                }
                decrypt(message, shift);
                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}