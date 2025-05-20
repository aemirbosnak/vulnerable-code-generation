//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt a given text using a Caesar cipher
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = text[i];

        // Handle uppercase letters
        if (isupper(ch)) {
            text[i] = (ch + shift - 'A') % 26 + 'A';
        }
        // Handle lowercase letters
        else if (islower(ch)) {
            text[i] = (ch + shift - 'a') % 26 + 'a';
        }
        // Non-alphabetic characters remain unchanged
    }
}

int main() {
    int shift;
    char text[256];

    printf("🎉 Welcome to the Happy Caesar Cipher Encryption Program! 🎉\n");
    printf("Please enter a shift value (1 to 25): ");
    scanf("%d", &shift);

    // Ensure shift is between 1 and 25
    if (shift < 1 || shift > 25) {
        printf("😢 Oops! The shift value must be between 1 and 25! Please restart the program.\n");
        return 1;
    }

    // Clear the newline character left by scanf
    while (getchar() != '\n');

    printf("✨ Please enter the text you wish to encrypt: ");
    fgets(text, sizeof(text), stdin);

    // Remove newline character from the end of the input
    text[strcspn(text, "\n")] = '\0';

    // Perform encryption
    encrypt(text, shift);

    // Display the result
    printf("🚀 Your encrypted text is: %s\n", text);
    printf("🙌 Thank you for using the Happy Caesar Cipher! Have a great day! 🌟\n");

    return 0;
}