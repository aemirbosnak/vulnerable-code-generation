//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt(char *message, int shift);
void decrypt(char *message, int shift);
void validateInput(int shift);

// Main function
int main() {
    char message[256];
    int shift;

    printf("🎉 Welcome to the Caesar Cipher Encryption Program! 🎉\n");
    printf("Enter your message to encrypt: ");
    fgets(message, sizeof(message), stdin);
    
    // Remove newline character if exists
    message[strcspn(message, "\n")] = 0;

    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);
    
    // Validate the shift value
    validateInput(shift);

    // Encrypt the message
    encrypt(message, shift);
    printf("🔒 Encrypted message: %s\n", message);
    
    // Decrypt the message
    decrypt(message, shift);
    printf("🔓 Decrypted message: %s\n", message);
    
    printf("✨ Thank you for using the Caesar Cipher Program! ✨\n");
    return 0;
}

// Encrypt function
void encrypt(char *message, int shift) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            // Shift lowercase letters
            ch = ((ch - 'a' + shift) % 26) + 'a';
            message[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            // Shift uppercase letters
            ch = ((ch - 'A' + shift) % 26) + 'A';
            message[i] = ch;
        }
        // Other characters remain unchanged
    }
}

// Decrypt function
void decrypt(char *message, int shift) {
    // Decryption is simply shifting in the opposite direction
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        if (ch >= 'a' && ch <= 'z') {
            // Reverse shift for lowercase letters
            ch = ((ch - 'a' - shift + 26) % 26) + 'a';
            message[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            // Reverse shift for uppercase letters
            ch = ((ch - 'A' - shift + 26) % 26) + 'A';
            message[i] = ch;
        }
        // Other characters remain unchanged
    }
}

// Function to validate input
void validateInput(int shift) {
    if (shift < 1 || shift > 25) {
        printf("⚠️ Invalid shift value! Please enter a number between 1 and 25.\n");
        exit(EXIT_FAILURE);
    }
}