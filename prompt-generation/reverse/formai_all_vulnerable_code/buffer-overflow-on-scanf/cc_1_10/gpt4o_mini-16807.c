//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

// Function declarations
void encrypt(char *plaintext, char *ciphertext, int shift);
void decrypt(char *ciphertext, char *plaintext, int shift);
void handle_input(char *input, int *shift);

int main() {
    char plaintext[MAX_LENGTH];
    char ciphertext[MAX_LENGTH];
    char decryptedtext[MAX_LENGTH];
    int shift;

    printf("=== Caesar Cipher Encryption and Decryption ===\n");
    handle_input(plaintext, &shift);
    
    encrypt(plaintext, ciphertext, shift);
    printf("Encrypted text: %s\n", ciphertext);
    
    decrypt(ciphertext, decryptedtext, shift);
    printf("Decrypted text: %s\n", decryptedtext);
    
    return 0;
}

// Function to handle user input for plaintext and shift value
void handle_input(char *input, int *shift) {
    printf("Enter the plaintext (max %d characters): ", MAX_LENGTH - 1);
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // Remove newline character

    printf("Enter the shift value (0-25): ");
    while (scanf("%d", shift) != 1 || *shift < 0 || *shift > 25) {
        printf("Invalid input. Please enter a valid shift value (0-25): ");
        while(getchar() != '\n'); // Clear invalid input
    }
}

// Function to encrypt plaintext using Caesar cipher
void encrypt(char *plaintext, char *ciphertext, int shift) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char c = plaintext[i];
        // Only shift alphabetic characters
        if ('a' <= c && c <= 'z') {
            ciphertext[i] = (c - 'a' + shift) % 26 + 'a';
        } else if ('A' <= c && c <= 'Z') {
            ciphertext[i] = (c - 'A' + shift) % 26 + 'A';
        } else {
            ciphertext[i] = c; // Non-alphabetic characters remain unchanged
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the string
}

// Function to decrypt ciphertext using Caesar cipher
void decrypt(char *ciphertext, char *plaintext, int shift) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        char c = ciphertext[i];
        // Only shift alphabetic characters
        if ('a' <= c && c <= 'z') {
            plaintext[i] = (c - 'a' - shift + 26) % 26 + 'a';
        } else if ('A' <= c && c <= 'Z') {
            plaintext[i] = (c - 'A' - shift + 26) % 26 + 'A';
        } else {
            plaintext[i] = c; // Non-alphabetic characters remain unchanged
        }
    }
    plaintext[i] = '\0'; // Null-terminate the string
}