//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the text
void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            text[i] = (text[i] - base + shift) % 26 + base;
        }
    }
}

// Function to decrypt the text
void decrypt(char *text, int shift) {
    // For decryption, we just shift in the opposite direction
    encrypt(text, 26 - shift);
}

// Function to get user input
void getInput(char *text) {
    printf("Enter text: ");
    fgets(text, 256, stdin);
    text[strcspn(text, "\n")] = 0; // Remove newline character
}

int main() {
    char text[256];
    int shift, choice;

    printf("Caesar Cipher Encryption/Decryption\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Choose an option (1/2): ");
    scanf("%d", &choice);
    printf("Enter shift value (1-25): ");
    scanf("%d", &shift);

    // Reset stdin to read the string input correctly after integer input
    while ((getchar()) != '\n'); // Clear newline from the input buffer
    
    if (shift < 1 || shift > 25) {
        printf("Shift value must be between 1 and 25.\n");
        return 1;
    }

    getInput(text);

    if (choice == 1) {
        encrypt(text, shift);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 2) {
        decrypt(text, shift);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid option selected.\n");
        return 1;
    }

    return 0;
}