//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to encrypt the text using Caesar Cipher
void encrypt(char *text, int shift) {
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

// Function to decrypt the text using Caesar Cipher
void decrypt(char *text, int shift) {
    encrypt(text, 26 - (shift % 26)); // Decrypt by reversing the shift
}

// Function to get user input for the text
void getUserInput(char *text, int maxLength) {
    printf("🎉 Please enter the text to be encrypted (max %d characters): ", maxLength);
    fgets(text, maxLength, stdin);
    text[strcspn(text, "\n")] = 0; // Remove the trailing newline character
}

// Function to get the shift value from user
int getShiftValue() {
    int shift;
    printf("🚀 Enter the shift value (1 - 25): ");
    scanf("%d", &shift);
    while (shift < 1 || shift > 25) {
        printf("😅 Oops! That's not a valid shift. Try again: ");
        scanf("%d", &shift);
    }
    return shift;
}

// Main function
int main() {
    printf("🌈 Welcome to the Cheerful Encryption Program! 🌈\n");
    
    // Prepare to take user input
    char text[256];
    getUserInput(text, sizeof(text));

    // Get shift value from user
    int shift = getShiftValue();

    // Display original text
    printf("📜 Original Text: %s\n", text);

    // Encrypt the text
    encrypt(text, shift);
    printf("🔒 Encrypted Text: %s\n", text);

    // Decrypt the text back
    decrypt(text, shift);
    printf("🔓 Decrypted Text: %s\n", text);

    printf("✨ Thank you for using the Cheerful Encryption Program! Have a great day! ✨\n");
    return 0;
}