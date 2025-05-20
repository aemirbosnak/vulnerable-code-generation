//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, int shift) {
    char ch;
    printf("🎉🎉 Encrypting your message... 🎉🎉\n");

    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        if (isupper(ch)) {
            text[i] = (ch + shift - 'A') % 26 + 'A'; // Wraps around A-Z
        } else if (islower(ch)) {
            text[i] = (ch + shift - 'a') % 26 + 'a'; // Wraps around a-z
        }
    }

    printf("✨ Encrypted message is: %s ✨\n", text);
}

void decrypt(char *text, int shift) {
    char ch;
    printf("🧐 Decrypting your message... 🧐\n");

    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        if (isupper(ch)) {
            text[i] = (ch - shift - 'A' + 26) % 26 + 'A'; // Wraps around A-Z
        } else if (islower(ch)) {
            text[i] = (ch - shift - 'a' + 26) % 26 + 'a'; // Wraps around a-z
        }
    }

    printf("✨ Decrypted message is: %s ✨\n", text);
}

int main() {
    char text[100];
    int shift;
    
    printf("💬 Welcome to the Caesar Cipher Program! 💬\n");
    printf("Enter a message (only alphabets): ");
    fgets(text, sizeof(text), stdin);
    
    // Remove newline character if present
    text[strcspn(text, "\n")] = 0;

    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);

    if (shift < 1 || shift > 25) {
        printf("😱 Please input a shift value between 1 and 25! 😱\n");
        return 1;
    }

    encrypt(text, shift);
    decrypt(text, shift);

    printf("🌈 Thank you for using the Caesar Cipher! Until next time! 🌈\n");

    return 0;
}