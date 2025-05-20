//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void handleErrors(void)
{
    printf("An error occurred. Exiting program.\n");
    exit(1);
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;
  
    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();
  
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();
  
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
  
    ciphertext_len = len;
  
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        handleErrors();
  
    ciphertext_len += len;
  
    EVP_CIPHER_CTX_free(ctx);
  
    return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;
  
    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();
  
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();
  
    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();
  
    plaintext_len = len;
  
    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
        handleErrors();
  
    plaintext_len += len;
  
    EVP_CIPHER_CTX_free(ctx);
  
    return plaintext_len;
}

int main(void)
{
    unsigned char *key = (unsigned char *)"01234567890123456789012345678901";
    unsigned char *iv = (unsigned char *)"01234567890123456";
    
    unsigned char *plaintext = (unsigned char *)"The quick brown fox jumps over the lazy dog";
    int plaintext_len = strlen((char *)plaintext);
  
    unsigned char ciphertext[1024];
    int ciphertext_len;
  
    unsigned char decryptedtext[1024];
    int decryptedtext_len;
    
    printf("Original text: %s\n", plaintext);
    
    // Encryption process
    ciphertext_len = encrypt(plaintext, plaintext_len, key, iv, ciphertext);
  
    printf("Encrypted text: ");
    for (int i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    // Decryption process
    decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);

    decryptedtext[decryptedtext_len] = '\0';

    printf("Decrypted text: %s\n", decryptedtext);
  
    return 0;
}