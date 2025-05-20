//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt a message using a simple Caesar cipher.
void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        if (isalpha(message[i])) {
            char offset = islower(message[i]) ? 'a' : 'A';
            message[i] = (message[i] - offset + shift) % 26 + offset;
        }
    }
}

// Function to decrypt a message using a simple Caesar cipher.
void decrypt(char *message, int shift) {
    encrypt(message, 26 - shift); // Decrypting is just reversing the shift.
}

// Function to display the menu and get user's choice.
int menu() {
    int choice;
    printf("\nSimple Caesar Cipher\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    char message[256];
    int shift, choice;

    while (1) {
        choice = menu();
        switch (choice) {
            case 1: // Encrypt
                printf("Enter a message to encrypt: ");
                getchar();  // Clear newline character from buffer
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value. Please try again.\n");
                    break;
                }
                encrypt(message, shift);
                printf("Encrypted message: %s\n", message);
                break;

            case 2: // Decrypt
                printf("Enter a message to decrypt: ");
                getchar();  // Clear newline character from buffer
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // Remove newline character
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value. Please try again.\n");
                    break;
                }
                decrypt(message, shift);
                printf("Decrypted message: %s\n", message);
                break;

            case 3: // Exit
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}