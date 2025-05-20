//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/aes.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 32

void handleErrors(void)
{
    printf("Error occurred\n");
    exit(1);
}

int main(void)
{
    unsigned char key[KEY_SIZE];
    unsigned char iv[BLOCK_SIZE];
    unsigned char plaintext[] = "This is a sample plaintext for encryption";
    unsigned char ciphertext[sizeof(plaintext) + BLOCK_SIZE];
    unsigned char decryptedtext[sizeof(ciphertext)];

    /* Generate a random key */
    if (!RAND_bytes(key, sizeof(key))){
        handleErrors();
    }

    /* Generate a random IV */
    if (!RAND_bytes(iv, sizeof(iv))){
        handleErrors();
    }

    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();

    /* Set the encryption key and IV */
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)){
        handleErrors();
    }

    int len, ciphertext_len;

    /* Encrypt plaintext */
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, sizeof(plaintext))){
        handleErrors();
    }
    ciphertext_len = len;

    /* Finalize encryption */
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)){
        handleErrors();
    }
    ciphertext_len += len;

    /* Set decryption key and IV */
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)){
        handleErrors();
    }

    int decryptedtext_len;

    /* Decrypt ciphertext */
    if (1 != EVP_DecryptUpdate(ctx, decryptedtext, &len, ciphertext, ciphertext_len)){
        handleErrors();
    }
    decryptedtext_len = len;

    /* Finalize decryption */
    if (1 != EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len)){
        handleErrors();
    }
    decryptedtext_len += len;

    /* Add null terminator to decrypted text */
    decryptedtext[decryptedtext_len] = '\0';

    /* Print results */
    printf("Plaintext: %s\n", plaintext);
    printf("Encrypted text: ");
    for (int i = 0; i < ciphertext_len; i++){
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    printf("Decrypted text: %s\n", decryptedtext);

    /* Free cipher context */
    EVP_CIPHER_CTX_free(ctx);

    return 0;
}