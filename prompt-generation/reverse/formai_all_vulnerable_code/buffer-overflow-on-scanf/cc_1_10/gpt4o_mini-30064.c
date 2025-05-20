//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the plaintext using Caesar Cipher
void encrypt(char *plaintext, int shift, char *ciphertext) {
    for (int i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        if (ch >= 'a' && ch <= 'z') {
            ciphertext[i] = (ch - 'a' + shift) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            ciphertext[i] = (ch - 'A' + shift) % 26 + 'A';
        } else {
            ciphertext[i] = ch; // Non-alphabetic characters remain unchanged
        }
    }
    ciphertext[strlen(plaintext)] = '\0'; // Null-terminate the ciphertext
}

// Function to decrypt the ciphertext using Caesar Cipher
void decrypt(char *ciphertext, int shift, char *plaintext) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];
        if (ch >= 'a' && ch <= 'z') {
            plaintext[i] = (ch - 'a' - shift + 26) % 26 + 'a';
        } else if (ch >= 'A' && ch <= 'Z') {
            plaintext[i] = (ch - 'A' - shift + 26) % 26 + 'A';
        } else {
            plaintext[i] = ch; // Non-alphabetic characters remain unchanged
        }
    }
    plaintext[strlen(ciphertext)] = '\0'; // Null-terminate the plaintext
}

// Main function to drive the encryption and decryption process
int main() {
    char plaintext[256], ciphertext[256], decrypted[256];
    int shift;
    
    printf("Welcome to the Caesar Cipher Program!\n");
    printf("Enter the shift value (1 - 25): ");
    scanf("%d", &shift);
    
    // Ensuring the shift value is within bounds
    if (shift < 1 || shift > 25) {
        printf("Invalid shift value! Please run the program again with a valid shift value.\n");
        return 1;
    }

    // Clear the input buffer
    while ((getchar()) != '\n');

    printf("Enter the plaintext (max 255 characters): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // Remove the trailing newline character

    // Encrypt the message
    encrypt(plaintext, shift, ciphertext);
    printf("Encrypted message: %s\n", ciphertext);

    // Decrypt the message
    decrypt(ciphertext, shift, decrypted);
    printf("Decrypted message: %s\n", decrypted);

    // Exit message
    printf("Thank you for using the Caesar Cipher Program! Goodbye!\n");
    return 0;
}