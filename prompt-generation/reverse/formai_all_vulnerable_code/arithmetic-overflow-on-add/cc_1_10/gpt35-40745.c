//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void handleErrors(void)
{
    printf("Error occurred\n");
    exit(EXIT_FAILURE);
}

void encrypt(const unsigned char *plaintext, int plaintext_len, const unsigned char *key, const unsigned char *iv, unsigned char *ciphertext)
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

void decrypt(const unsigned char *ciphertext, int ciphertext_len, const unsigned char *key, const unsigned char *iv, unsigned char *plaintext)
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

int main(void)
{
    unsigned char plaintext[] = "This is a top secret message";
    unsigned char key[] = "mysecretkeythatnobodyknows";
    unsigned char iv[16] = {0};

    unsigned char ciphertext[sizeof(plaintext) + EVP_MAX_BLOCK_LENGTH];
    unsigned char decryptedtext[sizeof(ciphertext)];

    int ciphertext_len, decryptedtext_len;

    // Encryption
    encrypt(plaintext, strlen((char*)plaintext), key, iv, ciphertext);

    // Decryption
    decrypt(ciphertext, strlen((char*)ciphertext), key, iv, decryptedtext);

    printf("Original: %s\n", plaintext);    
    printf("Encrypted: ");
    for(int i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    printf("Decrypted: %s\n", decryptedtext);    

    return 0;
}