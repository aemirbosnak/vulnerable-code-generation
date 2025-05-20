//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void handleErrors(void)
{
    printf("An error occurred.\n");
    exit(1);
}

int main(void)
{
    char message[1024], key[32], iv[32];
    EVP_CIPHER_CTX *ctx;
    int len, ciphertext_len;

    // Get message input
    printf("Enter message: ");
    fgets(message, sizeof message, stdin);

    // Get encryption key
    printf("Enter encryption key: ");
    fgets(key, sizeof key, stdin);

    // Get initial vector (IV)
    printf("Enter initial vector: ");
    fgets(iv, sizeof iv, stdin);

    // Remove newline characters from inputs
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;
    iv[strcspn(iv, "\n")] = 0;

    // Initialize cipher context
    if(!(ctx = EVP_CIPHER_CTX_new())) 
        handleErrors();

    // Set cipher type, key and IV
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char*)key, (unsigned char*)iv))
        handleErrors();

    // Encrypt message
    if(1 != EVP_EncryptUpdate(ctx, (unsigned char*)message, &len, (unsigned char*)message, strlen(message)))
        handleErrors();
    ciphertext_len = len;

    // Finalize encryption
    if(1 != EVP_EncryptFinal_ex(ctx, (unsigned char*)message + len, &len))
        handleErrors();
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    // Print ciphertext
    printf("Encrypted message: %s\n", message);
    printf("Encrypted message length: %d\n", ciphertext_len);

    return 0;
}