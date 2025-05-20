//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void encrypt(char *plaintext, char *key, int keylen);
void decrypt(char *ciphertext, char *key, int keylen);

// Main function
int main() {
    // Get the plaintext and key from the user
    char plaintext[100];
    char key[100];
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);
    printf("Enter the key: ");
    scanf("%s", key);

    // Encrypt the plaintext
    encrypt(plaintext, key, strlen(key));

    // Print the ciphertext
    printf("Ciphertext: %s\n", plaintext);

    // Decrypt the ciphertext
    decrypt(plaintext, key, strlen(key));

    // Print the plaintext
    printf("Plaintext: %s\n", plaintext);

    return 0;
}

// Function to encrypt the plaintext
void encrypt(char *plaintext, char *key, int keylen) {
    int i, j;
    for (i = 0; i < strlen(plaintext); i++) {
        j = i % keylen;
        plaintext[i] = plaintext[i] + key[j];
    }
}

// Function to decrypt the ciphertext
void decrypt(char *ciphertext, char *key, int keylen) {
    int i, j;
    for (i = 0; i < strlen(ciphertext); i++) {
        j = i % keylen;
        ciphertext[i] = ciphertext[i] - key[j];
    }
}