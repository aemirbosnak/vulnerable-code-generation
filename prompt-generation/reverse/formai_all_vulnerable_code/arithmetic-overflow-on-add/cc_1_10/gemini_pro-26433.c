//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: safe
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Generate a random 256-bit key
    unsigned char key[32];
    RAND_bytes(key, sizeof(key));

    // Create a new cipher context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        perror("EVP_CIPHER_CTX_new");
        return EXIT_FAILURE;
    }

    // Initialize the cipher context for encryption
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL) != 1) {
        perror("EVP_EncryptInit_ex");
        EVP_CIPHER_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Get the block size of the cipher
    int block_size = EVP_CIPHER_CTX_block_size(ctx);

    // Create a buffer for the plaintext and ciphertext
    unsigned char plaintext[1024];
    unsigned char ciphertext[1024 + block_size];
    int plaintext_len = 0;

    // Read the plaintext from the user
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext_len = strlen(plaintext);

    // Pad the plaintext to the block size
    int padding_len = block_size - (plaintext_len % block_size);
    memset(plaintext + plaintext_len, padding_len, padding_len);
    plaintext_len += padding_len;

    // Encrypt the plaintext
    int ciphertext_len = 0;
    if (EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, plaintext_len) != 1) {
        perror("EVP_EncryptUpdate");
        EVP_CIPHER_CTX_free(ctx);
        return EXIT_FAILURE;
    }
    if (EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len) != 1) {
        perror("EVP_EncryptFinal_ex");
        EVP_CIPHER_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Print the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02X", ciphertext[i]);
    }
    printf("\n");

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return EXIT_SUCCESS;
}