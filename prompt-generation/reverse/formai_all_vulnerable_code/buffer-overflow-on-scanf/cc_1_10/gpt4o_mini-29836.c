//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: mind-bending
#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

void encrypt(char *message, int shift) {
    for(int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Encrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            message[i] = (ch + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            message[i] = (ch + shift - 'a') % 26 + 'a';
        }
        // Non-alphabetic characters are unchanged
    }
}

void decrypt(char *message, int shift) {
    for(int i = 0; message[i] != '\0'; i++) {
        char ch = message[i];

        // Decrypt uppercase letters
        if (ch >= 'A' && ch <= 'Z') {
            message[i] = (ch - shift - 'A' + 26) % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (ch >= 'a' && ch <= 'z') {
            message[i] = (ch - shift - 'a' + 26) % 26 + 'a';
        }
        // Non-alphabetic characters are unchanged
    }
}

int main() {
    char message[MAX_LEN];
    int shift, choice;

    printf("Welcome to the Mind-Bending Cryptography Program!\n");
    printf("Enter a string to encrypt or decrypt (Max %d characters):\n", MAX_LEN - 1);
    fgets(message, MAX_LEN, stdin);
    message[strcspn(message, "\n")] = 0; // Removing any trailing newline character

    printf("Choose an option:\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);

    if (shift < 1 || shift > 25) {
        printf("Shift value must be between 1 and 25.\n");
        return 1;
    }

    switch(choice) {
        case 1:
            printf("Original message: %s\n", message);
            encrypt(message, shift);
            printf("Encrypted message: %s\n", message);
            break;

        case 2:
            printf("Original message: %s\n", message);
            decrypt(message, shift);
            printf("Decrypted message: %s\n", message);
            break;

        default:
            printf("Invalid choice! Please run the program again.\n");
            return 1;
    }

    printf("Thank you for using the Mind-Bending Cryptography Program!\n");
    return 0;
}