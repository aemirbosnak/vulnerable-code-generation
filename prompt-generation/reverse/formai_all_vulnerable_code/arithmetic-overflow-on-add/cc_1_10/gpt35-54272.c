//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define KEY_SIZE 16

void handleErrors(void);

int main(int argc, char *argv[])
{
    unsigned char key[KEY_SIZE];
    unsigned char *iv = NULL;
    unsigned char *plaintext = "Hello, World!";
    int plaintext_len = strlen((char*)plaintext);

    // Initialize OpenSSL library
    OPENSSL_init_crypto(OPENSSL_INIT_LOAD_CONFIG, NULL);

    // Generate random IV
    iv = (unsigned char *)malloc(EVP_CIPHER_iv_length(EVP_aes_128_cbc()));
    RAND_bytes(iv, EVP_CIPHER_iv_length(EVP_aes_128_cbc()));

    // Generate random key
    if (!RAND_bytes(key, KEY_SIZE))
        handleErrors();

    // Create cipher context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx)
        handleErrors();

    // Initialize cipher context
    if (EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv) != 1)
        handleErrors();

    // Encrypt plaintext
    int ciphertext_len = plaintext_len + EVP_MAX_BLOCK_LENGTH;
    unsigned char *ciphertext = (unsigned char *)malloc(ciphertext_len);
    int len;
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1)
        handleErrors();
    ciphertext_len = len;
    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1)
        handleErrors();
    ciphertext_len += len;

    // Print encrypted message and IV
    printf("Encrypted message:\n");
    int i;
    for (i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);
    printf("\n\nIV:\n");
    for (i = 0; i < EVP_CIPHER_iv_length(EVP_aes_128_cbc()); i++)
        printf("%02x", iv[i]);
    printf("\n");

    // Decrypt ciphertext
    unsigned char *decryptedtext = (unsigned char *)malloc(ciphertext_len);
    if (EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv) != 1)
        handleErrors();
    if (EVP_DecryptUpdate(ctx, decryptedtext, &len, ciphertext, ciphertext_len) != 1)
        handleErrors();
    int decryptedtext_len = len;
    if (EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len) != 1)
        handleErrors();
    decryptedtext_len += len;

    // Print decrypted message
    printf("\nDecrypted message: %s\n", decryptedtext);

    // Clean up
    free(iv);
    free(ciphertext);
    free(decryptedtext);
    EVP_CIPHER_CTX_free(ctx);
    return 0;
}

void handleErrors(void)
{
    printf("Error occurred\n");
    exit(EXIT_FAILURE);
}