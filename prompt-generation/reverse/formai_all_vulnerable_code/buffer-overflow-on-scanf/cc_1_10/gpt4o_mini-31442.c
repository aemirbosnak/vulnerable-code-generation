//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: enthusiastic
#include <stdio.h>
#include <string.h>

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        // Encrypt uppercase letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] + shift - 'a') % 26 + 'a';
        }
    }
}

void decrypt(char *text, int shift) {
    // For decryption, we simply shift in the opposite direction
    for (int i = 0; text[i] != '\0'; ++i) {
        // Decrypt uppercase letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - shift + 26 - 'A') % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - shift + 26 - 'a') % 26 + 'a';
        }
    }
}

int main() {
    char text[100];
    int shift;

    printf("🎉 Welcome to the C Encryption Program! 🎉\n");
    printf("Please enter the text you want to encrypt: ");
    fgets(text, sizeof(text), stdin);
    
    // Remove newline character from the end of fgets
    text[strcspn(text, "\n")] = '\0';

    printf("Enter the shift value (1 to 25): ");
    scanf("%d", &shift);
    
    // Ensure the shift value is valid
    if (shift < 1 || shift > 25) {
        printf("⚠️ Invalid shift value! Please run the program again with a valid shift (1-25).\n");
        return 1;
    }

    // Make a copy of the original text for decryption
    char encryptedText[100];
    strcpy(encryptedText, text);

    // Encrypt the original text
    encrypt(encryptedText, shift);
    printf("🔒 Encrypted Text: %s\n", encryptedText);

    // Decrypt the text to verify
    decrypt(encryptedText, shift);
    printf("🔓 Decrypted Text (for verification): %s\n", encryptedText);

    printf("🎉 Thank you for using the C Encryption Program! 🎉\n");
    return 0;
}