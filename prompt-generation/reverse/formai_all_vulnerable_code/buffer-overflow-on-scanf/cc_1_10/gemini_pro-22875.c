//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "1234567890ABCDEF"

// Declare the encryption function
void encrypt(char *plaintext, char *ciphertext);

// Declare the decryption function
void decrypt(char *ciphertext, char *plaintext);

// Main function
int main() {
    // Get the plaintext from the user
    printf("Enter the plaintext: ");
    char plaintext[100];
    scanf("%s", plaintext);

    // Encrypt the plaintext
    char ciphertext[100];
    encrypt(plaintext, ciphertext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    char decryptedText[100];
    decrypt(ciphertext, decryptedText);

    // Print the decrypted text
    printf("Decrypted text: %s\n", decryptedText);

    return 0;
}

// Encryption function
void encrypt(char *plaintext, char *ciphertext) {
    int i, j;
    for (i = 0; plaintext[i] != '\0'; i++) {
        ciphertext[i] = plaintext[i] ^ KEY[i % strlen(KEY)];
    }
    ciphertext[i] = '\0';
}

// Decryption function
void decrypt(char *ciphertext, char *plaintext) {
    int i, j;
    for (i = 0; ciphertext[i] != '\0'; i++) {
        plaintext[i] = ciphertext[i] ^ KEY[i % strlen(KEY)];
    }
    plaintext[i] = '\0';
}