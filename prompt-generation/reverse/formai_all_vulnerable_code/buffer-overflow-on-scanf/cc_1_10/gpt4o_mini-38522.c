//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: active
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256

void encrypt(char *message, int shift) {
    for (int i = 0; i < strlen(message); i++) {
        char c = message[i];

        // Encrypt uppercase letters
        if (isupper(c)) {
            message[i] = (c + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(c)) {
            message[i] = (c + shift - 'a') % 26 + 'a';
        }
    }
}

void decrypt(char *message, int shift) {
    // Decryption is simply shifting in the opposite direction
    for (int i = 0; i < strlen(message); i++) {
        char c = message[i];

        // Decrypt uppercase letters
        if (isupper(c)) {
            message[i] = (c - shift - 'A' + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (islower(c)) {
            message[i] = (c - shift - 'a' + 26) % 26 + 'a';
        }
    }
}

int main() {
    char message[MAX_LENGTH];
    int shift;
    char choice;

    printf("Welcome to the Caesar Cipher Program!\n");
    printf("Enter your message: ");
    fgets(message, MAX_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character

    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);
    if (shift < 1 || shift > 25) {
        printf("Shift value must be between 1 and 25.\n");
        return 1;
    }

    printf("Do you want to (e)ncrypt or (d)ecrypt the message? ");
    getchar(); // Consume newline left by scanf
    choice = getchar();

    switch (choice) {
        case 'e':
        case 'E':
            encrypt(message, shift);
            printf("Encrypted message: %s\n", message);
            break;

        case 'd':
        case 'D':
            decrypt(message, shift);
            printf("Decrypted message: %s\n", message);
            break;

        default:
            printf("Invalid choice! Please choose 'e' for encrypt or 'd' for decrypt.\n");
            return 1;
    }

    printf("Thank you for using the Caesar Cipher Program!\n");
    return 0;
}