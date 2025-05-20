//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/evp.h>
#include <openssl/err.h>

void handleErrors(void)
{
    ERR_print_errors_fp(stderr);
    abort();
}

void encrypt_decrypt(int mode)
{
    EVP_CIPHER_CTX *ctx;
    unsigned char iv[16];
    unsigned char key[] = "mysecretkey";
    unsigned char *plaintext = (unsigned char *)"The quick brown fox jumps over the lazy dog";
    int plaintext_len = strlen((char *)plaintext);
    int len;
    unsigned char ciphertext[32];
    unsigned char decryptedtext[32];

    memset(iv, 0, sizeof(iv));

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (mode == 1) {
        if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handleErrors();

        if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1) handleErrors();
    } else if (mode == 0) {
        if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handleErrors();

        if (EVP_DecryptUpdate(ctx, decryptedtext, &len, ciphertext, sizeof(ciphertext)) != 1) handleErrors();
    } else {
        handleErrors();
    }

    if (mode == 1) {
        if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) handleErrors();
        printf("Ciphertext is:");
        for (int i = 0; i < len + 16; i++) {
            printf("%02x", ciphertext[i]);
        }
        printf("\n");
    } else if (mode == 0) {
        if (EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len) != 1) handleErrors();

        decryptedtext[plaintext_len] = '\0';

        printf("Decrypted text is: %s\n", decryptedtext);
    }

    EVP_CIPHER_CTX_free(ctx);
}

int main()
{
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    encrypt_decrypt(1); // Encrypt
    encrypt_decrypt(0); // Decrypt

    ERR_free_strings();
    EVP_cleanup();

    return 0;
}