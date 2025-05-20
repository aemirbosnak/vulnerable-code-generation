//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define AES_BLOCK_SIZE 16

void handleErrors(void)
{
    printf("An error occurred\n");
    exit(1);
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
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

    return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
  unsigned char *iv, unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;
    int ret;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
      handleErrors();

    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
      handleErrors();
    plaintext_len = len;

    ret = EVP_DecryptFinal_ex(ctx, plaintext + len, &len);
    if(ret != 1) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

int main()
{
    unsigned char *key = (unsigned char*)"01234567890123456789012345678901";
    unsigned char *iv = (unsigned char*)"0123456789012345";
    unsigned char *plaintext =
        (unsigned char*)"This is a secret message to be encrypted";
  
    int plaintext_len = strlen((char*)plaintext);
    int ciphertext_len;
    unsigned char ciphertext[128];
    unsigned char decryptedtext[128];

    ciphertext_len = encrypt(plaintext, plaintext_len, key, iv, ciphertext);

    printf("Ciphertext is:\n");
    BIO_dump_fp(stdout, (const char *)ciphertext, ciphertext_len);

    int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);

    if(decryptedtext_len == -1) {
      printf("Decryption failed!\n");
      exit(1);
    }

    decryptedtext[decryptedtext_len] = '\0';

    printf("\nDecrypted text is:\n%s\n", decryptedtext);

    return 0;
}