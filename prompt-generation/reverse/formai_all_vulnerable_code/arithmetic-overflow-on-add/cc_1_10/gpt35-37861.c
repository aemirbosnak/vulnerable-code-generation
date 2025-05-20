//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void handleErrors(void)
{
    printf("Error\n");
    exit(EXIT_FAILURE);
}

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;

    int len;
    int ciphertext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();

    ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;

    int len;
    int plaintext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();

    plaintext_len = len;

    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

int main()
{
    unsigned char key[EVP_MAX_KEY_LENGTH];
    unsigned char iv[EVP_MAX_IV_LENGTH];
    unsigned char plaintext[] = "This is a test plaintext";
    unsigned char ciphertext[512];
    unsigned char decryptedtext[512];
    int decryptedtext_len;

    int plaintext_len = strlen((char *)plaintext);
    int key_len, iv_len;

    // Generate a random key and IV
    key_len = EVP_CIPHER_key_length(EVP_aes_256_cbc());
    iv_len = EVP_CIPHER_iv_length(EVP_aes_256_cbc());
    RAND_bytes(key, key_len);
    RAND_bytes(iv, iv_len);

    // Encrypt plaintext
    encrypt(plaintext, plaintext_len, key, iv, ciphertext);

    // Decrypt the ciphertext back into plaintext
    decrypt(ciphertext, strlen((char *)ciphertext), key, iv, decryptedtext);

    // Make sure the decrypted text matches the original plaintext
    decryptedtext_len = strlen((char *)decryptedtext);
    if (strncmp((char *)plaintext, (char *)decryptedtext, decryptedtext_len) == 0) {
        printf("Cryptography example completed successfully!\n");
    } else {
        printf("Cryptography example failed!\n");
    }

    return 0;
}