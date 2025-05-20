//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Function to encrypt a string using Caesar cipher
void encrypt(char *plaintext, int key, char *ciphertext) {
    int i;
    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = plaintext[i];
        // Encrypt uppercase characters
        if (ch >= 'A' && ch <= 'Z') {
            ciphertext[i] = (ch + key - 'A') % 26 + 'A';
        }
        // Encrypt lowercase characters
        else if (ch >= 'a' && ch <= 'z') {
            ciphertext[i] = (ch + key - 'a') % 26 + 'a';
        }
        // Leave non-alphabetical characters unchanged
        else {
            ciphertext[i] = ch;
        }
    }
    ciphertext[i] = '\0'; // Null terminating the ciphertext string
}

// Function to decrypt a string using Caesar cipher
void decrypt(char *ciphertext, int key, char *plaintext) {
    int i;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        char ch = ciphertext[i];
        // Decrypt uppercase characters
        if (ch >= 'A' && ch <= 'Z') {
            plaintext[i] = (ch - key + 26 - 'A') % 26 + 'A';
        }
        // Decrypt lowercase characters
        else if (ch >= 'a' && ch <= 'z') {
            plaintext[i] = (ch - key + 26 - 'a') % 26 + 'a';
        }
        // Leave non-alphabetical characters unchanged
        else {
            plaintext[i] = ch;
        }
    }
    plaintext[i] = '\0'; // Null terminating the plaintext string
}

// Function to get user input with a limited character size
void getInput(char *input, int maxLength) {
    printf("Enter your message (max %d characters): ", maxLength - 1);
    if (fgets(input, maxLength, stdin) != NULL) {
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0'; // Remove newline character
        }
    }
}

// Main function to demonstrate the Caesar cipher
int main() {
    char plaintext[MAX], ciphertext[MAX], decryptedtext[MAX];
    int key;

    printf("Welcome to the Caesar Cipher Program!\n");
    getInput(plaintext, MAX);
    
    printf("Enter the encryption key (1-25): ");
    scanf("%d", &key);

    if (key < 1 || key > 25) {
        printf("Error: Key must be between 1 and 25.\n");
        return 1;
    }

    // Encrypting the plaintext
    encrypt(plaintext, key, ciphertext);
    printf("Encrypted Message: %s\n", ciphertext);

    // Decrypting the ciphertext
    decrypt(ciphertext, key, decryptedtext);
    printf("Decrypted Message: %s\n", decryptedtext);

    return 0;
}