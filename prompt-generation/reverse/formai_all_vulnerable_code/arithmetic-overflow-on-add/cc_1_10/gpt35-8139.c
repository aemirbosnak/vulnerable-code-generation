//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// Encryption function
int encrypt(unsigned char *plaintext, int plaintextLen, unsigned char *key,
  unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertextLen;

    if(!(ctx = EVP_CIPHER_CTX_new())) return -1;
    if(EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv) != 1) return -1;
    if(EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintextLen) != 1) return -1;
    ciphertextLen = len;
    if(EVP_EncryptFinal_ex(ctx, ciphertext+len, &len) != 1) return -1;
    ciphertextLen += len;

    EVP_CIPHER_CTX_free(ctx);
    return ciphertextLen;
}

// Decryption function
int decrypt(unsigned char *ciphertext, int ciphertextLen, unsigned char *key,
  unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintextLen;

    if(!(ctx = EVP_CIPHER_CTX_new())) return -1;
    if(EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv) != 1) return -1;
    if(EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertextLen) != 1) return -1;
    plaintextLen = len;
    if(EVP_DecryptFinal_ex(ctx, plaintext+len, &len) != 1) return -1;
    plaintextLen += len;

    EVP_CIPHER_CTX_free(ctx);
    return plaintextLen;
}

int main() {
    unsigned char *plaintext = "The quick brown fox jumps over the lazy dog";
    unsigned char key[] = "0123456789abcdef";
    unsigned char iv[] = "0123456789abcdef";
    unsigned char ciphertext[strlen(plaintext)];
    unsigned char decryptedtext[strlen(plaintext)];

    int ciphertextLen = encrypt(plaintext, strlen(plaintext), key, iv, ciphertext);
    printf("Ciphertext is:\n");
    for(int i = 0; i < ciphertextLen; i++) {
        printf("%02x", ciphertext[i]);
    }

    int decryptedtextLen = decrypt(ciphertext, ciphertextLen, key, iv, decryptedtext);
    decryptedtext[decryptedtextLen] = '\0';

    printf("\nDecrypted text is:\n%s\n", decryptedtext);

    return 0;
}