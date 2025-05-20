//Code Llama-13B DATASET v1.0 Category: Encryption ; Style: protected
/*
 * C Encryption Example Program
 *
 * This program uses the Advanced Encryption Standard (AES) algorithm to encrypt and decrypt messages.
 * The program uses a 128-bit key and a 128-bit IV.
 *
 * Compile with: gcc -o aes_example aes_example.c -lcrypto
 *
 * Usage: ./aes_example [encrypt|decrypt] [key] [iv] [message]
 *
 * Example: ./aes_example encrypt 0123456789abcdef 0123456789abcdef "Hello, World!"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

int main(int argc, char *argv[]) {
    // Check number of arguments
    if (argc != 5) {
        fprintf(stderr, "Usage: %s [encrypt|decrypt] [key] [iv] [message]\n", argv[0]);
        return 1;
    }

    // Check if encryption or decryption is requested
    if (strcmp(argv[1], "encrypt") != 0 && strcmp(argv[1], "decrypt") != 0) {
        fprintf(stderr, "Invalid operation: %s\n", argv[1]);
        return 1;
    }

    // Check if key and iv are valid
    if (strlen(argv[2]) != 16 || strlen(argv[3]) != 16) {
        fprintf(stderr, "Invalid key or iv: %s\n", argv[2]);
        return 1;
    }

    // Convert key and iv to binary
    unsigned char key[16], iv[16];
    memset(key, 0, 16);
    memset(iv, 0, 16);
    for (int i = 0; i < 16; i++) {
        key[i] = (unsigned char) strtol(argv[2] + 2 * i, NULL, 16);
        iv[i] = (unsigned char) strtol(argv[3] + 2 * i, NULL, 16);
    }

    // Initialize the AES context
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);

    // Create the ciphertext
    unsigned char ciphertext[16];
    if (strcmp(argv[1], "encrypt") == 0) {
        AES_encrypt(argv[4], ciphertext, &aes_key);
    } else {
        AES_decrypt(argv[4], ciphertext, &aes_key);
    }

    // Print the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    return 0;
}