//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the given message using Caesar Cipher
void encrypt(char *message, int shift) {
    for(int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
            message[i] = ch;
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
            message[i] = ch;
        }
    }
}

// Function to decrypt the given message using Caesar Cipher
void decrypt(char *message, int shift) {
    for(int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - shift + 26) % 26 + 'A';
            message[i] = ch;
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - shift + 26) % 26 + 'a';
            message[i] = ch;
        }
    }
}

// Function to display the menu and get user input
void displayMenu() {
    printf("Caesar Cipher Program\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");
}

int main() {
    int choice, shift;
    char message[256];

    while(1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: // Encryption
                printf("Enter the message to encrypt: ");
                getchar(); // clear the newline left by previous scanf
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // remove newline character
                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);
                
                // Validate shift value
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value. Please enter a value between 1 and 25.\n");
                    break;
                }

                encrypt(message, shift);
                printf("Encrypted message: %s\n", message);
                break;

            case 2: // Decryption
                printf("Enter the message to decrypt: ");
                getchar(); // clear the newline left by previous scanf
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; // remove newline character
                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);
                
                // Validate shift value
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value. Please enter a value between 1 and 25.\n");
                    break;
                }

                decrypt(message, shift);
                printf("Decrypted message: %s\n", message);
                break;

            case 3: // Exit
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
        }
    }

    return 0;
}