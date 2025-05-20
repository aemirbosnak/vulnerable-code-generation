//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_LENGTH 256

// Function to encrypt the plaintext using Caesar cipher
void encrypt(char *plaintext, int shift, char *ciphertext) {
    int i = 0, charCode;

    while (plaintext[i] != '\0') {
        if (isalpha(plaintext[i])) {
            charCode = (plaintext[i] + shift);

            // Wrap around for uppercase letters
            if (isupper(plaintext[i])) {
                if (charCode > 'Z') {
                    charCode -= 26;
                }
            }
            // Wrap around for lowercase letters
            else {
                if (charCode > 'z') {
                    charCode -= 26;
                }
            }
            ciphertext[i] = charCode;
        } else {
            ciphertext[i] = plaintext[i];  // Non-alphabetical characters remain unchanged
        }
        i++;
    }
    ciphertext[i] = '\0'; // Null-terminate the string
}

// Function to decrypt the ciphertext using Caesar cipher
void decrypt(char *ciphertext, int shift, char *plaintext) {
    int i = 0, charCode;

    while (ciphertext[i] != '\0') {
        if (isalpha(ciphertext[i])) {
            charCode = (ciphertext[i] - shift);

            // Wrap around for uppercase letters
            if (isupper(ciphertext[i])) {
                if (charCode < 'A') {
                    charCode += 26;
                }
            }
            // Wrap around for lowercase letters
            else {
                if (charCode < 'a') {
                    charCode += 26;
                }
            }
            plaintext[i] = charCode;
        } else {
            plaintext[i] = ciphertext[i];  // Non-alphabetical characters remain unchanged
        }
        i++;
    }
    plaintext[i] = '\0'; // Null-terminate the string
}

// Main function to engage in this cryptographic inquiry
int main() {
    char plaintext[MAX_TEXT_LENGTH];
    char ciphertext[MAX_TEXT_LENGTH];
    char decryptedtext[MAX_TEXT_LENGTH];
    int shift;

    // The initial inquiry by the great Sherlock Holmes
    printf("Welcome to the Cryptographic Analysis of Sherlock Holmes!\n");
    printf("Please enter the plaintext you wish to encrypt (max 255 characters):\n");

    fgets(plaintext, sizeof(plaintext), stdin);
    
    // Remove newline character if present
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter the shift value for the encryption (1-25 recommended): ");
    scanf("%d", &shift);

    // Ensure shift is valid
    if (shift < 1 || shift > 25) {
        printf("Analyzing the shift value, I must deduce that it must be within 1-25.\n");
        return 1;
    }

    // The encryption process
    encrypt(plaintext, shift, ciphertext);
    printf("Ciphertext (Encrypted Text): %s\n", ciphertext);

    // The decryption process
    decrypt(ciphertext, shift, decryptedtext);
    printf("Decrypted Text: %s\n", decryptedtext);

    // Final deduction of Holmes
    if (strcmp(plaintext, decryptedtext) == 0) {
        printf("Elementary! The decryption matches the original text.\n");
    } else {
        printf("Alas! We have encountered an inconsistency.\n");
    }

    return 0; // The end of our cryptographic venture
}