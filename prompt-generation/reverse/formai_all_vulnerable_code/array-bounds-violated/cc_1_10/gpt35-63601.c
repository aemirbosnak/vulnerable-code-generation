//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rand.h>
#include <openssl/evp.h>

#define KEY_SIZE 32 // AES 256-bit key size
#define IV_SIZE 16 // 128-bit IV size

void secure_memzero(void *ptr, size_t size) {
    volatile unsigned char *p = ptr;
    while (size--) {
        *p++ = 0;
    }
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
            unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())) {
        return -1;
    }

    if(!EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    if(!EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }
    ciphertext_len = len;

    if(!EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
            unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())) {
        return -1;
    }

    if(!EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    if(!EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }
    plaintext_len = len;

    if(!EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

int main() {
    unsigned char plaintext[10000], ciphertext[10000], decryptedtext[10000];
    unsigned char key[KEY_SIZE], iv[IV_SIZE];
    int plaintext_len, ciphertext_len, decryptedtext_len;

    RAND_bytes(key, KEY_SIZE);
    RAND_bytes(iv, IV_SIZE);

    printf("Enter plaintext: ");
    fgets((char*)plaintext, 10000, stdin);
    plaintext_len = strlen((char*)plaintext);

    /* Encrypt the plaintext */
    ciphertext_len = encrypt(plaintext, plaintext_len, key, iv, ciphertext);

    if(ciphertext_len == -1) {
        fprintf(stderr, "Encryption failed\n");
        return -1;
    }

    printf("Ciphertext is:\n");
    for(int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    /* Decrypt the ciphertext */
    decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);

    if(decryptedtext_len == -1) {
        fprintf(stderr, "Decryption failed\n");
        return -1;
    }

    decryptedtext[decryptedtext_len] = '\0';

    printf("Decrypted text is:\n%s\n", decryptedtext);

    secure_memzero(plaintext, plaintext_len);
    secure_memzero(ciphertext, ciphertext_len);
    secure_memzero(decryptedtext, decryptedtext_len);
    secure_memzero(key, KEY_SIZE);
    secure_memzero(iv, IV_SIZE);

    return 0;
}