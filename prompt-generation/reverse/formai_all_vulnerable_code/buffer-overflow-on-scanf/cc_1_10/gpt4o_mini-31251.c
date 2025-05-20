//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to encrypt a message using a basic substitution cipher
char *encrypt(char *message, int shift) {
    char *encrypted = malloc(strlen(message) + 1);
    if (!encrypted) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (int i = 0; message[i] != '\0'; i++) {
        char c = message[i];

        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            encrypted[i] = (c - base + shift) % ALPHABET_SIZE + base;
        } else {
            encrypted[i] = c; // Non-alphabet characters remain unchanged
        }
    }
    encrypted[strlen(message)] = '\0'; // Null-terminate the string
    return encrypted;
}

// Function to decrypt a message using the same substitution cipher
char *decrypt(char *message, int shift) {
    return encrypt(message, ALPHABET_SIZE - shift); // Decryption is simply a reverse shift
}

// Function to display the menu
void displayMenu() {
    printf("Caesar Cipher Program\n");
    printf("=======================\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
}

// Main function to run the program
int main() {
    int choice;
    char message[256];
    int shift;

    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character after scanf

        switch (choice) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove trailing newline

                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);
                getchar(); // Consume the newline character

                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value. Please enter a value between 1 and 25.\n");
                    break;
                }

                char *encrypted_message = encrypt(message, shift);
                printf("Encrypted message: %s\n\n", encrypted_message);
                free(encrypted_message);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove trailing newline

                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);
                getchar(); // Consume the newline character

                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value. Please enter a value between 1 and 25.\n");
                    break;
                }

                char *decrypted_message = decrypt(message, shift);
                printf("Decrypted message: %s\n\n", decrypted_message);
                free(decrypted_message);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }

    return 0;
}