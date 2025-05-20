//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void handleErrors(void)
{
    printf("Error occurred\n");
    abort();
}

void encrypt(const char *key, const unsigned char *plaintext, int plaintext_len,
             unsigned char *ciphertext, int *ciphertext_len)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char*)key, NULL))
        handleErrors();

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();

    *ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();

    *ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(const char *key, const unsigned char *ciphertext, int ciphertext_len,
             unsigned char *plaintext, int *plaintext_len)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char*)key, NULL))
        handleErrors();

    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();

    *plaintext_len = len;

    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();

    *plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

int main(void)
{
    const char *key = "cryptographyexample";

    unsigned char plaintext[] = "This is an example of Cryptography Implementation";

    int plaintext_len = strlen((char*)plaintext);

    unsigned char ciphertext[128];

    int ciphertext_len;

    encrypt(key, plaintext, plaintext_len, ciphertext, &ciphertext_len);

    unsigned char decrypted_plaintext[128];

    int decrypted_plaintext_len;

    decrypt(key, ciphertext, ciphertext_len, decrypted_plaintext, &decrypted_plaintext_len);

    printf("Original Text: %s\n", plaintext);

    printf("Encrypted Text: ");

    for(int i = 0; i < ciphertext_len; i++)
    {
        printf("%02x", ciphertext[i]);
    }

    printf("\n");

    printf("Decrypted Text: %s\n", decrypted_plaintext);

    return 0;
}