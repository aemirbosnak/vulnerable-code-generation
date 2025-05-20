//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define KEY_SIZE 32 // AES-256
#define IV_SIZE 16  // AES block size
#define BUFFER_SIZE 1024

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

void generateKeyAndIV(unsigned char *key, unsigned char *iv) {
    if (!RAND_bytes(key, KEY_SIZE)) {
        handleErrors();
    }
    if (!RAND_bytes(iv, IV_SIZE)) {
        handleErrors();
    }
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) handleErrors();
    ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();

    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)) handleErrors();
    plaintext_len = len;

    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    return plaintext_len;
}

int main() {
    unsigned char key[KEY_SIZE];
    unsigned char iv[IV_SIZE];
    unsigned char plaintext[BUFFER_SIZE];
    unsigned char ciphertext[BUFFER_SIZE];
    unsigned char decryptedtext[BUFFER_SIZE];

    printf("Enter a message to encrypt: ");
    fgets((char *)plaintext, BUFFER_SIZE, stdin);
    plaintext[strcspn((char *)plaintext, "\n")] = 0; // Remove newline character

    generateKeyAndIV(key, iv);
    
    int plaintext_len = strlen((char *)plaintext);
    int ciphertext_len = encrypt(plaintext, plaintext_len, key, iv, ciphertext);
    
    printf("Ciphertext is:\n");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);
    decryptedtext[decryptedtext_len] = '\0'; // Null terminate the decrypted text

    printf("Decrypted text is: %s\n", decryptedtext);

    return 0;
}