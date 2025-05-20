//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the message using Caesar Cipher
void encryptMessage(char *message, int shift) {
    char ch;
    for (int i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        // Encrypt uppercase characters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch + shift - 'A') % 26 + 'A';
            message[i] = ch;
        }
        // Encrypt lowercase characters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch + shift - 'a') % 26 + 'a';
            message[i] = ch;
        }
    }
}

// Function to decrypt the message using Caesar Cipher
void decryptMessage(char *message, int shift) {
    char ch;
    for (int i = 0; message[i] != '\0'; ++i) {
        ch = message[i];

        // Decrypt uppercase characters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - shift + 26 - 'A') % 26 + 'A';
            message[i] = ch;
        }
        // Decrypt lowercase characters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - shift + 26 - 'a') % 26 + 'a';
            message[i] = ch;
        }
    }
}

int main() {
    char message[256];
    int shift;

    printf("🎉 Welcome to the Cheerful Caesar Cipher Program! 🎉\n");
    printf("Please enter a message to encrypt (max 255 characters): ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0; // Remove trailing newline

    printf("How many positions would you like to shift? (1-25): ");
    scanf("%d", &shift);
    
    // Validate shift value
    if (shift < 1 || shift > 25) {
        printf("😢 Oops! The shift value is out of bounds, defaulting to 3.\n");
        shift = 3; // Default shift
    }

    printf("🌟 Original Message: %s\n", message);
    
    // Encrypt the message
    encryptMessage(message, shift);
    printf("🎈 Encrypted Message: %s\n", message);
    
    // Decrypt the message
    decryptMessage(message, shift);
    printf("🎊 Decrypted Message: %s\n", message);

    printf("🥳 Thank you for using the Cheerful Caesar Cipher Program! Goodbye! 👋\n");
    return 0;
}