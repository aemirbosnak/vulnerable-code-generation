//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>

#define MAX_MSG_LENGTH 100

// Function to encrypt the message using Caesar Cipher
void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Check if the character is an uppercase letter
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        // Check if the character is a lowercase letter
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }

        message[i] = ch; // Updating the character in the message
    }
}

// Function to decrypt the message using Caesar Cipher
void decrypt(char *message, int shift) {
    encrypt(message, 26 - (shift % 26)); // Decrypting by reversing the shift
}

// Function to display the menu of operations
void displayMenu() {
    printf("Caesar Cipher Encryption Program\n");
    printf("1. Encrypt a Message\n");
    printf("2. Decrypt a Message\n");
    printf("3. Exit\n");
    printf("Please select an option: ");
}

// Main function that drives the program
int main() {
    char message[MAX_MSG_LENGTH];
    int shift;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice); // User input for menu selection
        
        // Clear buffer to read the string correctly
        while ((getchar()) != '\n');

        switch (choice) {
            case 1: // Encrypt
                printf("Enter the message to encrypt: ");
                fgets(message, MAX_MSG_LENGTH, stdin);
                message[strcspn(message, "\n")] = 0; // Remove trailing newline

                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);

                if(shift < 1 || shift > 25) {
                    printf("Invalid shift value. Please enter a value between 1 and 25.\n");
                } else {
                    encrypt(message, shift);
                    printf("Encrypted message: %s\n", message);
                }
                break;

            case 2: // Decrypt
                printf("Enter the message to decrypt: ");
                fgets(message, MAX_MSG_LENGTH, stdin);
                message[strcspn(message, "\n")] = 0; // Remove trailing newline

                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);

                if(shift < 1 || shift > 25) {
                    printf("Invalid shift value. Please enter a value between 1 and 25.\n");
                } else {
                    decrypt(message, shift);
                    printf("Decrypted message: %s\n", message);
                }
                break;

            case 3: // Exit
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}