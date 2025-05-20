//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_KEY_LENGTH 256 // AES key length in bits
#define AES_BLOCK_SIZE 16   // AES block size in bytes
#define BUFFER_SIZE 128

void handleErrors() {
    fprintf(stderr, "An error occurred\n");
    exit(EXIT_FAILURE);
}

// Function to encrypt plaintext using AES
void aes_encrypt(unsigned char *plaintext, unsigned char *key, unsigned char *ciphertext) {
    AES_KEY encryptKey;
    if (AES_set_encrypt_key(key, AES_KEY_LENGTH, &encryptKey) < 0) {
        handleErrors();
    }
    AES_encrypt(plaintext, ciphertext, &encryptKey);
}

// Function to decrypt ciphertext using AES
void aes_decrypt(unsigned char *ciphertext, unsigned char *key, unsigned char *plaintext) {
    AES_KEY decryptKey;
    if (AES_set_decrypt_key(key, AES_KEY_LENGTH, &decryptKey) < 0) {
        handleErrors();
    }
    AES_decrypt(ciphertext, plaintext, &decryptKey);
}

// Function to generate a random AES key
void generate_random_key(unsigned char *key) {
    if (RAND_bytes(key, AES_KEY_LENGTH / 8) != 1) {
        handleErrors();
    }
}

// Function for padding the plaintext
void pad_plaintext(unsigned char *input, unsigned char *output) {
    size_t len = strlen((char *)input);
    size_t padding_len = AES_BLOCK_SIZE - (len % AES_BLOCK_SIZE);
    for (size_t i = 0; i < padding_len; i++) {
        output[len + i] = (unsigned char) padding_len; // Add padding bytes
    }
    memcpy(output, input, len);
}

// Main function demonstrating encryption and decryption
int main() {
    unsigned char key[AES_KEY_LENGTH / 8];       // Buffer for AES key
    unsigned char plaintext[BUFFER_SIZE];          // Buffer for plaintext
    unsigned char ciphertext[AES_BLOCK_SIZE];      // Buffer for ciphertext
    unsigned char decryptedtext[AES_BLOCK_SIZE];   // Buffer for decrypted text
    unsigned char paddedtext[BUFFER_SIZE + AES_BLOCK_SIZE]; // Buffer for padded plaintext

    // Prompt user for input
    printf("Enter plaintext (up to 112 characters): ");
    fgets((char *)plaintext, BUFFER_SIZE, stdin);
    plaintext[strcspn((char *)plaintext, "\n")] = '\0'; // Remove newline character

    // Generate a random key
    generate_random_key(key);

    // Pad the plaintext
    pad_plaintext(plaintext, paddedtext);

    // Encrypt the padded plaintext
    aes_encrypt(paddedtext, key, ciphertext);

    // Decrypt the ciphertext
    aes_decrypt(ciphertext, key, decryptedtext);

    // Output results
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext (hex): ");
    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        printf("%02x ", ciphertext[i]);
    }
    printf("\n");

    // Output decrypted text (remove padding)
    size_t padding_len = decryptedtext[AES_BLOCK_SIZE - 1];
    decryptedtext[AES_BLOCK_SIZE - padding_len] = '\0'; // null-terminate the string
    printf("Decrypted text: %s\n", decryptedtext);

    return EXIT_SUCCESS;
}