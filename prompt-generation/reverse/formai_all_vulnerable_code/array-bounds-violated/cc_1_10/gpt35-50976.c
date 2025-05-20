//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define KEYLEN 32
#define IVLEN 16

// Function to encrypt plaintext using provided key
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
  unsigned char *iv, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;

    int len, ciphertext_len;

    /* Create and initialise the context */
    if(!(ctx = EVP_CIPHER_CTX_new()))
        return 0;

    /* Initialise the encryption operation */
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        return 0;

    /* Provide the plaintext to be encrypted, and obtain the ciphertext output */
    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        return 0;
    ciphertext_len = len;

    /* Finalise the encryption operation */
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        return 0;
    ciphertext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

// Function to decrypt ciphertext using provided key
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
  unsigned char *iv, unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;

    int len, plaintext_len;

    /* Create and initialise the context */
    if(!(ctx = EVP_CIPHER_CTX_new()))
        return 0;

    /* Initialise the decryption operation */
    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        return 0;

    /* Provide the ciphertext to be decrypted, and obtain the plaintext output */
    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        return 0;
    plaintext_len = len;

    /* Finalise the decryption operation */
    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
        return 0;
    plaintext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

int main(int argc, char *argv[])
{
    unsigned char *plaintext = (unsigned char *)"This is a sample plaintext.";
    unsigned char *key = (unsigned char *)"01234567890123456789012345678901"; // 256-bit key
    unsigned char *iv = (unsigned char *)"0123456789abcdef"; // 128-bit IV
    unsigned char ciphertext[128];
    unsigned char decryptedtext[128];

    int ciphertext_len, decryptedtext_len;

    /* Encrypt the plaintext */
    ciphertext_len = encrypt(plaintext, strlen((char *)plaintext), key, iv,
      ciphertext);

    printf("Ciphertext:\n");
    BIO_dump_fp(stdout, (const char *)ciphertext, ciphertext_len);

    /* Decrypt the ciphertext */
    decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv,
      decryptedtext);

    decryptedtext[decryptedtext_len] = '\0';

    /* Print decrypted plaintext */
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}