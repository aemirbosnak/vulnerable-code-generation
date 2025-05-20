//Code Llama-13B DATASET v1.0 Category: Modern Encryption ; Style: careful
// Modern Encryption Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// Function to encrypt a string using AES-256-GCM
int encrypt(const char* plaintext, const char* key, const char* iv, char* ciphertext) {
    int len = strlen(plaintext);
    int ciphertext_len = 0;

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, (const unsigned char*)key, (const unsigned char*)iv);
    EVP_EncryptUpdate(ctx, (unsigned char*)ciphertext, &ciphertext_len, (const unsigned char*)plaintext, len);
    EVP_EncryptFinal_ex(ctx, (unsigned char*)ciphertext + ciphertext_len, &len);
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

// Function to decrypt a string using AES-256-GCM
int decrypt(const char* ciphertext, const char* key, const char* iv, char* plaintext) {
    int len = strlen(ciphertext);
    int plaintext_len = 0;

    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, (const unsigned char*)key, (const unsigned char*)iv);
    EVP_DecryptUpdate(ctx, (unsigned char*)plaintext, &plaintext_len, (const unsigned char*)ciphertext, len);
    EVP_DecryptFinal_ex(ctx, (unsigned char*)plaintext + plaintext_len, &len);
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

int main() {
    const char* plaintext = "Hello, World!";
    const char* key = "my secret key";
    const char* iv = "my initialization vector";

    char ciphertext[128];
    char plaintext_dec[128];

    int ciphertext_len = encrypt(plaintext, key, iv, ciphertext);
    int plaintext_len = decrypt(ciphertext, key, iv, plaintext_dec);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    printf("Decrypted plaintext: %s\n", plaintext_dec);

    return 0;
}