//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <openssl/err.h>

#define AES_KEY_LENGTH 128
#define AES_BLOCK_SIZE 16

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

void generate_key(unsigned char *key, const char *password) {
    if (!PKCS5_PBKDF2_HMAC(password, strlen(password), NULL, 0, 10000, EVP_sha256(), AES_KEY_LENGTH / 8, key)) {
        handleErrors();
    }
}

void encrypt(const unsigned char *plaintext, int plaintext_len, unsigned char *ciphertext, unsigned char *key, unsigned char *iv) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv) != 1) handleErrors();

    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1) handleErrors();
    ciphertext_len = len;

    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) handleErrors();
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(const unsigned char *ciphertext, int ciphertext_len, unsigned char *plaintext, unsigned char *key, unsigned char *iv) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv) != 1) handleErrors();

    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) != 1) handleErrors();
    plaintext_len = len;

    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &len) != 1) handleErrors();
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

int main(void) {
    const char *password = "securePassword";
    unsigned char key[AES_KEY_LENGTH/8];
    unsigned char iv[AES_BLOCK_SIZE];
    
    unsigned char *plaintext = (unsigned char *)"This is a secret message";
    unsigned char ciphertext[128];
    unsigned char decryptedtext[128];

    // Generate key and IV
    generate_key(key, password);
    if (!RAND_bytes(iv, sizeof(iv))) handleErrors();

    printf("Original message: %s\n", plaintext);

    // Encrypt the plaintext
    encrypt(plaintext, strlen((char *)plaintext), ciphertext, key, iv);
    printf("Ciphertext is:");
    for (int i = 0; i < strlen((char *)plaintext); i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the ciphertext
    decrypt(ciphertext, strlen((char *)plaintext), decryptedtext, key, iv);
    decryptedtext[strlen((char *)plaintext)] = '\0'; // Null terminate the string

    printf("Decrypted message: %s\n", decryptedtext);

    return 0;
}