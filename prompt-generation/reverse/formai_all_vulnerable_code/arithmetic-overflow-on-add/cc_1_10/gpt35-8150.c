//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// AES Encryption function
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
            unsigned char *iv, unsigned char *ciphertext) {
    int len;

    // Create and initialize the context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // Encrypt the plaintext
    EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len);

    // Finalize the encryption
    int ciphertext_len = len;
    EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);
    ciphertext_len += len;

    // Clean up the context
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

// AES Decryption function
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
            unsigned char *iv, unsigned char *plaintext) {
    int len;

    // Create and initialize the context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // Decrypt the ciphertext
    EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len);

    // Finalize the decryption
    int plaintext_len = len;
    EVP_DecryptFinal_ex(ctx, plaintext + len, &len);
    plaintext_len += len;

    // Clean up the context
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

int main(int argc, char **argv) {
    // Set the key and IV
    unsigned char *key = (unsigned char *)"01234567890123456789012345678901";
    unsigned char *iv = (unsigned char *)"0123456789012345";

    // Define plaintext
    unsigned char *plaintext = (unsigned char *)"Hello, World!";
    int plaintext_len = strlen((char *)plaintext);

    // Allocate memory for the ciphertext
    int ciphertext_len = plaintext_len + EVP_CIPHER_block_size(EVP_aes_256_cbc());
    unsigned char *ciphertext = malloc(ciphertext_len);

    // Encrypt the plaintext
    int len = encrypt(plaintext, plaintext_len, key, iv, ciphertext);

    // Print the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Allocate memory for the decrypted text
    unsigned char *decryptedtext = malloc(len);

    // Decrypt the ciphertext
    int decryptedtext_len = decrypt(ciphertext, len, key, iv, decryptedtext);

    // Print the decrypted text
    printf("Decrypted text: %s\n", decryptedtext);

    // Clean up memory
    free(ciphertext);
    free(decryptedtext);

    return 0;
}