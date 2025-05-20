//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: protected
#include <stdio.h>
#include <string.h>

#define MAX_LEN 256

// Function to encrypt a plaintext message
void encrypt(char *plaintext, int shift, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char c = plaintext[i];
        // Encrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            ciphertext[i] = (c + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            ciphertext[i] = (c + shift - 'a') % 26 + 'a';
        }
        // Non-alphabetic characters remain unchanged
        else {
            ciphertext[i] = c;
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the ciphertext
}

// Function to decrypt a ciphertext message
void decrypt(char *ciphertext, int shift, char *plaintext) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        char c = ciphertext[i];
        // Decrypt uppercase letters
        if (c >= 'A' && c <= 'Z') {
            plaintext[i] = (c - shift + 26 - 'A') % 26 + 'A'; // +26 for negative wrap-around
        }
        // Decrypt lowercase letters
        else if (c >= 'a' && c <= 'z') {
            plaintext[i] = (c - shift + 26 - 'a') % 26 + 'a';
        }
        // Non-alphabetic characters remain unchanged
        else {
            plaintext[i] = c;
        }
    }
    plaintext[i] = '\0'; // Null-terminate the plaintext
}

int main() {
    char plaintext[MAX_LEN];
    char ciphertext[MAX_LEN];
    char decryptedtext[MAX_LEN];
    int shift;

    printf("Welcome to the Caesar Cipher Encryption Program!\n");
    
    printf("Enter the plaintext (max %d characters): ", MAX_LEN - 1);
    fgets(plaintext, MAX_LEN, stdin);
    // Remove newline character from input
    plaintext[strcspn(plaintext, "\n")] = 0;

    printf("Enter the shift value (a positive integer): ");
    scanf("%d", &shift);
    
    // Ensure shift is within 0-25
    shift = shift % 26;

    // Encrypt the plaintext
    encrypt(plaintext, shift, ciphertext);
    printf("Encrypted message: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, shift, decryptedtext);
    printf("Decrypted message: %s\n", decryptedtext);

    return 0;
}