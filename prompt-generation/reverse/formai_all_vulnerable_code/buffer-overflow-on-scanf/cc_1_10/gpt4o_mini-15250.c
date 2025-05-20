//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256

void encrypt(char *plaintext, int shift, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];

        // Encrypt uppercase letters
        if (isupper(ch)) {
            ciphertext[i] = (ch + shift - 'A') % 26 + 'A';
        }
        // Encrypt lowercase letters
        else if (islower(ch)) {
            ciphertext[i] = (ch + shift - 'a') % 26 + 'a';
        }
        // Non-alphabetic characters remain unchanged
        else {
            ciphertext[i] = ch;
        }
    }
    ciphertext[i] = '\0'; // Null terminate the ciphertext
}

void decrypt(char *ciphertext, int shift, char *plaintext) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];

        // Decrypt uppercase letters
        if (isupper(ch)) {
            plaintext[i] = (ch - shift + 26 - 'A') % 26 + 'A';
        }
        // Decrypt lowercase letters
        else if (islower(ch)) {
            plaintext[i] = (ch - shift + 26 - 'a') % 26 + 'a';
        }
        // Non-alphabetic characters remain unchanged
        else {
            plaintext[i] = ch;
        }
    }
    plaintext[i] = '\0'; // Null terminate the plaintext
}

int main() {
    char plaintext[MAX_LEN];
    char ciphertext[MAX_LEN];
    char decryptedtext[MAX_LEN];
    int shift;

    // User input for plaintext
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    
    // Remove newline character if present
    plaintext[strcspn(plaintext, "\n")] = '\0'; 

    // User input for shift
    printf("Enter shift amount (0-25): ");
    scanf("%d", &shift);

    // Ensure shift is in the range of 0-25
    if (shift < 0 || shift > 25) {
        printf("Invalid shift amount. Please enter a value between 0 and 25.\n");
        return 1;
    }

    // Perform encryption
    encrypt(plaintext, shift, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);

    // Perform decryption
    decrypt(ciphertext, shift, decryptedtext);
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}