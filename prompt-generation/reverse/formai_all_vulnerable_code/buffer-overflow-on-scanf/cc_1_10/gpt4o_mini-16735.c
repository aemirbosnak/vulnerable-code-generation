//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: surprised
#include <stdio.h>
#include <string.h>

// Function to encrypt the text using Caesar Cipher technique
void encrypt(char *text, int shift) {
    char *original_text = text;
    while (*text) {
        // Encrypt uppercase letters
        if (*text >= 'A' && *text <= 'Z') {
            *text = ((*text - 'A' + shift) % 26) + 'A';
        }
        // Encrypt lowercase letters
        else if (*text >= 'a' && *text <= 'z') {
            *text = ((*text - 'a' + shift) % 26) + 'a';
        }
        text++;
    }
    printf("✨ Encrypted Text: %s\n", original_text);
}

// Function to decrypt the text using Caesar Cipher technique
void decrypt(char *text, int shift) {
    char *original_text = text;
    while (*text) {
        // Decrypt uppercase letters
        if (*text >= 'A' && *text <= 'Z') {
            *text = ((*text - 'A' - shift + 26) % 26) + 'A';
        }
        // Decrypt lowercase letters
        else if (*text >= 'a' && *text <= 'z') {
            *text = ((*text - 'a' - shift + 26) % 26) + 'a';
        }
        text++;
    }
    printf("🔑 Decrypted Text: %s\n", original_text);
}

int main() {
    char text[100];
    int shift;

    // Welcome Message
    printf("🎉 Welcome to the Magical Encryption Program! 🎉\n");
    printf("Please enter the text you want to encrypt: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0'; // Remove newline character

    printf("Choose a shift value (1-25): ");
    scanf("%d", &shift);
    
    // Ensuring shift is within valid range
    if (shift < 1 || shift > 25) {
        printf("🚫 Invalid shift value! It must be between 1 and 25.\n");
        return 1;
    }

    // Encrypting the input text
    encrypt(text, shift);

    // Decrypting the text back to original
    decrypt(text, shift);

    // Thank You Message
    printf("🌟 Thank you for using the Magical Encryption Program! 🌟\n");
    return 0;
}