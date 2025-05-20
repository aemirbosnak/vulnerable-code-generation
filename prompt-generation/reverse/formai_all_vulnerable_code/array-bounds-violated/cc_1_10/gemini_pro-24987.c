//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/evp.h>

// Define the block size for the cipher
#define BLOCK_SIZE 16

// Define the key and IV for the cipher
uint8_t key[] = "0123456789ABCDEF";
uint8_t iv[] = "ABCDEF0123456789";

// Encrypt a message using AES-256-CBC
int encrypt_aes_cbc(uint8_t *plaintext, size_t plaintext_len, uint8_t *ciphertext)
{
    // Create a new EVP context for the cipher
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        return -1;
    }

    // Initialize the cipher context for encryption
    if (EVP_CipherInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv, 1) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Update the cipher context with the plaintext
    if (EVP_CipherUpdate(ctx, ciphertext, &plaintext_len, plaintext, plaintext_len) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Finalize the cipher context and write the remaining ciphertext
    int ciphertext_len;
    if (EVP_CipherFinal_ex(ctx, ciphertext + plaintext_len, &ciphertext_len) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Clean up the EVP context
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len + ciphertext_len;
}

// Decrypt a message using AES-256-CBC
int decrypt_aes_cbc(uint8_t *ciphertext, size_t ciphertext_len, uint8_t *plaintext)
{
    // Create a new EVP context for the cipher
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        return -1;
    }

    // Initialize the cipher context for decryption
    if (EVP_CipherInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv, 0) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Update the cipher context with the ciphertext
    if (EVP_CipherUpdate(ctx, plaintext, &ciphertext_len, ciphertext, ciphertext_len) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Finalize the cipher context and write the remaining plaintext
    int plaintext_len;
    if (EVP_CipherFinal_ex(ctx, plaintext + ciphertext_len, &plaintext_len) != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    // Clean up the EVP context
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len + ciphertext_len;
}

int main()
{
    // Define the plaintext message
    uint8_t plaintext[] = "Hello, world!";

    // Allocate a buffer for the ciphertext
    uint8_t ciphertext[BLOCK_SIZE * 2];

    // Encrypt the plaintext message
    int ciphertext_len = encrypt_aes_cbc(plaintext, strlen(plaintext), ciphertext);
    if (ciphertext_len < 0) {
        fprintf(stderr, "Error encrypting plaintext message\n");
        return EXIT_FAILURE;
    }

    // Print the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02X", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the ciphertext
    uint8_t decrypted_plaintext[BLOCK_SIZE * 2];
    int decrypted_plaintext_len = decrypt_aes_cbc(ciphertext, ciphertext_len, decrypted_plaintext);
    if (decrypted_plaintext_len < 0) {
        fprintf(stderr, "Error decrypting ciphertext\n");
        return EXIT_FAILURE;
    }

    // Print the decrypted plaintext
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    return EXIT_SUCCESS;
}