//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LENGTH 256

// Function to encrypt the message using a Caesar cipher
void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char currentChar = message[i];

        // Check if the character is an uppercase letter
        if (currentChar >= 'A' && currentChar <= 'Z') {
            message[i] = (currentChar - 'A' + shift) % 26 + 'A';
        }
        // Check if the character is a lowercase letter
        else if (currentChar >= 'a' && currentChar <= 'z') {
            message[i] = (currentChar - 'a' + shift) % 26 + 'a';
        }
    }
}

// Function to decrypt the message using a Caesar cipher
void decrypt(char *message, int shift) {
    // A shift for decryption is the total range minus the encryption shift
    encrypt(message, 26 - shift);
}

// Function to display menu
void displayMenu() {
    printf("************************\n");
    printf("Welcome to Caesar Cipher!\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("************************\n");
}

// Main function
int main() {
    char message[MAX_MESSAGE_LENGTH];
    int option, shift;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &option);
        getchar(); // clear newline character from input buffer

        switch (option) {
            case 1:
                printf("Enter the message to encrypt: ");
                fgets(message, MAX_MESSAGE_LENGTH, stdin);

                // Remove newline character if it exists
                message[strcspn(message, "\n")] = 0;

                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);

                // Validate shift
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value. Please try again.\n");
                    break;
                }

                encrypt(message, shift);
                printf("Encrypted message: %s\n", message);
                break;

            case 2:
                printf("Enter the message to decrypt: ");
                fgets(message, MAX_MESSAGE_LENGTH, stdin);

                // Remove newline character if it exists
                message[strcspn(message, "\n")] = 0;

                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);

                // Validate shift
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value. Please try again.\n");
                    break;
                }

                decrypt(message, shift);
                printf("Decrypted message: %s\n", message);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;

            default:
                printf("Invalid option. Please choose again.\n");
                break;
        }
    }

    return 0;
}