//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

void handleErrors(void)
{
    printf("Error\n");
    abort();
}

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
             unsigned char *iv, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int ciphertext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();

    ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();

    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
             unsigned char *iv, unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int plaintext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();

    plaintext_len = len;

    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();

    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

int main(int argc, char **argv)
{
    unsigned char *key, *iv, *plaintext, *ciphertext;

    int plaintext_len, ciphertext_len;

    const char *password = "my_password";

    plaintext = (unsigned char *)"This is a secret message.";
    plaintext_len = strlen((char*)plaintext);

    printf("Original Message: %s\n", plaintext);

    key = (unsigned char *)malloc(EVP_CIPHER_key_length(EVP_aes_256_cbc()));
    iv = (unsigned char *)malloc(EVP_CIPHER_iv_length(EVP_aes_256_cbc()));

    if(!RAND_bytes(key, EVP_CIPHER_key_length(EVP_aes_256_cbc()))) handleErrors();

    if(!RAND_bytes(iv, EVP_CIPHER_iv_length(EVP_aes_256_cbc()))) handleErrors();

    ciphertext_len = plaintext_len + EVP_CIPHER_block_size(EVP_aes_256_cbc());
    ciphertext = (unsigned char *)malloc(ciphertext_len);

    encrypt(plaintext, plaintext_len, key, iv, ciphertext);

    printf("Encrypted Message Length: %d\n", ciphertext_len);
    printf("Encrypted Message: %s\n", ciphertext);
    printf("Key: %s\n", key);
    printf("IV: %s\n", iv);

    plaintext_len = ciphertext_len - EVP_CIPHER_block_size(EVP_aes_256_cbc());
    plaintext = (unsigned char *)malloc(plaintext_len + 1);

    decrypt(ciphertext, ciphertext_len, key, iv, plaintext);

    plaintext[plaintext_len] = '\0';

    printf("Decrypted Message Length: %d\n", plaintext_len);
    printf("Decrypted Message: %s\n", plaintext);

    free(key);
    free(iv);
    free(ciphertext);
    free(plaintext);

    return 0;
}