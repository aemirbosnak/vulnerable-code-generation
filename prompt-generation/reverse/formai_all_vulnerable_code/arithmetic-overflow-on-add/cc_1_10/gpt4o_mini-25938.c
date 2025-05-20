//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/evp.h>
#include <openssl/err.h>

#define AES_BLOCK_SIZE 16
#define BUFFER_SIZE 1024

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

void encrypt(const char *plaintext, const uint8_t *key, const uint8_t *iv, uint8_t *ciphertext, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    // Initialize the encryption operation
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    // Provide the message to be encrypted
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, ciphertext_len, (const uint8_t *)plaintext, strlen(plaintext)))
        handleErrors();

    int len;
    // Finalize the encryption
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + *ciphertext_len, &len))
        handleErrors();
    
    *ciphertext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(const uint8_t *ciphertext, int ciphertext_len, const uint8_t *key, const uint8_t *iv, uint8_t *plaintext, int *plaintext_len) {
    EVP_CIPHER_CTX *ctx;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    // Initialize the decryption operation
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    // Provide the message to be decrypted
    if (1 != EVP_DecryptUpdate(ctx, plaintext, plaintext_len, ciphertext, ciphertext_len))
        handleErrors();

    int len;
    // Finalize the decryption
    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + *plaintext_len, &len))
        handleErrors();
    
    *plaintext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
}

int main() {
    // Set up key and IV
    const uint8_t key[32] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
        0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
        0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
        0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F
    };
    
    const uint8_t iv[AES_BLOCK_SIZE] = {
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00
    };

    // Message to be encrypted
    const char *message = "This is a secret message!";
    uint8_t ciphertext[BUFFER_SIZE];
    int ciphertext_len;

    // Encrypt the message
    printf("Original Message: %s\n", message);
    encrypt(message, key, iv, ciphertext, &ciphertext_len);
    printf("Ciphertext (hex): ");
    for(int i = 0; i < ciphertext_len; i++) {
        printf("%02x ", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the message
    uint8_t decryptedtext[BUFFER_SIZE];
    int decryptedtext_len;
    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, &decryptedtext_len);
    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the decrypted string

    printf("Decrypted Message: %s\n", decryptedtext);

    return 0;
}