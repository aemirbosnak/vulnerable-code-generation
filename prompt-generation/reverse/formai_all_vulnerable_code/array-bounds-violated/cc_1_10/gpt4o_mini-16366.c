//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define AES_256_KEY_SIZE 32
#define AES_BLOCK_SIZE  16

// Function to handle errors
void handleErrors(void)
{
    ERR_print_errors_fp(stderr);
    abort();
}

// Function to encrypt plaintext using AES-256-CBC
int encrypt(const unsigned char *plaintext, int plaintext_len,
             const unsigned char *key, const unsigned char *iv,
             unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int ciphertext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize the encryption operation
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    // Provide the message to be encrypted, and obtain the encrypted output
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
    ciphertext_len = len;

    // Finalize the encryption
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    ciphertext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

// Function to decrypt ciphertext using AES-256-CBC
int decrypt(const unsigned char *ciphertext, int ciphertext_len,
             const unsigned char *key, const unsigned char *iv,
             unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int plaintext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize the decryption operation
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    // Provide the message to be decrypted, and obtain the output
    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();
    plaintext_len = len;

    // Finalize the decryption
    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();
    plaintext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

// Function to generate a random key and IV
void generate_key_and_iv(unsigned char *key, unsigned char *iv)
{
    if (!RAND_bytes(key, AES_256_KEY_SIZE)) handleErrors();
    if (!RAND_bytes(iv, AES_BLOCK_SIZE)) handleErrors();
}

int main(void)
{
    // Initialize OpenSSL Algorithms
    OpenSSL_add_all_algorithms();

    // Define plaintext
    unsigned char *plaintext = (unsigned char *)"This is a secret message!";
    unsigned char ciphertext[128];
    unsigned char decryptedtext[128];

    // Key and IV definitions
    unsigned char key[AES_256_KEY_SIZE];
    unsigned char iv[AES_BLOCK_SIZE];

    // Generate a random key and IV
    generate_key_and_iv(key, iv);

    int decryptedtext_len, ciphertext_len;

    ciphertext_len = encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext);
    
    printf("Ciphertext is: ");
    for (int i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);

    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the string
    printf("Decrypted text is: %s\n", decryptedtext);

    // Clean up
    EVP_cleanup();
    return 0;
}