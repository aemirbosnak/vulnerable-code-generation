//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define KEY_SIZE 16
#define IV_SIZE 16
#define MAX_INPUT_SIZE 1024

void handleErrors(void)
{
    printf("An error occurred\n");
    exit(1);
}

void encrypt(char *plaintext, int plaintext_len, unsigned char *key,
             unsigned char *iv, char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;

    int len;
    int ciphertext_len;

    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv))
        handleErrors();

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();

    ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        handleErrors();

    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(char *ciphertext, int ciphertext_len, unsigned char *key,
             unsigned char *iv, char *plaintext)
{
    EVP_CIPHER_CTX *ctx;

    int len;
    int plaintext_len;

    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv))
        handleErrors();

    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();

    plaintext_len = len;

    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
        handleErrors();

    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

int main(int argc, char *argv[])
{
    unsigned char key[KEY_SIZE];
    unsigned char iv[IV_SIZE];
    char plaintext[MAX_INPUT_SIZE];
    char ciphertext[MAX_INPUT_SIZE];
    char decryptedtext[MAX_INPUT_SIZE];
    int decryptedtext_len, ciphertext_len;

    // Generate random key and IV
    RAND_bytes(key, KEY_SIZE);
    RAND_bytes(iv, IV_SIZE);

    printf("Enter plaintext: ");
    fgets(plaintext, MAX_INPUT_SIZE - 1, stdin);

    // Remove newline character
    plaintext[strcspn(plaintext, "\n")] = 0;

    // Encrypt plaintext
    encrypt(plaintext, strlen(plaintext), key, iv, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt ciphertext
    decrypt(ciphertext, strlen(ciphertext), key, iv, decryptedtext);
    decryptedtext_len = strlen(decryptedtext);

    // Add null terminator to decrypted text
    decryptedtext[strcspn(decryptedtext, "\n")] = 0;

    printf("Decrypted Text : %s\n", decryptedtext);

    return 0;
}