//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the text using Caesar Cipher
void encrypt(char *plaintext, int shift, char *ciphertext) {
    int i;
    char ch;

    // For every character in the plaintext
    for (i = 0; plaintext[i] != '\0'; ++i) {
        ch = plaintext[i];

        // Encrypt uppercase characters
        if (ch >= 'A' && ch <= 'Z') {
            ciphertext[i] = (ch + shift - 'A') % 26 + 'A';
        } 
        // Encrypt lowercase characters
        else if (ch >= 'a' && ch <= 'z') {
            ciphertext[i] = (ch + shift - 'a') % 26 + 'a';
        } 
        // If character is not alphabetic, leave it as is
        else {
            ciphertext[i] = ch;
        }
    }

    // Null-terminate the ciphertext string
    ciphertext[i] = '\0';
}

// Function to decrypt the text using Caesar Cipher
void decrypt(char *ciphertext, int shift, char *plaintext) {
    int i;
    char ch;

    // For every character in the ciphertext
    for (i = 0; ciphertext[i] != '\0'; ++i) {
        ch = ciphertext[i];

        // Decrypt uppercase characters
        if (ch >= 'A' && ch <= 'Z') {
            plaintext[i] = (ch - shift + 26 - 'A') % 26 + 'A';
        } 
        // Decrypt lowercase characters
        else if (ch >= 'a' && ch <= 'z') {
            plaintext[i] = (ch - shift + 26 - 'a') % 26 + 'a';
        } 
        // If character is not alphabetic, leave it as is
        else {
            plaintext[i] = ch;
        }
    }

    // Null-terminate the plaintext string
    plaintext[i] = '\0';
}

// Main Function
int main() {
    char plaintext[100], ciphertext[100], decryptedtext[100];
    int shift;

    // Welcome message
    printf("Welcome to the Exciting Caesar Cipher Encryption Program!\n");
    
    // Input the plaintext message
    printf("Enter your message to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    
    // Remove the newline character from the input
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    // Input the shift value
    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);

    // Adjust shift to be within the range
    shift = shift % 26;

    // Encrypting the plaintext
    encrypt(plaintext, shift, ciphertext);
    printf("Encrypted message: %s\n", ciphertext);

    // Decrypting the ciphertext
    decrypt(ciphertext, shift, decryptedtext);
    printf("Decrypted message: %s\n", decryptedtext);
    
    // End message
    printf("Thank you for using the Caesar Cipher Program!\n");
    return 0;
}