//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define AES_KEY_LENGTH 256
#define AES_BLOCK_SIZE 16

// Helper function to handle OpenSSL errors
void handleErrors(void) {
    ERR_print_errors_fp(stdout);
    abort();
}

// Function to encrypt plaintext using AES-256-CBC
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;

    int len;
    int ciphertext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize encryption operation
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handleErrors();

    // Provide the message to be encrypted and receive the encrypted output
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1) handleErrors();
    ciphertext_len = len;

    // Finalize the encryption process
    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) handleErrors();
    ciphertext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

// Function to decrypt ciphertext using AES-256-CBC
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;

    int len;
    int plaintext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize decryption operation
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handleErrors();

    // Provide the message to be decrypted and receive the output
    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) != 1) handleErrors();
    plaintext_len = len;

    // Finalize the decryption process
    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &len) != 1) handleErrors();
    plaintext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

// Function to generate a random key and IV
void generate_key_and_iv(unsigned char *key, unsigned char *iv) {
    if (!RAND_bytes(key, AES_KEY_LENGTH / 8)) handleErrors();
    if (!RAND_bytes(iv, AES_BLOCK_SIZE)) handleErrors();
}

int main() {
    // Sample text to encrypt
    unsigned char *plaintext = (unsigned char *)"This is a secret message with AES encryption.";
    // Buffer for ciphertext
    unsigned char ciphertext[128];
    // Buffer for decrypted text
    unsigned char decryptedtext[128];
    // Key and IV
    unsigned char key[AES_KEY_LENGTH / 8];
    unsigned char iv[AES_BLOCK_SIZE];

    // Generate a random key and IV
    generate_key_and_iv(key, iv);

    // Encrypt the plaintext
    int ciphertext_len = encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext);
    printf("Ciphertext is:\n");
    for (int i = 0; i < ciphertext_len; i++)
        printf("%02x ", ciphertext[i]);
    printf("\n");

    // Decrypt the ciphertext
    int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);
    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the decrypted text

    printf("Decrypted text is:\n");
    printf("%s\n", decryptedtext);

    return 0;
}