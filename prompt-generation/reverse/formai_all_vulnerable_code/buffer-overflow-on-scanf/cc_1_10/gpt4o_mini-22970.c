//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1024

void encrypt(char *plaintext, int shift, char *ciphertext) {
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++) {
        char c = plaintext[i];
        if (isalpha(c)) { // Check if the character is an alphabet
            char base = islower(c) ? 'a' : 'A';
            // Shift within the bounds of 'a' to 'z' or 'A' to 'Z'
            ciphertext[i] = (c - base + shift) % 26 + base;
        } else {
            ciphertext[i] = c; // Non-alphabet characters remain unchanged
        }
    }
    ciphertext[length] = '\0'; // Null-terminate the ciphertext string
}

void decrypt(char *ciphertext, int shift, char *plaintext) {
    int length = strlen(ciphertext);
    for (int i = 0; i < length; i++) {
        char c = ciphertext[i];
        if (isalpha(c)) { // Check if the character is an alphabet
            char base = islower(c) ? 'a' : 'A';
            // Reverse shift within the bounds of 'a' to 'z' or 'A' to 'Z'
            plaintext[i] = (c - base - shift + 26) % 26 + base;
        } else {
            plaintext[i] = c; // Non-alphabet characters remain unchanged
        }
    }
    plaintext[length] = '\0'; // Null-terminate the plaintext string
}

int main() {
    char plaintext[MAX_LEN], ciphertext[MAX_LEN], decryptedtext[MAX_LEN];
    int shift;

    printf("Welcome to the Caesar Cipher Encryption/Decryption Program!\n");
    
    // Prompt for the shift value
    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);

    // Ensure the shift value is within bounds
    shift = (shift >= 1 && shift <= 25) ? shift : 3; // Default to 3 if out of bounds

    // Get plaintext from user
    printf("Enter the plaintext to encrypt: ");
    getchar(); // To clear the newline character from the buffer
    fgets(plaintext, MAX_LEN, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // Remove the trailing newline character

    // Encrypt the plaintext
    encrypt(plaintext, shift, ciphertext);
    printf("Encrypted ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, shift, decryptedtext);
    printf("Decrypted plaintext: %s\n", decryptedtext);

    return 0;
}