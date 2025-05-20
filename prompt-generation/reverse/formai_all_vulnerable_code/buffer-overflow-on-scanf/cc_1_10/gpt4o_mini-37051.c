//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 1024

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' + shift) % 26 + 'a';
        }
    }
    printf("Encrypted Text: %s\n", text);
}

void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        // Decrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            text[i] = (c - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            text[i] = (c - 'a' - shift + 26) % 26 + 'a';
        }
    }
    printf("Decrypted Text: %s\n", text);
}

int main() {
    char text[MAX_TEXT_LENGTH];
    int shift;
    int choice;

    printf("Caesar Cipher Encryption/Decryption Tool\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice (1 or 2): ");
    
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input! Exiting.\n");
        return 1;
    }

    printf("Enter the shift value (1-25): ");
    if (scanf("%d", &shift) != 1 || shift < 1 || shift > 25) {
        printf("Invalid shift value! Exiting.\n");
        return 1;
    }

    // Clear input buffer
    while (getchar() != '\n');

    printf("Enter the text: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
        printf("Error reading input! Exiting.\n");
        return 1;
    }

    // Remove newline character if present
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }

    switch (choice) {
        case 1:
            encrypt(text, shift);
            break;
        case 2:
            decrypt(text, shift);
            break;
        default:
            printf("Invalid choice! Exiting.\n");
            return 1;
    }

    return 0;
}