//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void handleErrors()
{
    printf("Encryption failed\n");
    exit(1);
}

void encrypt()
{
    unsigned char *key = (unsigned char *)"mykey";
    unsigned char *iv = (unsigned char *)"myiv";
    const EVP_CIPHER *cipher;
    EVP_CIPHER_CTX *ctx;
    unsigned char *plaintext = (unsigned char *)"This is a secret message";
    unsigned char ciphertext[128];
    int len;
    int ciphertext_len;

    cipher = EVP_aes_256_cbc();
    ctx = EVP_CIPHER_CTX_new();

    if (!EVP_EncryptInit_ex(ctx, cipher, NULL, key, iv))
        handleErrors();

    if (!EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, strlen(plaintext)))
        handleErrors();

    ciphertext_len = len;

    if (!EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        handleErrors();

    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    printf("Ciphertext is: ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
}

void decrypt()
{
    unsigned char *key = (unsigned char *)"mykey";
    unsigned char *iv = (unsigned char *)"myiv";
    const EVP_CIPHER *cipher;
    EVP_CIPHER_CTX *ctx;
    unsigned char ciphertext[] = {0x8c, 0x66, 0xf9, 0x91, 0xd6, 0xf4, 0x60, 0xea, 0x8f, 0x13, 0x06, 0xaa, 0x7f, 0xfa, 0x92, 0xa6};
    unsigned char decryptedtext[128];
    int len;
    int decryptedtext_len;

    cipher = EVP_aes_256_cbc();
    ctx = EVP_CIPHER_CTX_new();

    if (!EVP_DecryptInit_ex(ctx, cipher, NULL, key, iv))
        handleErrors();

    if (!EVP_DecryptUpdate(ctx, decryptedtext, &len, ciphertext, sizeof(ciphertext) - 1))
        handleErrors();

    decryptedtext_len = len;

    if (!EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len))
        handleErrors();

    decryptedtext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    decryptedtext[decryptedtext_len] = '\0';

    printf("Decrypted text is: ");
    for (int i = 0; i < decryptedtext_len; i++) {
        printf("%c", decryptedtext[i]);
    }
    printf("\n");
}

int main() 
{
    printf("Encrypting...\n");
    encrypt();

    printf("\nDecrypting...\n");
    decrypt();

    return 0;
}