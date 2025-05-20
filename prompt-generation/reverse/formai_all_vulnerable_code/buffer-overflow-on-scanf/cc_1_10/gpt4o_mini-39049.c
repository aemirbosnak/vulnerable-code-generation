//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: high level of detail
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char c = text[i];

        // Encrypt uppercase letters
        if (isupper(c)) {
            text[i] = (c + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(c)) {
            text[i] = (c + shift - 'a') % 26 + 'a';
        }
    }
}

void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char c = text[i];

        // Decrypt uppercase letters
        if (isupper(c)) {
            text[i] = (c - shift - 'A' + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (islower(c)) {
            text[i] = (c - shift - 'a' + 26) % 26 + 'a';
        }
    }
}

int main() {
    char text[MAX_LEN];
    int shift;
    int choice;

    printf("Welcome to the Simple Caesar Cipher Encryption Program!\n");
    printf("Please enter a string to encrypt (max 255 characters): ");
    fgets(text, MAX_LEN, stdin);
    text[strcspn(text, "\n")] = 0;  // Remove trailing newline

    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);

    // Ensure shift is valid
    if (shift < 1 || shift > 25) {
        printf("Invalid shift value. Please enter a value between 1 and 25.\n");
        return 1;
    }

    printf("Choose an option:\n1. Encrypt\n2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(text, shift);
            printf("Encrypted text: %s\n", text);
            break;
        case 2:
            decrypt(text, shift);
            printf("Decrypted text: %s\n", text);
            break;
        default:
            printf("Invalid choice. Please select either 1 or 2.\n");
            return 1;
    }

    return 0;
}