//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt(char *plaintext, int shift);
void decrypt(char *ciphertext, int shift);
void displayMenu();

int main() {
    char text[100];
    int shift, choice;

    printf("Surprise! Welcome to the Simple Cryptography Program!\n");
    displayMenu();
    
    printf("Please choose an option (1 or 2): ");
    scanf("%d", &choice);

    // Input validation for choice
    if (choice < 1 || choice > 2) {
        printf("Invalid choice! Please run the program again.\n");
        return 1;
    }

    printf("Enter your text (max 99 characters): ");
    getchar(); // consume the newline character left by scanf
    fgets(text, sizeof(text), stdin);
    
    // Remove the newline character from the input
    text[strcspn(text, "\n")] = 0;

    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);

    // Ensure shift is within valid range
    if (shift < 1 || shift > 25) {
        printf("Invalid shift value! Please run the program again.\n");
        return 1;
    }

    if (choice == 1) {
        printf("Encrypting your text...\n");
        encrypt(text, shift);
    } else {
        printf("Decrypting your text...\n");
        decrypt(text, shift);
    }

    return 0;
}

void encrypt(char *plaintext, int shift) {
    char ciphertext[100];
    int i;

    for (i = 0; plaintext[i] != '\0'; ++i) {
        char ch = plaintext[i];

        if (ch >= 'a' && ch <= 'z') {
            ciphertext[i] = (ch + shift - 'a') % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ciphertext[i] = (ch + shift - 'A') % 26 + 'A';
        } else {
            ciphertext[i] = ch; // Non-alphabetic characters remain unchanged
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the string
    printf("Encrypted text: %s\n", ciphertext);
}

void decrypt(char *ciphertext, int shift) {
    char decryptedtext[100];
    int i;

    for (i = 0; ciphertext[i] != '\0'; ++i) {
        char ch = ciphertext[i];

        if (ch >= 'a' && ch <= 'z') {
            decryptedtext[i] = (ch - shift - 'a' + 26) % 26 + 'a'; // Adding 26 to handle negative indexing
        } else if (ch >= 'A' && ch <= 'Z') {
            decryptedtext[i] = (ch - shift - 'A' + 26) % 26 + 'A'; // Adding 26 to handle negative indexing
        } else {
            decryptedtext[i] = ch; // Non-alphabetic characters remain unchanged
        }
    }
    decryptedtext[i] = '\0'; // Null-terminate the string
    printf("Decrypted text: %s\n", decryptedtext);
}

void displayMenu() {
    printf("1. Encrypt text\n");
    printf("2. Decrypt text\n");
}