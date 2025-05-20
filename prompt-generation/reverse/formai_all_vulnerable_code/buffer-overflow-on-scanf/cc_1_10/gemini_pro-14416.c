//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key for encryption and decryption
#define KEY "my_secret_key"

// Function to encrypt a string using XOR encryption
char *encrypt(char *plaintext) {
    int keylen = strlen(KEY);
    int plaintextlen = strlen(plaintext);

    // Allocate memory for the ciphertext
    char *ciphertext = malloc(plaintextlen + 1);
    if (ciphertext == NULL) {
        return NULL;
    }

    // Perform XOR encryption
    for (int i = 0; i < plaintextlen; i++) {
        ciphertext[i] = plaintext[i] ^ KEY[i % keylen];
    }

    // Add null terminator
    ciphertext[plaintextlen] = '\0';

    return ciphertext;
}

// Function to decrypt a string using XOR encryption
char *decrypt(char *ciphertext) {
    int keylen = strlen(KEY);
    int ciphertextlen = strlen(ciphertext);

    // Allocate memory for the plaintext
    char *plaintext = malloc(ciphertextlen + 1);
    if (plaintext == NULL) {
        return NULL;
    }

    // Perform XOR decryption
    for (int i = 0; i < ciphertextlen; i++) {
        plaintext[i] = ciphertext[i] ^ KEY[i % keylen];
    }

    // Add null terminator
    plaintext[ciphertextlen] = '\0';

    return plaintext;
}

int main() {
    // Get the plaintext from the user
    char plaintext[100];
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    // Encrypt the plaintext
    char *ciphertext = encrypt(plaintext);
    if (ciphertext == NULL) {
        printf("Error: Could not allocate memory for ciphertext.\n");
        return EXIT_FAILURE;
    }

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    char *decrypted_plaintext = decrypt(ciphertext);
    if (decrypted_plaintext == NULL) {
        printf("Error: Could not allocate memory for decrypted plaintext.\n");
        free(ciphertext);
        return EXIT_FAILURE;
    }

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(ciphertext);
    free(decrypted_plaintext);

    return EXIT_SUCCESS;
}