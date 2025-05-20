//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h> // For encryption and decryption functions

void handleErrors(void) {
    printf("An error occurred\n");
    exit(1);
}

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
             unsigned char *iv, unsigned char *ciphertext) {

    EVP_CIPHER_CTX *ctx;

    int len;
    int ciphertext_len;

    /* Create and initialise the context */
    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
    ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    ciphertext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
             unsigned char *iv, unsigned char *plaintext) {

    EVP_CIPHER_CTX *ctx;

    int len;
    int plaintext_len;

    /* Create and initialise the context */
    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();
    plaintext_len = len;

    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();
    plaintext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

}

int main(void) {

    /* Set up the key and iv */
    unsigned char *key = (unsigned char *)"0123456789abcdef";
    unsigned char *iv = (unsigned char *)"fedcba9876543210";

    /* Message to encrypt */
    unsigned char *plaintext =
        (unsigned char *)"This is a secret message to be encrypted and decrypted using OpenSSL library.";

    int plaintext_len = strlen((char *)plaintext);

    /* Allocate memory for the ciphertext */
    int ciphertext_len = plaintext_len + EVP_CIPHER_block_size(EVP_aes_256_cbc());
    unsigned char *ciphertext = (unsigned char *)malloc(ciphertext_len);

    /* Encrypt plaintext */
    encrypt(plaintext, plaintext_len, key, iv, ciphertext);

    /* Allocate memory for the decrypted text */
    int decryptedtext_len = ciphertext_len;
    unsigned char *decryptedtext = (unsigned char *)malloc(decryptedtext_len);

    /* Decrypt ciphertext */
    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);

    /* Add a null terminator in the end*/
    decryptedtext[decryptedtext_len] = '\0';

    printf("Original Message: %s\n", plaintext);
    printf("Encrypted Message: ");
    BIO_dump_fp(stdout, ciphertext, ciphertext_len);
    printf("Decrypted Message: %s\n", decryptedtext);

    /* Clean up */
    free(ciphertext);
    free(decryptedtext);

    return 0;
}