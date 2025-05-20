//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *text, int shift);
void decrypt(char *text, int shift);

int main() {
    char text[1000];
    int shift;
    int choice;

    printf("Welcome to the Simple Encryption Program!\n");
    printf("Choose an option:\n");
    printf("1. Encrypt a message\n");
    printf("2. Decrypt a message\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);
    getchar(); // Clear newline from input buffer

    if (choice == 1) {
        printf("Enter the message to encrypt: ");
        fgets(text, sizeof(text), stdin);
        printf("Enter the shift value (0-25): ");
        scanf("%d", &shift);
        encrypt(text, shift);
    } else if (choice == 2) {
        printf("Enter the message to decrypt: ");
        fgets(text, sizeof(text), stdin);
        printf("Enter the shift value (0-25): ");
        scanf("%d", &shift);
        decrypt(text, shift);
    } else {
        printf("Invalid choice! Please restart the program.\n");
        return 1;
    }

    return 0;
}

void encrypt(char *text, int shift) {
    char ch;
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch + shift - 'A') % 26 + 'A';
            text[i] = ch;
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch + shift - 'a') % 26 + 'a';
            text[i] = ch;
        }
    }
    printf("Encrypted message: %s", text);
}

void decrypt(char *text, int shift) {
    char ch;
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - shift - 'A' + 26) % 26 + 'A';
            text[i] = ch;
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - shift - 'a' + 26) % 26 + 'a';
            text[i] = ch;
        }
    }
    printf("Decrypted message: %s", text);
}