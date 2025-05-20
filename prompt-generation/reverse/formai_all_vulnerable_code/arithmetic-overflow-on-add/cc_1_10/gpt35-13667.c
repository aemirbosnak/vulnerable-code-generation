//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<openssl/evp.h>

#define AES_BLOCK_SIZE 128

/*Encrypt the data using Advanced Encryption Standard(AES) with Cipher Block Chaining(CBC) mode*/
int aes_cbc_encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext){
    EVP_CIPHER_CTX *ctx;
    int len, ciphertext_len;
    if(!(ctx = EVP_CIPHER_CTX_new())) return -1;
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv)) return -1;
    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) return -1;
    ciphertext_len = len;
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) return -1;
    ciphertext_len += len;
    EVP_CIPHER_CTX_free(ctx);
    return ciphertext_len;
}

/*Decrypt the data using Advanced Encryption Standard(AES) with Cipher Block Chaining(CBC) mode*/
int aes_cbc_decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext){
    EVP_CIPHER_CTX *ctx;
    int len, plaintext_len;
    if(!(ctx = EVP_CIPHER_CTX_new())) return -1;
    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv)) return -1;
    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)) return -1;
    plaintext_len = len;
    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) return -1;
    plaintext_len += len;
    EVP_CIPHER_CTX_free(ctx);
    return plaintext_len;
}

int main(){
    unsigned char *message = "Hello, World!";
    unsigned char *key = (unsigned char *)"ThisIsMySecretKey";
    unsigned char *iv = (unsigned char *)"0123456789012345";
    unsigned char ciphertext[AES_BLOCK_SIZE], decryptedtext[AES_BLOCK_SIZE];
    memset(ciphertext, 0, sizeof(ciphertext));
    memset(decryptedtext, 0, sizeof(decryptedtext));
    int decryptedtext_len, ciphertext_len;
    ciphertext_len = aes_cbc_encrypt(message, strlen(message), key, iv, ciphertext);
    decryptedtext_len = aes_cbc_decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);
    printf("Original Message: %s\n", message);
    printf("Encrypted Message: %s\n", ciphertext);
    printf("Decrypted Message: %s\n", decryptedtext);
    return 0;
}