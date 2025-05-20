//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: happy
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 100

void encrypt(char *text, int shift);
void decrypt(char *text, int shift);

int main() {
    char input[MAX_LENGTH];
    int shift;
    char choice;

    printf("🎉 Welcome to the Happy Encryption Program! 🎉\n");
    printf("This program will help you encrypt and decrypt your messages happily! 😊\n\n");

    while (1) {
        printf("Please enter your message (up to %d characters): ", MAX_LENGTH - 1);
        fgets(input, MAX_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0; // Remove newline character

        printf("☀️ Enter a shift value (1-25) for encryption: ");
        scanf("%d", &shift);
        getchar(); // to consume the newline character after the integer input

        if (shift < 1 || shift > 25) {
            printf("❌ The shift value should be between 1 and 25! Please try again.\n");
            continue;
        }

        // Encrypt the message
        char encrypted[MAX_LENGTH];
        strcpy(encrypted, input);
        encrypt(encrypted, shift);
        printf("🛡️ Your encrypted message: %s\n", encrypted);

        // Decrypt the message
        char decrypted[MAX_LENGTH];
        strcpy(decrypted, encrypted);
        decrypt(decrypted, shift);
        printf("💌 Your decrypted message: %s\n", decrypted);

        printf("\nWould you like to try again? (y/n): ");
        scanf(" %c", &choice);
        getchar(); // to consume the newline character
        if (choice != 'y' && choice != 'Y') {
            printf("🥳 Thank you for using the Happy Encryption Program! Goodbye! 👋\n");
            break;
        }
    }

    return 0;
}

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];

        // Encrypt uppercase letters
        if (isupper(ch)) {
            text[i] = (ch + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(ch)) {
            text[i] = (ch + shift - 'a') % 26 + 'a';
        }
        // Do not encrypt non-alphabetic characters
    }
}

void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];

        // Decrypt uppercase letters
        if (isupper(ch)) {
            text[i] = (ch - shift + 26 - 'A') % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (islower(ch)) {
            text[i] = (ch - shift + 26 - 'a') % 26 + 'a';
        }
        // Do not decrypt non-alphabetic characters
    }
}