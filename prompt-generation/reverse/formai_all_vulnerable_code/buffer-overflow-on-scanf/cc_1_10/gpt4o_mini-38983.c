//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: Ada Lovelace
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt the given text using a simple Caesar Cipher
void encryptText(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char c = text[i];
        
        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            text[i] = (c + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            text[i] = (c + shift - 'a') % 26 + 'a';
        }
    }
}

// Function to decrypt the given text using a simple Caesar Cipher
void decryptText(char *text, int shift) {
    encryptText(text, 26 - shift); // Decrypting is just reversing the shift
}

// Function to display text
void displayText(char *text, const char *action) {
    printf("%s: %s\n", action, text);
}

// Main function
int main() {
    char inputText[256];
    int shift;
    
    // Welcome message
    printf("Welcome to the Ada Lovelace Encryption Program!\n");
    printf("This program utilizes a simple Caesar Cipher for encryption and decryption.\n");

    // Get user input for text
    printf("Please enter the text to be encrypted (up to 255 characters): ");
    fgets(inputText, sizeof(inputText), stdin);
    
    // Remove newline character from the end, if present
    size_t len = strlen(inputText);
    if (len > 0 && inputText[len-1] == '\n') {
        inputText[len-1] = '\0';
    }

    // Get user input for shift value
    printf("Please enter the shift value for encryption (1-25): ");
    scanf("%d", &shift);
    
    if (shift < 1 || shift > 25) {
        printf("Invalid shift value! Please run the program again and enter a value between 1 and 25.\n");
        return 1; // Exit with error code
    }

    // Encrypt and display the text
    encryptText(inputText, shift);
    displayText(inputText, "Encrypted Text");

    // Prepare for decryption
    char decryptedText[256];
    strcpy(decryptedText, inputText); // Copy encrypted text for decryption

    // Decrypt and display the text
    decryptText(decryptedText, shift);
    displayText(decryptedText, "Decrypted Text");

    // Goodbye message
    printf("Thank you for using the Ada Lovelace Encryption Program! Goodbye!\n");

    return 0; // Success
}