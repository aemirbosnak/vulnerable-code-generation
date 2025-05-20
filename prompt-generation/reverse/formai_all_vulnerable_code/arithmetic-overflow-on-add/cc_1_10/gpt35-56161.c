//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <openssl/rand.h>
#include <openssl/evp.h>

#define MAX_LEN 1024

bool encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
             unsigned char *iv, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;
    int len, ciphertext_len;

    if (!(ctx = EVP_CIPHER_CTX_new()))
        return false;

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        return false;

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        return false;
    ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        return false;
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return true;
}

bool decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
             unsigned char *iv, unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;
    int len, plaintext_len;
    unsigned char *decryptedtext = malloc(MAX_LEN);

    if (!(ctx = EVP_CIPHER_CTX_new()))
        return false;

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        return false;

    if (1 != EVP_DecryptUpdate(ctx, decryptedtext, &len, ciphertext, ciphertext_len))
        return false;
    plaintext_len = len;

    if (1 != EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len))
        return false;
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    memcpy(plaintext, decryptedtext, plaintext_len);
    free(decryptedtext);

    return true;
}

int main()
{
    unsigned char plaintext[MAX_LEN];
    unsigned char ciphertext[MAX_LEN];
    unsigned char key[32];
    unsigned char iv[16];
    int plaintext_len, ciphertext_len;

    // Generate a random key and initialization vector
    if (RAND_bytes(key, 32) == 0) {
        fprintf(stderr, "Error generating random key\n");
        exit(EXIT_FAILURE);
    }
    if (RAND_bytes(iv, 16) == 0) {
        fprintf(stderr, "Error generating random iv\n");
        exit(EXIT_FAILURE);
    }

    // Prompt user for plaintext
    printf("Enter plaintext: ");
    fgets((char *) plaintext, MAX_LEN, stdin);
    plaintext_len = strlen((char *) plaintext);
    if (plaintext_len > 0 && plaintext[plaintext_len - 1] == '\n')
        plaintext[--plaintext_len] = '\0';

    // Encrypt plaintext
    if (!encrypt(plaintext, plaintext_len, key, iv, ciphertext)) {
        fprintf(stderr, "Error encrypting plaintext!\n");
        exit(EXIT_FAILURE);
    }
    ciphertext_len = strlen((char *) ciphertext);

    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Decrypt ciphertext
    unsigned char decryptedtext[MAX_LEN];
    if (!decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext)) {
        fprintf(stderr, "Error decrypting ciphertext!\n");
        exit(EXIT_FAILURE);
    }

    // Print decrypted plaintext
    printf("Decrypted text: %s\n", decryptedtext);

    return EXIT_SUCCESS;
}