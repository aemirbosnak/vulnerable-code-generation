//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void handleErrors(void)
{
    printf("An error occurred\n");
    exit(EXIT_FAILURE);
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;
    if((ctx = EVP_CIPHER_CTX_new()) == NULL) handleErrors();
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();
    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) handleErrors();
    ciphertext_len = len;
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    ciphertext_len += len;
    EVP_CIPHER_CTX_free(ctx);
    return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;
    if((ctx = EVP_CIPHER_CTX_new()) == NULL) handleErrors();
    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();
    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)) handleErrors();
    plaintext_len = len;
    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();
    plaintext_len += len;
    EVP_CIPHER_CTX_free(ctx);
    return plaintext_len;
}

int main(void)
{
    unsigned char *plaintext = (unsigned char *)"This is a secret message. It will be encrypted using AES-256 CBC mode.";
    unsigned char *key = (unsigned char *)"01234567890123456789012345678901";
    unsigned char *iv = (unsigned char *)"0123456789012345";
    unsigned char ciphertext[1024];
    unsigned char decryptedtext[1024];
    int decryptedtext_len, ciphertext_len;
    ciphertext_len = encrypt(plaintext, strlen(plaintext), key, iv, ciphertext);
    decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);
    ciphertext[ciphertext_len] = '\0';
    decryptedtext[decryptedtext_len] = '\0';
    printf("Original Message: %s\n", plaintext);
    printf("Encrypted Message: %s\n", ciphertext);
    printf("Decrypted Message: %s\n", decryptedtext);
    return 0;
}