//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 1024

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char current_char = text[i];
        // Encrypt uppercase letters
        if (isupper(current_char)) {
            text[i] = (current_char + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(current_char)) {
            text[i] = (current_char + shift - 'a') % 26 + 'a';
        }
    }
}

void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char current_char = text[i];
        // Decrypt uppercase letters
        if (isupper(current_char)) {
            text[i] = (current_char - shift - 'A' + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (islower(current_char)) {
            text[i] = (current_char - shift - 'a' + 26) % 26 + 'a';
        }
    }
}

int main() {
    char text[MAX_TEXT_LENGTH];
    int shift;
    char choice;

    printf("Welcome to the Caesar Cipher Encryption Program!\n");
    do {
        printf("Enter the text to be encrypted: ");
        fgets(text, MAX_TEXT_LENGTH, stdin);
        // Remove newline character from fgets input
        text[strcspn(text, "\n")] = '\0';

        printf("Enter the shift value (1-25): ");
        scanf("%d", &shift);
        // Clear the newline character left by scanf
        getchar();

        // Input validation for shift value
        if (shift < 1 || shift > 25) {
            printf("Invalid shift value. Please enter a number between 1 and 25.\n");
            continue;
        }

        encrypt(text, shift);
        printf("Encrypted text: %s\n", text);

        decrypt(text, shift);
        printf("Decrypted text: %s\n", text);

        printf("Do you want to encrypt/decrypt another text? (Y/N): ");
        choice = getchar();
        // Clear the input buffer
        getchar();

    } while (toupper(choice) == 'Y');

    printf("Thank you for using the Caesar Cipher Program!\n");
    return 0;
}