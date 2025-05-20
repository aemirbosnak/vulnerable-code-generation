//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void handleErrors()
{
    printf("An error occurred.\n");
    exit(1);
}

void encrypt(char *plaintext, int plaintext_len, char *key, unsigned char *iv, char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int ciphertext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();

    ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();

    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(char *ciphertext, int ciphertext_len, char *key, unsigned char *iv, char *plaintext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int plaintext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();

    plaintext_len = len;

    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();

    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

int main(int argc, char *argv[])
{
    char *key = "mysecretpassword";

    char *plaintext = "plaintext message";

    int plaintext_len = strlen(plaintext);

    unsigned char *iv = (unsigned char *)"0123456789012345";

    char ciphertext[128];

    char decryptedtext[128];

    encrypt(plaintext, plaintext_len, key, iv, ciphertext);

    decrypt(ciphertext, strlen(ciphertext), key, iv, decryptedtext);

    decryptedtext[strlen(plaintext)] = '\0';

    printf("Original Message: %s\n", plaintext);

    printf("Encrypted Message: %s\n", ciphertext);

    printf("Decrypted Message: %s\n", decryptedtext);

    return 0;
}