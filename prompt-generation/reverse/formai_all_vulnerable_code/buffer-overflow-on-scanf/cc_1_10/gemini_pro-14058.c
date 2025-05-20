//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the key for the XOR encryption
const char *key = "MySuperSecretKey";

// XOR encryption function
char *xor_encrypt(char *plaintext) {
    size_t plaintext_len = strlen(plaintext);
    size_t key_len = strlen(key);

    // Allocate memory for the ciphertext
    char *ciphertext = malloc(plaintext_len + 1);

    // Perform XOR encryption
    for (size_t i = 0; i < plaintext_len; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % key_len];
    }

    // Null-terminate the ciphertext
    ciphertext[plaintext_len] = '\0';

    return ciphertext;
}

// XOR decryption function
char *xor_decrypt(char *ciphertext) {
    size_t ciphertext_len = strlen(ciphertext);
    size_t key_len = strlen(key);

    // Allocate memory for the plaintext
    char *plaintext = malloc(ciphertext_len + 1);

    // Perform XOR decryption
    for (size_t i = 0; i < ciphertext_len; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % key_len];
    }

    // Null-terminate the plaintext
    plaintext[ciphertext_len] = '\0';

    return plaintext;
}

int main() {
    // Get the plaintext from the user
    char plaintext[100];
    printf("Enter the plaintext: ");
    scanf("%s", plaintext);

    // Encrypt the plaintext using XOR encryption
    char *ciphertext = xor_encrypt(plaintext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using XOR decryption
    char *decrypted_plaintext = xor_decrypt(ciphertext);

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Free the allocated memory
    free(ciphertext);
    free(decrypted_plaintext);

    return 0;
}