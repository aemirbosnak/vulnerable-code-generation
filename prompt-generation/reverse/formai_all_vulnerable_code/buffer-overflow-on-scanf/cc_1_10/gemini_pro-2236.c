//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "my_super_secret_key"

// Function to encrypt a string
char *encrypt(char *plaintext) {
    int key_len = strlen(KEY);
    int plaintext_len = strlen(plaintext);

    // Allocate memory for the encrypted string
    char *ciphertext = malloc(plaintext_len + 1);

    // Encrypt the string by XORing each character with the key
    for (int i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ KEY[i % key_len];
    }

    // Terminate the string
    ciphertext[plaintext_len] = '\0';

    // Return the encrypted string
    return ciphertext;
}

// Function to decrypt a string
char *decrypt(char *ciphertext) {
    int key_len = strlen(KEY);
    int ciphertext_len = strlen(ciphertext);

    // Allocate memory for the decrypted string
    char *plaintext = malloc(ciphertext_len + 1);

    // Decrypt the string by XORing each character with the key
    for (int i = 0; i < ciphertext_len; i++) {
        plaintext[i] = ciphertext[i] ^ KEY[i % key_len];
    }

    // Terminate the string
    plaintext[ciphertext_len] = '\0';

    // Return the decrypted string
    return plaintext;
}

int main() {
    // Get the plaintext from the user
    char plaintext[100];
    printf("Enter the plaintext to encrypt: ");
    scanf("%s", plaintext);

    // Encrypt the plaintext
    char *ciphertext = encrypt(plaintext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    char *decrypted_plaintext = decrypt(ciphertext);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}