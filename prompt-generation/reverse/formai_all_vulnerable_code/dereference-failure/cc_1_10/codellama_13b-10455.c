//Code Llama-13B DATASET v1.0 Category: Modern Encryption ; Style: single-threaded
/*
 * Modern Encryption Example Program
 *
 * Usage: ./modern_encryption <plaintext> <key>
 *
 * Example: ./modern_encryption "Hello, World!" "secret"
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_BLOCK_SIZE 16
#define AES_KEY_SIZE 32

void handle_errors(const char *file, int line, const char *msg)
{
    fprintf(stderr, "%s:%d: %s\n", file, line, msg);
    exit(EXIT_FAILURE);
}

void encrypt(const unsigned char *plaintext, int plaintext_len,
             const unsigned char *key, unsigned char *ciphertext)
{
    AES_KEY aes_key;
    AES_set_encrypt_key(key, AES_KEY_SIZE * 8, &aes_key);

    AES_encrypt(plaintext, ciphertext, &aes_key);
}

void decrypt(const unsigned char *ciphertext, int ciphertext_len,
             const unsigned char *key, unsigned char *plaintext)
{
    AES_KEY aes_key;
    AES_set_decrypt_key(key, AES_KEY_SIZE * 8, &aes_key);

    AES_decrypt(ciphertext, plaintext, &aes_key);
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <plaintext> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *plaintext = argv[1];
    int plaintext_len = strlen(plaintext);

    char *key = argv[2];
    int key_len = strlen(key);

    if (plaintext_len % AES_BLOCK_SIZE != 0) {
        fprintf(stderr, "Plaintext length must be a multiple of %d\n", AES_BLOCK_SIZE);
        return EXIT_FAILURE;
    }

    if (key_len != AES_KEY_SIZE) {
        fprintf(stderr, "Key length must be %d bytes\n", AES_KEY_SIZE);
        return EXIT_FAILURE;
    }

    unsigned char *ciphertext = (unsigned char *) malloc(plaintext_len);
    encrypt(plaintext, plaintext_len, key, ciphertext);

    unsigned char *plaintext_dec = (unsigned char *) malloc(plaintext_len);
    decrypt(ciphertext, plaintext_len, key, plaintext_dec);

    printf("Ciphertext: ");
    for (int i = 0; i < plaintext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    printf("Decrypted text: %s\n", plaintext_dec);

    free(ciphertext);
    free(plaintext_dec);

    return EXIT_SUCCESS;
}