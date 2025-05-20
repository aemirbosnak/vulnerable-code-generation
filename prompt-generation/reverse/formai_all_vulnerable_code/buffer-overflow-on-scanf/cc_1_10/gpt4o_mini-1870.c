//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt(char *text, int shift);
void decrypt(char *text, int shift);
void clean_newline(char *text);

int main() {
    char text[256];     // Buffer to hold user input
    int shift;         // Variable to hold the shift value
    int choice;        // Variable to hold user choice

    // Instructions for the user
    printf("Welcome to the Caesar Cipher Program!\n");
    printf("Choose an option:\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("3. Exit\n");

    while (1) {
        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from the input buffer

        switch (choice) {
            case 1: // Encrypt
                printf("Enter the message you want to encrypt: ");
                fgets(text, sizeof(text), stdin);
                clean_newline(text); // Remove trailing newline character

                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);
                
                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please enter a number between 1 and 25.\n");
                    break;
                }

                printf("Encrypted message: ");
                encrypt(text, shift);
                printf("\n");
                break;

            case 2: // Decrypt
                printf("Enter the message you want to decrypt: ");
                fgets(text, sizeof(text), stdin);
                clean_newline(text); // Remove trailing newline character

                printf("Enter the shift value (1-25): ");
                scanf("%d", &shift);

                if (shift < 1 || shift > 25) {
                    printf("Invalid shift value! Please enter a number between 1 and 25.\n");
                    break;
                }

                printf("Decrypted message: ");
                decrypt(text, shift);
                printf("\n");
                break;

            case 3: // Exit
                printf("Thank you for using the Caesar Cipher Program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please enter 1, 2 or 3.\n");
                break;
        }
    }
    return 0;
}

// Function to encrypt the text using Caesar cipher
void encrypt(char *text, int shift) {
    char ch;
    for (int i = 0; text[i] != '\0'; i++) {
        ch = text[i];
        
        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        // Non-alphabetic characters remain the same
        printf("%c", ch);
    }
}

// Function to decrypt the text using Caesar cipher
void decrypt(char *text, int shift) {
    char ch;
    for (int i = 0; text[i] != '\0'; i++) {
        ch = text[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - shift + 26) % 26 + 'a';
        }
        // Non-alphabetic characters remain the same
        printf("%c", ch);
    }
}

// Function to clean newline character from a string
void clean_newline(char *text) {
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }
}