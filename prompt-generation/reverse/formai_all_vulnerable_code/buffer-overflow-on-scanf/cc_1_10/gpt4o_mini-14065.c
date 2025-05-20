//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

// Function to encrypt a text using Caesar Cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        // Encrypt uppercase letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        }
    }
}

// Function to decrypt a text using Caesar Cipher
void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        // Decrypt uppercase letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' - shift + 26) % 26 + 'a';
        }
    }
}

// Function to display menu and read user choice
void displayMenu() {
    printf("Caesar Cipher - Encryption and Decryption Tool\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Exit\n");
    printf("Please select an option (1-3): ");
}

// Main function
int main() {
    char text[256]; // Buffer for storing text
    int shift, choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        // Handle choice
        switch (choice) {
            case 1:
                printf("Enter text to encrypt: ");
                scanf(" %[^\n]", text); // Read line including spaces
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Shift value must be between 1 and 25.\n");
                    continue;
                }
                encrypt(text, shift);
                printf("Encrypted text: %s\n", text);
                break;

            case 2:
                printf("Enter text to decrypt: ");
                scanf(" %[^\n]", text); // Read line including spaces
                printf("Enter shift value (1-25): ");
                scanf("%d", &shift);
                if (shift < 1 || shift > 25) {
                    printf("Shift value must be between 1 and 25.\n");
                    continue;
                }
                decrypt(text, shift);
                printf("Decrypted text: %s\n", text);
                break;

            case 3:
                printf("Exiting the program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}