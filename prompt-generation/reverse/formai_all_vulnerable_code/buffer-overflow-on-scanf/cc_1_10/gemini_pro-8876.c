//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

// Define the encryption function
char *encrypt(char *plaintext) {
    int keylen = strlen(KEY);
    int plaintextlen = strlen(plaintext);

    // Allocate memory for the ciphertext
    char *ciphertext = malloc(plaintextlen + 1);
    if (ciphertext == NULL) {
        return NULL;
    }

    // Encrypt the plaintext
    for (int i = 0; i < plaintextlen; i++) {
        int index = plaintext[i] - 'A';
        ciphertext[i] = KEY[(index + i) % keylen];
    }

    // Terminate the ciphertext
    ciphertext[plaintextlen] = '\0';

    // Return the ciphertext
    return ciphertext;
}

// Define the decryption function
char *decrypt(char *ciphertext) {
    int keylen = strlen(KEY);
    int ciphertextlen = strlen(ciphertext);

    // Allocate memory for the plaintext
    char *plaintext = malloc(ciphertextlen + 1);
    if (plaintext == NULL) {
        return NULL;
    }

    // Decrypt the ciphertext
    for (int i = 0; i < ciphertextlen; i++) {
        int index = ciphertext[i] - 'A';
        plaintext[i] = KEY[(index - i + keylen) % keylen];
    }

    // Terminate the plaintext
    plaintext[ciphertextlen] = '\0';

    // Return the plaintext
    return plaintext;
}

// Define the main function
int main() {
    // Get the plaintext from the user
    char plaintext[100];
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    // Encrypt the plaintext
    char *ciphertext = encrypt(plaintext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext
    char *plaintext2 = decrypt(ciphertext);

    // Print the plaintext
    printf("Plaintext: %s\n", plaintext2);

    // Free the memory allocated for the ciphertext and plaintext
    free(ciphertext);
    free(plaintext2);

    return 0;
}