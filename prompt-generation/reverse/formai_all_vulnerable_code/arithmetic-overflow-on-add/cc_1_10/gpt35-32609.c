//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rand.h>
#include <openssl/evp.h>

void handleErrors(void)
{
    printf("An error occurred.\n");
    exit(1);
}

int main(void)
{
    // Initialization
    OpenSSL_add_all_algorithms();
    RAND_load_file("/dev/urandom", 1024);

    // Generating a random key and IV
    unsigned char key[EVP_MAX_KEY_LENGTH];
    unsigned char iv[EVP_MAX_IV_LENGTH];
    if (!RAND_bytes(key, 32) || !RAND_bytes(iv, 16))
        handleErrors();

    // Setting up the encryption context
    EVP_CIPHER_CTX *ctx;
    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    // Reading in the plaintext
    char *plaintext = "Hello, world!";
    int plaintext_len = strlen(plaintext);
    int ciphertext_len = plaintext_len + EVP_MAX_BLOCK_LENGTH;
    unsigned char ciphertext[ciphertext_len];

    // Encrypting the data
    int len;
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len,
                               plaintext, plaintext_len))
        handleErrors();
    ciphertext_len = len;
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        handleErrors();
    ciphertext_len += len;

    // Printing the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    // Setting up the decryption context
    if (!EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    // Decrypting the data
    unsigned char decryptedtext[plaintext_len];
    if (!EVP_DecryptUpdate(ctx, decryptedtext, &len, ciphertext, ciphertext_len))
        handleErrors();
    int decryptedtext_len = len;
    if (!EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len))
        handleErrors();
    decryptedtext_len += len;

    // Null-terminating the decrypted data and printing it
    decryptedtext[decryptedtext_len] = '\0';
    printf("Decrypted text: %s\n", decryptedtext);

    // Cleaning up
    EVP_CIPHER_CTX_free(ctx);
    return 0;
}