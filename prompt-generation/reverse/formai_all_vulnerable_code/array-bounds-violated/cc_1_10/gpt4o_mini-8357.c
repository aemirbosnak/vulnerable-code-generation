//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define AES_KEY_LENGTH 256
#define IV_LENGTH 16
#define BUFFER_SIZE 1024

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv,
             unsigned char *ciphertext, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handleErrors();

    int len;
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1) handleErrors();
    *ciphertext_len = len;

    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) handleErrors();
    *ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv,
             unsigned char *plaintext, int *plaintext_len) {
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handleErrors();

    int len;
    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) != 1) handleErrors();
    *plaintext_len = len;

    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &len) != 1) handleErrors();
    *plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void generate_key_iv(unsigned char *key, unsigned char *iv) {
    if (!RAND_bytes(key, AES_KEY_LENGTH / 8)) handleErrors();
    if (!RAND_bytes(iv, IV_LENGTH)) handleErrors();
}

void print_hex(unsigned char *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {
    unsigned char key[AES_KEY_LENGTH / 8];
    unsigned char iv[IV_LENGTH];
    unsigned char plaintext[BUFFER_SIZE] = "This is a secret message!";
    unsigned char ciphertext[BUFFER_SIZE];
    unsigned char decryptedtext[BUFFER_SIZE];
    int decryptedtext_len;

    generate_key_iv(key, iv);

    int ciphertext_len;
    encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext, &ciphertext_len);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext (hex): ");
    print_hex(ciphertext, ciphertext_len);

    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, &decryptedtext_len);

    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the string
    printf("Decrypted text: %s\n", decryptedtext);

    printf("Key (hex): ");
    print_hex(key, sizeof(key));
    printf("IV (hex): ");
    print_hex(iv, sizeof(iv));

    return 0;
}