//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int encrypt_data(unsigned char *plaintext, int plaintext_len, unsigned char *key,
                 unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    /* Create and initialise the context */
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        return -1;
    }

    /* Initialise the encryption operation */
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    /* Encrypt the plaintext */
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }
    ciphertext_len = len;

    /* Finalise the encryption operation */
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }
    ciphertext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

int decrypt_data(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
                 unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;
    int ret;

    /* Create and initialise the context */
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        return -1;
    }

    /* Initialise the decryption operation */
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }

    /* Decrypt the ciphertext */
    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)) {
        EVP_CIPHER_CTX_free(ctx);
        return -1;
    }
    plaintext_len = len;

    /* Finalise the decryption operation */
    ret = EVP_DecryptFinal_ex(ctx, plaintext + len, &len);

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    if (ret > 0) {
        plaintext_len += len;
        return plaintext_len;
    } else {
        return -1;
    }
}

int main(int argc, char *argv[]) {
    unsigned char *plaintext = (unsigned char *)"This is a secret message";
    unsigned char *key = (unsigned char *)"0123456789abcdef";
    unsigned char *iv = (unsigned char *)"fedcba9876543210";
    unsigned char ciphertext[128], decrypted_text[128];
    int ciphertext_len, decrypted_len;

    /* Encrypt the plaintext */
    ciphertext_len = encrypt_data(plaintext, strlen((char *)plaintext), key, iv, ciphertext);
    if (ciphertext_len == -1) {
        fprintf(stderr, "Encryption failed\n");
        exit(1);
    }
    printf("Ciphertext is:\n");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    /* Decrypt the ciphertext */
    decrypted_len = decrypt_data(ciphertext, ciphertext_len, key, iv, decrypted_text);
    if (decrypted_len == -1) {
        fprintf(stderr, "Decryption failed\n");
        exit(1);
    }
    decrypted_text[decrypted_len] = '\0';
    printf("Decrypted text is:\n%s\n", decrypted_text);

    exit(0);
}