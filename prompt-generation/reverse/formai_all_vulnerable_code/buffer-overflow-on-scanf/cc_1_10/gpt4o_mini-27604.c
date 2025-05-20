//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LENGTH 1024

// Function to encrypt the plaintext using Caesar cipher
void encrypt(const char *plaintext, int key, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];

        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ciphertext[i] = (ch - base + key) % 26 + base;
        } else {
            ciphertext[i] = ch; // Non-alphabetic characters are unchanged
        }
    }
    ciphertext[i] = '\0'; // Null-terminate the ciphertext
}

// Function to decrypt the ciphertext using Caesar cipher
void decrypt(const char *ciphertext, int key, char *plaintext) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];

        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            plaintext[i] = (ch - base - key + 26) % 26 + base; // +26 to ensure positive
        } else {
            plaintext[i] = ch; // Non-alphabetic characters are unchanged
        }
    }
    plaintext[i] = '\0'; // Null-terminate the plaintext
}

int main() {
    char plaintext[MAX_LENGTH], ciphertext[MAX_LENGTH], decryptedtext[MAX_LENGTH];
    int key;

    printf("----- Caesar Cipher Encryption Program -----\n");
    
    // Get plaintext from the user
    printf("Enter the plaintext: ");
    fgets(plaintext, MAX_LENGTH, stdin);
    
    // Remove newline character if present
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    // Get key from the user
    printf("Enter the encryption key (1-25): ");
    scanf("%d", &key);
    
    // Ensure the key is within a valid range
    if (key < 1 || key > 25) {
        printf("Invalid key! Please enter a key between 1 and 25.\n");
        return 1;
    }

    // Encrypt the plaintext
    encrypt(plaintext, key, ciphertext);
    printf("Encrypted ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, key, decryptedtext);
    printf("Decrypted plaintext: %s\n", decryptedtext);

    return 0;
}