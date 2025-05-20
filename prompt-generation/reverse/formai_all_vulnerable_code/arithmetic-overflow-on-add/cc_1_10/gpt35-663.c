//FormAI DATASET v1.0 Category: Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/err.h>

#define MAX_BUF_SIZE 1024

void handleErrors(void)
{
    ERR_print_errors_fp(stderr);
    exit(EXIT_FAILURE);
}

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
             unsigned char *iv, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int ciphertext_len;

    if((ctx = EVP_CIPHER_CTX_new()) == NULL)
        handleErrors();

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();

    ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        handleErrors();

    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
             unsigned char *iv, unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int plaintext_len;

    if((ctx = EVP_CIPHER_CTX_new()) == NULL)
        handleErrors();

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();

    plaintext_len = len;

    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
        handleErrors();

    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

int main(int argc, char **argv)
{
    unsigned char key[EVP_MAX_KEY_LENGTH];

    unsigned char iv[EVP_MAX_IV_LENGTH];

    unsigned char plaintext[MAX_BUF_SIZE];

    unsigned char ciphertext[MAX_BUF_SIZE];

    int plaintext_len;

    int i;

    int ciphertext_len;

    printf("Enter the plaintext to encrypt: ");
    fgets(plaintext, MAX_BUF_SIZE, stdin);

    plaintext_len = strlen(plaintext) - 1;

    memset(key, 0, EVP_MAX_KEY_LENGTH);
    memset(iv, 0, EVP_MAX_IV_LENGTH);

    if(!RAND_bytes(key, 32))
        handleErrors();

    if(!RAND_bytes(iv, 16))
        handleErrors();

    encrypt(plaintext, plaintext_len, key, iv, ciphertext);

    printf("Plaintext:\n");
    for(i = 0; i < plaintext_len; i++)
        printf("%02X ", plaintext[i]);
    putchar('\n');

    printf("Key:\n");
    for(i = 0; i < 32; i++)
        printf("%02X ", key[i]);
    putchar('\n');

    printf("IV:\n");
    for(i = 0; i < 16; i++)
        printf("%02X ", iv[i]);
    putchar('\n');

    printf("Ciphertext:\n");
    for(i = 0; i < ciphertext_len; i++)
        printf("%02X ", ciphertext[i]);
    putchar('\n');

    decrypt(ciphertext, ciphertext_len, key, iv, plaintext);

    printf("Decrypted plaintext:\n");
    for(i = 0; i < plaintext_len; i++)
        putchar(plaintext[i]);
    putchar('\n');

    return EXIT_SUCCESS;
}