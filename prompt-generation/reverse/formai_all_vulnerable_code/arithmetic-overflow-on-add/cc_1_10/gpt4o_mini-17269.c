//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define AES_KEY_LENGTH 256  // Key length in bits
#define AES_BLOCK_SIZE 16    // Block size for AES

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

void generate_random_key(unsigned char *key) {
    if (!RAND_bytes(key, AES_KEY_LENGTH / 8)) {
        fprintf(stderr, "Could not generate random key.\n");
        exit(EXIT_FAILURE);
    }
}

void encrypt(const unsigned char *plaintext, const unsigned char *key, unsigned char *ciphertext, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;
    int len;
    unsigned char iv[AES_BLOCK_SIZE];

    // Generate a random Initialization Vector (IV)
    if (!RAND_bytes(iv, sizeof(iv))) {
        fprintf(stderr, "Could not generate random IV.\n");
        exit(EXIT_FAILURE);
    }

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    // Initialize encryption operation
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1)
        handleErrors();

    // Provide the input message and obtain the encrypted output
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, strlen((const char *)plaintext)) != 1)
        handleErrors();
    *ciphertext_len = len;

    // Finalize encryption
    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1)
        handleErrors();
    *ciphertext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    
    printf("IV: ");
    for(int i = 0; i < AES_BLOCK_SIZE; i++) {
        printf("%02x", iv[i]);
    }
    printf("\n");
}

void decrypt(const unsigned char *ciphertext, int ciphertext_len, const unsigned char *key, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    unsigned char iv[AES_BLOCK_SIZE];  // IV should be retrieved from somewhere, here I will use a fixed IV for simplicity

    // Set the IV here (in a real application, you would send/store it with the ciphertext)
    memset(iv, 0, AES_BLOCK_SIZE);  // For demonstration, it's set to zero; in practice, use actual IV

    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    // Initialize decryption operation
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1)
        handleErrors();

    // Provide the ciphertext and obtain the plaintext
    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) != 1)
        handleErrors();
    plaintext[len] = '\0';  // Null-terminate the plaintext

    // Finalize decryption
    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &len) != 1)
        handleErrors();

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
}

int main() {
    unsigned char key[AES_KEY_LENGTH / 8];     // Key for encryption/decryption
    unsigned char plaintext[128];                // Buffer for the plaintext
    unsigned char ciphertext[128];               // Buffer for the ciphertext
    int ciphertext_len;

    // Get user input for plaintext message
    printf("Enter plaintext (up to 128 characters): ");
    fgets((char *)plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn((char *)plaintext, "\n")] = 0; // Remove newline character

    // Generate a random key
    generate_random_key(key);

    // Perform encryption
    encrypt(plaintext, key, ciphertext, &ciphertext_len);
    printf("Ciphertext (in hex): ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the ciphertext
    unsigned char decryptedplaintext[128];
    decrypt(ciphertext, ciphertext_len, key, decryptedplaintext);
    printf("Decrypted plaintext: %s\n", decryptedplaintext);

    return 0;
}