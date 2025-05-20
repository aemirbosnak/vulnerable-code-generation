//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void handleErrors(void)
{
    printf("Error in encryption!\n");
    exit(1);
}

int main(void)
{
    printf("Welcome to my C cryptography implementation!\n\n");

    /* Set up the key and IV */
    unsigned char key[] = "secretpassword";
    unsigned char iv[] = "initialvector";

    /* Set up the plaintext and ciphertext */
    unsigned char plaintext[] = "This is a top secret message.";
    int plaintext_len = strlen(plaintext);
    unsigned char ciphertext[128];
    int ciphertext_len;

    /* Initialize the encryption context */
    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();

    /* Set the cipher type, key, and IV */
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv))
        handleErrors();

    /* Encrypt the plaintext */
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, plaintext_len))
        handleErrors();

    /* Finalize the encryption */
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len))
        handleErrors();

    /* Print out the ciphertext in hex format */
    printf("Encrypted message: ");
    for (int i = 0; i < ciphertext_len + plaintext_len; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    /* Clean up the context */
    EVP_CIPHER_CTX_free(ctx);

    printf("\nEncryption complete. Thanks for trying my program!\n");

    return 0;
}