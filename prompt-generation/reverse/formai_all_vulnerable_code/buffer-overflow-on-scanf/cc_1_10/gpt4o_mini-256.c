//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024
#define SHIFT 3 // Number of positions to shift for Caesar Cipher

// Function to encrypt the text using Caesar Cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            text[i] = (ch + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            text[i] = (ch + shift - 'a') % 26 + 'a';
        }
        // Non-alphabetic characters remain unchanged
    }
}

// Function to decrypt the text using Caesar Cipher
void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            text[i] = (ch - shift - 'A' + 26) % 26 + 'A'; // +26 for wrap-around
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            text[i] = (ch - shift - 'a' + 26) % 26 + 'a'; // +26 for wrap-around
        }
        // Non-alphabetic characters remain unchanged
    }
}

// Function to display the current menu options
void display_menu() {
    printf("Caesar Cipher Program\n");
    printf("1. Encrypt text\n");
    printf("2. Decrypt text\n");
    printf("3. Exit\n");
    printf("Select an option: ");
}

// Main function
int main() {
    char text[MAX_TEXT_LENGTH];
    int choice;
    
    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar();  // Consume newline character left in buffer

        switch (choice) {
            case 1:
                printf("Enter text to encrypt: ");
                fgets(text, MAX_TEXT_LENGTH, stdin);
                text[strcspn(text, "\n")] = 0;  // Remove trailing newline
                encrypt(text, SHIFT);
                printf("Encrypted text: %s\n", text);
                break;

            case 2:
                printf("Enter text to decrypt: ");
                fgets(text, MAX_TEXT_LENGTH, stdin);
                text[strcspn(text, "\n")] = 0;  // Remove trailing newline
                decrypt(text, SHIFT);
                printf("Decrypted text: %s\n", text);
                break;

            case 3:
                printf("Exiting program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}