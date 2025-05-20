//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define IV_LENGTH 16
#define KEY_LENGTH 32
#define BUFFER_SIZE 1024

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv,
             unsigned char *ciphertext, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, ciphertext_len, plaintext, plaintext_len))
        handleErrors();

    int len;
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + *ciphertext_len, &len))
        handleErrors();
    *ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv,
             unsigned char *plaintext, int *plaintext_len) {
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if (1 != EVP_DecryptUpdate(ctx, plaintext, plaintext_len, ciphertext, ciphertext_len))
        handleErrors();

    int len;
    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + *plaintext_len, &len))
        handleErrors();
    *plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void generate_key_and_iv(unsigned char *key, unsigned char *iv) {
    if (!RAND_bytes(key, KEY_LENGTH)) {
        fprintf(stderr, "Key generation failed.\n");
        exit(EXIT_FAILURE);
    }
    if (!RAND_bytes(iv, IV_LENGTH)) {
        fprintf(stderr, "IV generation failed.\n");
        exit(EXIT_FAILURE);
    }
}

void print_hex(unsigned char *data, int len) {
    for (int i = 0; i < len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {
    unsigned char key[KEY_LENGTH], iv[IV_LENGTH];
    
    generate_key_and_iv(key, iv);

    unsigned char plaintext[BUFFER_SIZE] = "This is a secret message that needs encryption.";
    unsigned char ciphertext[BUFFER_SIZE];
    unsigned char decryptedtext[BUFFER_SIZE];
    int decryptedtext_len, ciphertext_len;

    printf("Original Plaintext: %s\n", plaintext);

    encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext, &ciphertext_len);
    printf("Ciphertext: ");
    print_hex(ciphertext, ciphertext_len);

    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, &decryptedtext_len);
    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the decrypted string

    printf("Decrypted Plaintext: %s\n", decryptedtext);
    
    printf("Encryption Key: ");
    print_hex(key, KEY_LENGTH);
    
    printf("Initialization Vector: ");
    print_hex(iv, IV_LENGTH);

    return 0;
}