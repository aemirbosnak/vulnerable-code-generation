//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main()
{
    char key[] = "thisisaverysecurekey";
    char input[] = "The quick brown fox jumps over the lazy dog.";
    char ciphertext[128], decryptedtext[128];

    // Initialize OpenSSL
    OpenSSL_add_all_algorithms();
    OpenSSL_add_all_ciphers();

    // Create an encryption context using the AES-256-CBC algorithm
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char *)key, NULL);

    // Encrypt the input data
    int len;
    EVP_EncryptUpdate(ctx, (unsigned char *)ciphertext, &len, (unsigned char *)input, strlen(input));
    int ciphertext_len = len;

    EVP_EncryptFinal_ex(ctx, (unsigned char *)ciphertext + len, &len);
    ciphertext_len += len;

    // Print the encrypted data in hexadecimal format
    printf("Ciphertext in hexadecimal:");
    for(int i=0; i<ciphertext_len; i++) {
        printf(" %02x", ciphertext[i]);
    }
    printf("\n");

    // Create a decryption context using the same algorithm and key
    EVP_CIPHER_CTX *d_ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(d_ctx, EVP_aes_256_cbc(), NULL, (unsigned char *)key, NULL);

    // Decrypt the ciphertext
    EVP_DecryptUpdate(d_ctx, (unsigned char *)decryptedtext, &len, (unsigned char *)ciphertext, ciphertext_len);
    int decryptedtext_len = len;
    EVP_DecryptFinal_ex(d_ctx, (unsigned char *)decryptedtext + len, &len);
    decryptedtext_len += len;

    // Print the decrypted text
    printf("Decrypted text: %s\n", decryptedtext);

    // Clean up the contexts
    EVP_CIPHER_CTX_free(ctx);
    EVP_CIPHER_CTX_free(d_ctx);

    return 0;
}