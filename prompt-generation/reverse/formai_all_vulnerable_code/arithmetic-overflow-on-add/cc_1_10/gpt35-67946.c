//FormAI DATASET v1.0 Category: Encryption ; Style: portable
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

void handleErrors(void)
{
    printf("An error occurred\n");
    exit(1);    
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
  unsigned char *iv, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    // Create and initialise the context
    if(!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    // Initialise the encryption operation with 256bit AES key in CBC mode
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    // Encrypt the plaintext
    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
    ciphertext_len = len;

    // Finalise the encryption
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        handleErrors();
    ciphertext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

int main(void)
{
    // Initialize encryption variables
    unsigned char *key = "01234567890123456789012345678901";
    unsigned char *iv = "01234567890123456"; // 16 bytes for AES-128, 32 for AES-256
    unsigned char plaintext[] = "This is a test.";
    int plaintext_len = strlen(plaintext);
    unsigned char ciphertext[128];
    int ciphertext_len;

    // Encrypt the plaintext
    ciphertext_len = encrypt(plaintext, plaintext_len, key, iv, ciphertext);

    // Print the plaintext and ciphertext
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for(int i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    return 0;
}