//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define KEY_LENGTH 32
#define IV_LENGTH 16
#define BUFFER_SIZE 1024

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

void generate_key_and_iv(unsigned char *key, unsigned char *iv) {
    if (!RAND_bytes(key, KEY_LENGTH)) {
        handleErrors();
    }
    
    if (!RAND_bytes(iv, IV_LENGTH)) {
        handleErrors();
    }
}

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext, int *ciphertext_len) {
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

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext, int *plaintext_len) {
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

void print_hex(unsigned char *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {
    unsigned char key[KEY_LENGTH];
    unsigned char iv[IV_LENGTH];

    generate_key_and_iv(key, iv);

    char *plaintext = "This is a secret message";
    unsigned char ciphertext[BUFFER_SIZE];
    int ciphertext_len;

    encrypt((unsigned char *)plaintext, strlen(plaintext), key, iv, ciphertext, &ciphertext_len);

    printf("Ciphertext (hex): ");
    print_hex(ciphertext, ciphertext_len);

    unsigned char decryptedtext[BUFFER_SIZE];
    int decryptedtext_len;

    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, &decryptedtext_len);
    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the decrypted text

    printf("Decrypted text: %s\n", decryptedtext);

    printf("Key (hex): ");
    print_hex(key, KEY_LENGTH);
    printf("IV (hex): ");
    print_hex(iv, IV_LENGTH);

    return 0;
}