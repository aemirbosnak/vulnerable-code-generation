//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/evp.h>

void handleErrors(void)
{
    printf("Error occurred.\n");
    exit(1);    
}

int main(void)
{
    char *input = "This is my secret message.";
    unsigned char iv[EVP_MAX_IV_LENGTH] = {0};
    unsigned char key[EVP_MAX_KEY_LENGTH] = {0};
    unsigned char ciphertext[1024] = {0};
    unsigned char decryptedtext[1024] = {0};
    int decryptedtext_len, ciphertext_len;

    // Generate a random key and iv
    if (!RAND_bytes(key, 256/8) || !RAND_bytes(iv, EVP_MAX_IV_LENGTH))
    {
        printf("Failed to generate random key and iv.\n");
        exit(1);
    }

    // Encrypt the plaintext
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
    {
        printf("EVP_EncryptInit_ex failed.\n");
        handleErrors();
    }

    if (!EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, (unsigned char *) input, strlen(input)))
    {
        printf("Encryption failed.\n");
        handleErrors();
    }

    if (!EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len))
    {
        printf("Encryption failed.\n");
        handleErrors();
    }
    ciphertext_len += ciphertext_len;

    EVP_CIPHER_CTX_free(ctx);

    // Decrypt the ciphertext
    ctx = EVP_CIPHER_CTX_new();
    if (!EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
    {
        printf("EVP_DecryptInit_ex failed.\n");
        handleErrors();
    }

    if (!EVP_DecryptUpdate(ctx, decryptedtext, &decryptedtext_len, ciphertext, ciphertext_len))
    {
        printf("Decryption failed.\n");
        handleErrors();
    }

    if (!EVP_DecryptFinal_ex(ctx, decryptedtext + decryptedtext_len, &decryptedtext_len))
    {
        printf("Decryption failed.\n");
        handleErrors();
    }
    decryptedtext_len += decryptedtext_len;

    EVP_CIPHER_CTX_free(ctx);

    // Verify the plaintext and decryptedtext are the same
    if (strcmp(input, decryptedtext) == 0)
    {
        printf("Encryption and decryption successful.\n");
    }
    else
    {
        printf("Encryption and decryption unsuccessful.\n");
    }

    return 0;
}