//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/err.h>

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

void encrypt(const unsigned char *plaintext, int plaintext_len, const unsigned char *key,
             const unsigned char *iv, unsigned char *ciphertext, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, ciphertext_len, plaintext, plaintext_len))
        handleErrors();

    int len;
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + *ciphertext_len, &len)) handleErrors();
    *ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(const unsigned char *ciphertext, int ciphertext_len, const unsigned char *key,
             const unsigned char *iv, unsigned char *plaintext, int *plaintext_len) {
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if (1 != EVP_DecryptUpdate(ctx, plaintext, plaintext_len, ciphertext, ciphertext_len))
        handleErrors();

    int len;
    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + *plaintext_len, &len)) handleErrors();
    *plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <text_to_encrypt>\n", argv[0]);
        return 1;
    }

    // Set up the key and IV for encryption
    unsigned char key[32];  // AES-256 key size
    unsigned char iv[16];   // AES block size

    // Generate a random key and IV
    if (RAND_bytes(key, sizeof(key)) != 1) handleErrors();
    if (RAND_bytes(iv, sizeof(iv)) != 1) handleErrors();

    unsigned char *plaintext = (unsigned char *)argv[1];
    int plaintext_len = strlen((char *)plaintext);

    unsigned char ciphertext[128];
    int ciphertext_len;

    // Encrypt the plaintext
    encrypt(plaintext, plaintext_len, key, iv, ciphertext, &ciphertext_len);
    
    printf("Ciphertext is:\n");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    unsigned char decryptedtext[128];
    int decryptedtext_len;

    // Decrypt the ciphertext
    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, &decryptedtext_len);

    // Null-terminate the decrypted text
    decryptedtext[decryptedtext_len] = '\0';
    
    printf("Decrypted text is:\n%s\n", decryptedtext);

    // Clean up
    memset(key, 0, sizeof(key));
    memset(iv, 0, sizeof(iv));
    memset(ciphertext, 0, sizeof(ciphertext));
    memset(decryptedtext, 0, sizeof(decryptedtext));

    return 0;
}