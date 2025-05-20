//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: cheerful
#include <stdio.h>
#include <string.h>

void encrypt(char plainText[], int shift) {
    char cipherText[100];
    int i;

    for (i = 0; plainText[i] != '\0'; ++i) {
        char ch = plainText[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            cipherText[i] = (ch + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            cipherText[i] = (ch + shift - 'a') % 26 + 'a';
        }
        // If it's not a letter, we keep it the same!
        else {
            cipherText[i] = ch;
        }
    }
    cipherText[i] = '\0'; // Null-terminate the string

    printf("🎉 Encrypted message: %s\n", cipherText);
}

void decrypt(char cipherText[], int shift) {
    char plainText[100];
    int i;

    for (i = 0; cipherText[i] != '\0'; ++i) {
        char ch = cipherText[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            plainText[i] = (ch - shift - 'A' + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            plainText[i] = (ch - shift - 'a' + 26) % 26 + 'a';
        }
        // If it's not a letter, we keep it the same!
        else {
            plainText[i] = ch;
        }
    }
    plainText[i] = '\0'; // Null-terminate the string

    printf("🌈 Decrypted message: %s\n", plainText);
}

int main() {
    char text[100];
    int shift;
    
    printf("🌟 Welcome to the Cheery Caesar Cipher!\n");
    printf("Please enter your message (max 100 characters): ");
    fgets(text, sizeof(text), stdin);
    // Remove the newline character if present
    text[strcspn(text, "\n")] = 0;

    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);

    // Ensure the shift is within the valid range
    if (shift < 1 || shift > 25) {
        printf("🤔 Oops! Please enter a valid shift value between 1 and 25.\n");
        return 1;
    }

    printf("\n✨ Here we go! Encrypting your message...\n");
    encrypt(text, shift);

    printf("\n🔑 And now, let's decrypt it back!\n");
    decrypt(text, shift);

    printf("\n🎊 Thank you for using the Cheery Caesar Cipher. Have a splendid day!\n");
    return 0;
}