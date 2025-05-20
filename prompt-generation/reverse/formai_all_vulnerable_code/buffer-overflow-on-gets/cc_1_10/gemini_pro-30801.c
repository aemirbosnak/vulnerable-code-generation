//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encryption key
#define KEY "MySuperSecretKey"

// Function to encrypt a string
char *encrypt(char *plaintext) {
    // Get the length of the plaintext and key
    int plaintext_length = strlen(plaintext);
    int key_length = strlen(KEY);

    // Create a buffer to store the encrypted text
    char *ciphertext = malloc(plaintext_length + 1);

    // Loop through each character in the plaintext
    for (int i = 0; i < plaintext_length; i++) {
        // Get the character from the plaintext
        char plaintext_char = plaintext[i];

        // Get the character from the key
        char key_char = KEY[i % key_length];

        // XOR the plaintext character with the key character
        char ciphertext_char = plaintext_char ^ key_char;

        // Store the ciphertext character in the buffer
        ciphertext[i] = ciphertext_char;
    }

    // Terminate the ciphertext string
    ciphertext[plaintext_length] = '\0';

    // Return the ciphertext
    return ciphertext;
}

// Function to decrypt a string
char *decrypt(char *ciphertext) {
    // Get the length of the ciphertext and key
    int ciphertext_length = strlen(ciphertext);
    int key_length = strlen(KEY);

    // Create a buffer to store the decrypted text
    char *plaintext = malloc(ciphertext_length + 1);

    // Loop through each character in the ciphertext
    for (int i = 0; i < ciphertext_length; i++) {
        // Get the character from the ciphertext
        char ciphertext_char = ciphertext[i];

        // Get the character from the key
        char key_char = KEY[i % key_length];

        // XOR the ciphertext character with the key character
        char plaintext_char = ciphertext_char ^ key_char;

        // Store the plaintext character in the buffer
        plaintext[i] = plaintext_char;
    }

    // Terminate the plaintext string
    plaintext[ciphertext_length] = '\0';

    // Return the plaintext
    return plaintext;
}

// Main function
int main() {
    // Get the plaintext from the user
    char plaintext[100];
    printf("Enter the plaintext: ");
    gets(plaintext);

    // Encrypt the plaintext
    char *ciphertext = encrypt(plaintext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    char *plaintext2 = decrypt(ciphertext);

    // Print the decrypted plaintext
    printf("Plaintext: %s\n", plaintext2);

    // Free the allocated memory
    free(ciphertext);
    free(plaintext2);

    return 0;
}