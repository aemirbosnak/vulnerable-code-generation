//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1024

// Function to encrypt the plain text using Caesar Cipher
void encrypt(char *plainText, int shift, char *cipherText) {
    int i;
    for (i = 0; plainText[i] != '\0'; ++i) {
        char ch = plainText[i];
        // Encrypt uppercase characters
        if (isupper(ch)) {
            cipherText[i] = (ch + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase characters
        else if (islower(ch)) {
            cipherText[i] = (ch + shift - 'a') % 26 + 'a';
        }
        // If it's neither, just copy it
        else {
            cipherText[i] = ch;
        }
    }
    cipherText[i] = '\0'; // Don't forget to null-terminate
}

// Function to decrypt the cipher text using Caesar Cipher
void decrypt(char *cipherText, int shift, char *plainText) {
    int i;
    for (i = 0; cipherText[i] != '\0'; ++i) {
        char ch = cipherText[i];
        // Decrypt uppercase characters
        if (isupper(ch)) {
            plainText[i] = (ch - shift + 26 - 'A') % 26 + 'A';
        }
        // Decrypt lowercase characters
        else if (islower(ch)) {
            plainText[i] = (ch - shift + 26 - 'a') % 26 + 'a';
        }
        // If it's neither, just copy it
        else {
            plainText[i] = ch;
        }
    }
    plainText[i] = '\0'; // Don't forget to null-terminate
}

int main() {
    char plainText[MAX_LENGTH];
    char cipherText[MAX_LENGTH];
    char decryptedText[MAX_LENGTH];
    int shift;

    printf("Welcome to the Caesar Cipher Encryption Program!\n");
    printf("Please enter a message to encrypt: ");
    fgets(plainText, sizeof(plainText), stdin);
    
    // Remove trailing newline character from fgets
    plainText[strcspn(plainText, "\n")] = 0;

    printf("Enter the shift value (1-25): ");
    scanf("%d", &shift);
    
    // Ensure valid shift value
    if (shift < 1 || shift > 25) {
        printf("Invalid shift value! It must be between 1 and 25.\n");
        return EXIT_FAILURE;
    }

    // Encrypt the plain text
    encrypt(plainText, shift, cipherText);
    printf("Encrypted text: %s\n", cipherText);

    // Decrypt the cipher text
    decrypt(cipherText, shift, decryptedText);
    printf("Decrypted text: %s\n", decryptedText);

    if (strcmp(plainText, decryptedText) == 0) {
        printf("Success! The decrypted text matches the original plain text.\n");
    } else {
        printf("Oops! The decrypted text does not match the original plain text.\n");
    }

    return EXIT_SUCCESS;
}