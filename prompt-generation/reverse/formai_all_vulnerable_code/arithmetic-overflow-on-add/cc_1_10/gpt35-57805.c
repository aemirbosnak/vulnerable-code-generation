//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/err.h>

// Error handling function
void handleErrors(void)
{
    ERR_print_errors_fp(stderr);
    abort();
}

// Generate a symmetric key
void genSymmetricKey(unsigned char *key, int keySize)
{
    if (!RAND_bytes(key, keySize)) {
        handleErrors();
    }
}

// Encrypt a message using AES-256-CBC algorithm
int encrypt(unsigned char *plaintext, int plaintextLen, unsigned char *key,
    unsigned char *iv, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int ciphertextLen;

    // Create and initialize the context
    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    // Encrypt the plaintext
    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintextLen))
        handleErrors();
    ciphertextLen = len;

    // Finalize the encryption
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    ciphertextLen += len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertextLen;
}

// Decrypt a message using AES-256-CBC algorithm
int decrypt(unsigned char *ciphertext, int ciphertextLen, unsigned char *key,
    unsigned char *iv, unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int plaintextLen;

    // Create and initialize the context
    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();
    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    // Decrypt the ciphertext
    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertextLen))
        handleErrors();
    plaintextLen = len;

    // Finalize the decryption
    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();
    plaintextLen += len;

    EVP_CIPHER_CTX_free(ctx);

    return plaintextLen;
}

int main(int argc, char *argv[])
{
    if (argc < 3) {
        printf("Usage: %s <plaintext> <key>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int plaintextLen = strlen(argv[1]);
    int keySize = EVP_CIPHER_key_length(EVP_aes_256_cbc());
    unsigned char *key = (unsigned char *)argv[2];

    // Generate a random IV
    unsigned char iv[EVP_MAX_IV_LENGTH];
    if (!RAND_bytes(iv, EVP_MAX_IV_LENGTH)) {
        handleErrors();
    }

    // Allocate memory for the ciphertext
    int ciphertextLen = plaintextLen + EVP_CIPHER_block_size(EVP_aes_256_cbc());
    unsigned char *ciphertext = (unsigned char *)malloc(ciphertextLen);

    // Encrypt the plaintext
    int encryptedLen = encrypt((unsigned char *)argv[1], plaintextLen, key, iv, ciphertext);
    printf("Encrypted message: ");
    for (int i = 0; i < encryptedLen; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Allocate memory for the decrypted plaintext
    unsigned char *decryptedPlaintext = (unsigned char *)malloc(plaintextLen);

    // Decrypt the ciphertext
    int decryptedLen = decrypt(ciphertext, encryptedLen, key, iv, decryptedPlaintext);
    printf("Decrypted message: %s\n", decryptedPlaintext);

    // Free memory
    free(ciphertext);
    free(decryptedPlaintext);

    return 0;
}