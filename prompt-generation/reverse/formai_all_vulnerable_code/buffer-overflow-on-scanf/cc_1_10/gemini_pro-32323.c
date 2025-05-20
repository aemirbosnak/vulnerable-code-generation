//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "MySecretEncryptionKey"

// Define the encryption function
void encrypt(char *plaintext, char *ciphertext) {
    int i, j, k;
    int keylen = strlen(KEY);

    // Iterate over the plaintext
    for (i = 0; i < strlen(plaintext); i++) {
        // Get the current character of the plaintext
        char c = plaintext[i];

        // Get the current character of the key
        char key_char = KEY[i % keylen];

        // XOR the plaintext character with the key character
        ciphertext[i] = c ^ key_char;
    }

    // Null-terminate the ciphertext
    ciphertext[strlen(plaintext)] = '\0';
}

// Define the decryption function
void decrypt(char *ciphertext, char *plaintext) {
    int i, j, k;
    int keylen = strlen(KEY);

    // Iterate over the ciphertext
    for (i = 0; i < strlen(ciphertext); i++) {
        // Get the current character of the ciphertext
        char c = ciphertext[i];

        // Get the current character of the key
        char key_char = KEY[i % keylen];

        // XOR the ciphertext character with the key character
        plaintext[i] = c ^ key_char;
    }

    // Null-terminate the plaintext
    plaintext[strlen(ciphertext)] = '\0';
}

// Main function
int main() {
    // Get the plaintext from the user
    char plaintext[1024];
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    // Encrypt the plaintext
    char ciphertext[1024];
    encrypt(plaintext, ciphertext);

    // Print the ciphertext
    printf("The ciphertext is: %s\n", ciphertext);

    // Decrypt the ciphertext
    char decrypted_plaintext[1024];
    decrypt(ciphertext, decrypted_plaintext);

    // Print the decrypted plaintext
    printf("The decrypted plaintext is: %s\n", decrypted_plaintext);

    return 0;
}