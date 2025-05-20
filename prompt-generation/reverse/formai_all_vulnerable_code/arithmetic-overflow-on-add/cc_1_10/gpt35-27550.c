//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <openssl/evp.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 32
#define SALT_SIZE 16
#define ITERATIONS 10000

bool encrypt(char *plaintext, int plaintext_len, char *password, unsigned char *ciphertext, char *salt, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;
    int len, outlen;
    unsigned char key[KEY_SIZE];
    bool result = false;

    if (EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha256(), (const unsigned char *)salt, (const unsigned char *)password, strlen(password), ITERATIONS, key, NULL) == 0) {
        printf("Error generating key.\n");
        return false;
    }

    ctx = EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX_set_padding(ctx, 1);
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, (const unsigned char *)salt);

    if (EVP_EncryptUpdate(ctx, ciphertext, &len, (const unsigned char*)plaintext, plaintext_len) == 0) {
        printf("Error encrypting.\n");
        goto end;
    }

    outlen = len;

    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) == 0) {
        printf("Error finalizing encryption.\n");
        goto end;
    }

    outlen += len;
    *ciphertext_len = outlen;
    result = true;

    end:
    EVP_CIPHER_CTX_free(ctx);
    return result;
}

bool decrypt(unsigned char *ciphertext, int ciphertext_len, char *password, unsigned char *plaintext, char *salt) {
    EVP_CIPHER_CTX *ctx;
    int len, outlen;
    unsigned char key[KEY_SIZE];
    bool result = false;

    if (EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha256(), (const unsigned char *)salt, (const unsigned char *)password, strlen(password), ITERATIONS, key, NULL) == 0) {
        printf("Error generating key.\n");
        return false;
    }

    ctx = EVP_CIPHER_CTX_new();
    EVP_CIPHER_CTX_set_padding(ctx, 1);
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, (const unsigned char *)salt);

    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) == 0) {
        printf("Error decrypting.\n");
        goto end;
    }

    outlen = len;

    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &len) == 0) {
        printf("Error finalizing decryption.\n");
        goto end;
    }

    outlen += len;
    result = true;

    end:
    EVP_CIPHER_CTX_free(ctx);
    return result;
}

int main() {
    char *plaintext = "Hello, world!";
    char *password = "mysecretpassword";
    char salt[SALT_SIZE];
    unsigned char ciphertext[strlen(plaintext) + BLOCK_SIZE], decrypted[strlen(plaintext) + BLOCK_SIZE];
    int ciphertext_len;

    // Generate random salt
    if (RAND_bytes((unsigned char *)&salt, SALT_SIZE) == 0) {
        printf("Error generating salt.\n");
        exit(EXIT_FAILURE);
    }

    // Encrypt plaintext
    if (encrypt(plaintext, strlen(plaintext), password, ciphertext, salt, &ciphertext_len)) {
        printf("Plaintext: %s\n", plaintext);
        printf("Ciphertext: ");
        for (int i = 0; i < ciphertext_len; i++) {
            printf("%02x", ciphertext[i]);
        }
        printf("\n");

        // Decrypt ciphertext
        if (decrypt(ciphertext, ciphertext_len, password, decrypted, salt)) {
            printf("Decrypted Text: %s\n", decrypted);
        }
    }

    return 0;
}