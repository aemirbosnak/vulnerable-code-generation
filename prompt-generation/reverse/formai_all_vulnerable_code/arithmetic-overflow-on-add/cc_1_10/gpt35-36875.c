//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

char *encrypt(char *plaintext, char *key)
{
    EVP_CIPHER_CTX *ctx;
    char *ciphertext;
    int ciphertext_len, len;

    ciphertext = (char *)malloc(strlen(plaintext)+EVP_MAX_BLOCK_LENGTH);
    if (!ciphertext)
        return NULL;

    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_ecb(), NULL, (unsigned char *)key, NULL);
    EVP_EncryptUpdate(ctx, (unsigned char *)ciphertext, &len, (unsigned char *)plaintext, strlen(plaintext));
    ciphertext_len = len;
    EVP_EncryptFinal_ex(ctx, (unsigned char *)ciphertext+len, &len);
    ciphertext_len += len;
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext;
}

char *decrypt(char *ciphertext, char *key)
{
    EVP_CIPHER_CTX *ctx;
    char *plaintext;
    int plaintext_len, len;

    plaintext = (char *)malloc(strlen(ciphertext));
    if (!plaintext)
        return NULL;

    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_ecb(), NULL, (unsigned char *)key, NULL);
    EVP_DecryptUpdate(ctx, (unsigned char *)plaintext, &len, (unsigned char *)ciphertext, strlen(ciphertext));
    plaintext_len = len;
    EVP_DecryptFinal_ex(ctx, (unsigned char *)plaintext+len, &len);
    plaintext_len += len;
    EVP_CIPHER_CTX_free(ctx);

    return plaintext;
}

int main()
{
    char *plaintext = "hello world";
    char *key = "1234567890123456";
    char *ciphertext;
    char *decrypted;

    ciphertext = encrypt(plaintext, key);
    decrypted = decrypt(ciphertext, key);

    printf("Original Text: %s\n", plaintext);
    printf("Encrypted Text: %s\n", ciphertext);
    printf("Decrypted Text: %s\n", decrypted);

    free(ciphertext);
    free(decrypted);

    return 0;
}