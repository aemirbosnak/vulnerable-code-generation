//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/evp.h>

void handleErrors(void)
{
    printf("Error occurred with %{EVP_ErrorMessage}\n");
    exit(1);    
}

int main(void)
{
    // Create plaintext and key buffers
    unsigned char *plaintext = (unsigned char *)"Hello World!";
    unsigned char *key = (unsigned char *)"MySecretKey123";

    // Create output buffer for ciphertext and iv (initialization vector)
    unsigned char ciphertext[128];
    unsigned char iv[EVP_MAX_IV_LENGTH];
    memset(ciphertext, 0, sizeof(ciphertext));
    memset(iv, 0, sizeof(iv));

    // Initialize encryption context
    EVP_CIPHER_CTX *ctx;
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        handleErrors();
    }

    // Set the encryption algorithm to AES-256-CBC
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        handleErrors();
    }

    int plaintext_len = strlen((char *)plaintext);
    int ciphertext_len;

    // Encrypt the plaintext
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, plaintext_len)) {
        handleErrors();
    }

    // Finalize the encryption
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len)) {
        handleErrors();
    }

    ciphertext_len += ciphertext_len;

    printf("Ciphertext is: \n");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%x ", ciphertext[i]);
    }
    printf("\n");

    // Cleanup context
    EVP_CIPHER_CTX_free(ctx);

    return 0;
}