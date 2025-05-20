//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using Caesar cipher
void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            message[i] = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            message[i] = (ch - 'a' + shift) % 26 + 'a';
        }
    }
}

// Function to decrypt the message using Caesar cipher
void decrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            message[i] = (ch - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            message[i] = (ch - 'a' - shift + 26) % 26 + 'a';
        }
    }
}

// Function to display the menu
void displayMenu() {
    printf("Welcome to the Caesar Cipher Program!\n");
    printf("Please choose an option:\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
}

// Main function
int main() {
    int choice;
    char message[256];
    int shift;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a message to encrypt: ");
                getchar(); // Consume the newline character
                fgets(message, sizeof(message), stdin);
                
                // Remove newline character if present
                message[strcspn(message, "\n")] = 0;

                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);

                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! It should be between 1 and 25.\n");
                    continue;
                }
                
                encrypt(message, shift);
                printf("Encrypted message: %s\n\n", message);
                break;

            case 2:
                printf("Enter a message to decrypt: ");
                getchar(); // Consume the newline character
                fgets(message, sizeof(message), stdin);
                
                // Remove newline character if present
                message[strcspn(message, "\n")] = 0;

                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);

                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! It should be between 1 and 25.\n");
                    continue;
                }

                decrypt(message, shift);
                printf("Decrypted message: %s\n\n", message);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please choose again.\n\n");
        }
    }

    return 0;
}