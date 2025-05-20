//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        // Encrypt uppercase letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        }
    }
}

void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        // Decrypt uppercase letters
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = (text[i] - 'A' - shift + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' - shift + 26) % 26 + 'a';
        }
    }
}

int main() {
    char text[256];
    int shift, choice;

    printf("Welcome to the Brave C Encryption Program!\n");
    printf("Enter your secret message (max 255 characters): ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline character

    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);
    if (shift < 1 || shift > 25) {
        printf("Invalid shift value! It must be between 1 and 25.\n");
        return 1;
    }

    printf("Choose an option:\n");
    printf("1. Encrypt the message\n");
    printf("2. Decrypt the message\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            encrypt(text, shift);
            printf("Encrypted message: %s\n", text);
            break;
        case 2:
            decrypt(text, shift);
            printf("Decrypted message: %s\n", text);
            break;
        default:
            printf("Invalid choice! Please enter 1 or 2.\n");
            return 1;
    }

    printf("Thank you for using the Brave C Encryption Program! Stay secure.\n");
    return 0;
}