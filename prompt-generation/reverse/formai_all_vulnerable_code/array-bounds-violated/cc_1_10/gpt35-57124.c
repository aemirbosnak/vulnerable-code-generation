//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/crypto.h>
#include <openssl/rand.h>
#include <openssl/evp.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    unsigned char buffer[MAX_BUFFER_SIZE];
    unsigned char ciphertext[MAX_BUFFER_SIZE];
    unsigned char decrypted_buffer[MAX_BUFFER_SIZE + EVP_MAX_BLOCK_LENGTH];
    unsigned char iv[EVP_MAX_IV_LENGTH];
    unsigned char key[EVP_MAX_KEY_LENGTH];
    int buffer_length, ciphertext_length, decrypted_length;
    EVP_CIPHER_CTX *ctx;

    OpenSSL_add_all_algorithms();
    RAND_bytes(iv, EVP_MAX_IV_LENGTH);
    RAND_bytes(key, EVP_MAX_KEY_LENGTH);

    ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        perror("Failed to create new cipher context.");
        return EXIT_FAILURE;
    }

    if (!EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        perror("Failed to initialize encryption.");
        return EXIT_FAILURE;
    }

    printf("Enter the string to encrypt: ");
    fgets(buffer, MAX_BUFFER_SIZE, stdin);
    buffer_length = strlen(buffer) - 1;
    buffer[buffer_length] = '\0';

    if (!EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_length, buffer, buffer_length)) {
        perror("Failed to encrypt.");
        return EXIT_FAILURE;
    }

    if (!EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_length, &ciphertext_length)) {
        perror("Failed to finalize encryption.");
        return EXIT_FAILURE;
    }

    EVP_CIPHER_CTX_reset(ctx);

    if (!EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        perror("Failed to initialize decryption.");
        return EXIT_FAILURE;
    }

    if (!EVP_DecryptUpdate(ctx, decrypted_buffer, &decrypted_length, ciphertext, ciphertext_length)) {
        perror("Failed to decrypt.");
        return EXIT_FAILURE;
    }

    if (!EVP_DecryptFinal_ex(ctx, decrypted_buffer + decrypted_length, &decrypted_length)) {
        printf("Failed to finalize decryption. Error code: %d\n", ERR_get_error());
        return EXIT_FAILURE;
    }

    EVP_CIPHER_CTX_free(ctx);

    printf("\nOriginal string: %s\n", buffer);
    printf("Encrypted message: %s\n", ciphertext);
    printf("Decrypted message: %s\n", decrypted_buffer);

    return EXIT_SUCCESS;
}