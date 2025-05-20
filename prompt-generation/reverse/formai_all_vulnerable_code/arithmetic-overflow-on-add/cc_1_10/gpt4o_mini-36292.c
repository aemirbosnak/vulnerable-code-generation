//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/err.h>

#define AES_256_KEY_SIZE 32
#define AES_256_IV_SIZE 16

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

void encrypt(unsigned char *plaintext, int plaintext_len, 
             unsigned char *key, unsigned char *iv, 
             unsigned char *ciphertext, int *ciphertext_len) {

    EVP_CIPHER_CTX *ctx;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) 
        handleErrors();

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, ciphertext_len, plaintext, plaintext_len)) 
        handleErrors();

    int len;
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + *ciphertext_len, &len)) 
        handleErrors();
    
    *ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, 
             unsigned char *key, unsigned char *iv, 
             unsigned char *plaintext, int *plaintext_len) {

    EVP_CIPHER_CTX *ctx;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) 
        handleErrors();

    if(1 != EVP_DecryptUpdate(ctx, plaintext, plaintext_len, ciphertext, ciphertext_len)) 
        handleErrors();

    int len;
    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + *plaintext_len, &len)) 
        handleErrors();
    
    *plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void printHex(unsigned char *data, int len) {
    for(int i = 0; i < len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {
    unsigned char key[AES_256_KEY_SIZE] = "01234567890123456789012345678901"; // 32 bytes key
    unsigned char iv[AES_256_IV_SIZE] = "0123456789012345"; // 16 bytes IV

    unsigned char plaintext[] = "Hello, world! This is a test of encryption.";
    unsigned char ciphertext[128];
    unsigned char decryptedtext[128];

    int decryptedtext_len, ciphertext_len;

    printf("Original plaintext: %s\n", plaintext);
    
    encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext, &ciphertext_len);

    printf("Ciphertext: ");
    printHex(ciphertext, ciphertext_len);

    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, &decryptedtext_len);

    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the string

    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}