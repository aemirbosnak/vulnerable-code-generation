//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define KEY_LEN 32
#define IV_LEN 16
#define BUFFER_LEN 1024

void handleErrors(void)
{
    printf("Error occurred in cryptography implementation. \n");
    exit(1);
}

void encrypt(char *plaintext, int plaintext_len, unsigned char *key,
  unsigned char *iv, char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int ciphertext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_EncryptUpdate(ctx, (unsigned char *)ciphertext, &len, (unsigned char *)plaintext, plaintext_len))
        handleErrors();
    ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, (unsigned char *)ciphertext + len, &len)) handleErrors();
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(char *ciphertext, int ciphertext_len, unsigned char *key,
  unsigned char *iv, char *plaintext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int plaintext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_DecryptUpdate(ctx, (unsigned char *)plaintext, &len, (unsigned char *)ciphertext, ciphertext_len))
        handleErrors();
    plaintext_len = len;

    if(1 != EVP_DecryptFinal_ex(ctx, (unsigned char *)plaintext + len, &len)) handleErrors();
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

int main(int argc, char** argv){

    unsigned char *key = (unsigned char *)"01234567890123456789012345678901";
    unsigned char *iv = (unsigned char *)"0123456789012345";
    char *plaintext = "This is a secret message!";
    int len = strlen(plaintext);
  
    char ciphertext[BUFFER_LEN];
    encrypt(plaintext, len, key, iv, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    char decryptedtext[BUFFER_LEN];
    decrypt(ciphertext, strlen(ciphertext), key, iv, decryptedtext);
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;

}