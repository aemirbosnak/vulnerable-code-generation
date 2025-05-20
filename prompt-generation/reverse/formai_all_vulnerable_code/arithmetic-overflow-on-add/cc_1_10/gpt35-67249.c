//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void handleErrors(void)
{
    printf("Error occurred.\n");
    exit(EXIT_FAILURE);
}

int main(void)
{
    // Variables to hold messages and keys
    unsigned char message[] = "Hello, world!";
    unsigned char key[] = "mykey";
    
    // Variables for encryption and decryption
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;
    unsigned char *ciphertext;
    unsigned char *plaintext;
    
    // Initialize the library
    EVP_CIPHER_CTX_init(ctx);
    
    // Initialize the encryption operation.
    if (!EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL))
        handleErrors();
    
    // Allocate memory for the ciphertext and plaintext
    ciphertext = malloc(strlen((char *)message) + EVP_CIPHER_block_size(EVP_aes_256_cbc()));
    plaintext = malloc(strlen((char *)message) + EVP_CIPHER_block_size(EVP_aes_256_cbc()));
    
    // Encrypt the message
    if (!EVP_EncryptUpdate(ctx, ciphertext, &len, message, strlen((char *)message)))
        handleErrors();
    ciphertext_len = len;
    
    // Finalize the encryption
    if (!EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        handleErrors();
    
    ciphertext_len += len;
    
    // Print the ciphertext
    printf("Ciphertext is: ");
    for (int i = 0; i < ciphertext_len; i++)
    {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    
    // Initialize the decryption operation.
    if (!EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL))
        handleErrors();
    
    // Decrypt the message
    if (!EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();
    int plaintext_len = len;
    
    // Finalize the decryption
    if (!EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
        handleErrors();
    
    plaintext_len += len;
    plaintext[plaintext_len] = '\0';
    
    // Print the plaintext
    printf("Decrypted message: %s\n", plaintext);
    
    // Clean up
    free(ciphertext);
    free(plaintext);
    EVP_CIPHER_CTX_free(ctx);
    
    return 0;
}