//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/evp.h>

void handleErrors(void)
{
    fprintf(stderr, "An error occurred\n");
    abort();
}

int main(int argc, char *argv[])
{
    // Initialize OpenSSL library
    OpenSSL_add_all_algorithms();
    if (argc != 3) {
        fprintf(stderr, "Usage: %s message password\n", argv[0]);
        return 1;
    }
    char *message = argv[1];
    char *password = argv[2];
    const EVP_CIPHER *cipher = EVP_aes_256_cbc();
    
    // Generate random salt
    unsigned char salt[8];
    if (!RAND_bytes(salt, sizeof(salt)))
        handleErrors();
        
    // Generate encryption key and initialization vector from password and salt
    unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];
    if (!EVP_BytesToKey(cipher, EVP_md5(), salt, (unsigned char*)password, strlen(password), 1, key, iv))
        handleErrors();

    // Perform encryption
    EVP_CIPHER_CTX *ctx;
    ctx = EVP_CIPHER_CTX_new();
    int len;
    int ciphertext_len;
    unsigned char ciphertext[1024];
    if (EVP_EncryptInit_ex(ctx, cipher, NULL, key, iv) != 1)
        handleErrors();
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, (unsigned char*)message, strlen(message)) != 1)
        handleErrors();
    ciphertext_len = len;
    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1)
        handleErrors();
    ciphertext_len += len;
    EVP_CIPHER_CTX_free(ctx);

    // Print result
    printf("Salt: ");
    for (int i = 0; i < sizeof(salt); i++)
        printf("%02x", salt[i]);
    printf("\nCiphertext: ");
    for (int i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");
    
    // Perform decryption
    ctx = EVP_CIPHER_CTX_new();
    unsigned char plaintext[1024];
    if (EVP_DecryptInit_ex(ctx, cipher, NULL, key, iv) != 1)
        handleErrors();
    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) != 1)
        handleErrors();
    int plaintext_len = len;
    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &len) != 1)
        handleErrors();
    plaintext_len += len;
    EVP_CIPHER_CTX_free(ctx);
    
    // Print decrypted message
    printf("Decrypted message: %.*s\n", plaintext_len, plaintext);
    
    // Clean up
    EVP_cleanup();
    return 0;
}