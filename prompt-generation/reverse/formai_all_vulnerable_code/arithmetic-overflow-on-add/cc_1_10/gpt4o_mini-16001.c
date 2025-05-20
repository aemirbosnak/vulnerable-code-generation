//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: random
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define AES_KEY_LENGTH 256 // AES key length in bits
#define AES_BLOCK_SIZE 16   // AES block size in bytes
#define MAX_INPUT_SIZE 1024 // Maximum input size for the text

// Function declarations
void handleErrors(void);
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext);
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext);
void generate_key_and_iv(unsigned char *key, unsigned char *iv);
void print_hex(unsigned char *data, int len);

int main() {
    unsigned char key[AES_KEY_LENGTH / 8]; // Key for AES
    unsigned char iv[AES_BLOCK_SIZE];       // Initialization vector
    unsigned char plaintext[MAX_INPUT_SIZE]; // Input text to encrypt
    unsigned char ciphertext[MAX_INPUT_SIZE + AES_BLOCK_SIZE]; // To hold the ciphertext
    unsigned char decryptedtext[MAX_INPUT_SIZE + AES_BLOCK_SIZE]; // To hold the decrypted text
    int decryptedtext_len, ciphertext_len;

    // Generate random key and initialization vector
    generate_key_and_iv(key, iv);

    // Get plaintext input from the user
    printf("Enter text to encrypt (up to %d characters):\n", MAX_INPUT_SIZE);
    fgets((char *)plaintext, MAX_INPUT_SIZE, stdin);
    plaintext[strcspn((char *)plaintext, "\n")] = 0; // Remove newline character

    // Encrypt the plaintext
    ciphertext_len = encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext);
    printf("Ciphertext is:\n");
    print_hex(ciphertext, ciphertext_len);

    // Decrypt the ciphertext
    decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);
    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the decrypted string
    printf("Decrypted text is: %s\n", decryptedtext);

    return 0;
}

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize the encryption operation
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handleErrors();

    // Provide the plaintext to be encrypted, and obtain the ciphertext
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1) handleErrors();
    ciphertext_len = len;

    // Finalize the encryption
    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) handleErrors();
    ciphertext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize the decryption operation
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handleErrors();

    // Provide the ciphertext to be decrypted, and obtain the plaintext
    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) != 1) handleErrors();
    plaintext_len = len;

    // Finalize the decryption
    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &len) != 1) handleErrors();
    plaintext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    return plaintext_len;
}

void generate_key_and_iv(unsigned char *key, unsigned char *iv) {
    // Generate random key
    if (!RAND_bytes(key, AES_KEY_LENGTH / 8)) handleErrors();
    // Generate random IV
    if (!RAND_bytes(iv, AES_BLOCK_SIZE)) handleErrors();
}

void print_hex(unsigned char *data, int len) {
    for (int i = 0; i < len; i++) {
        printf("%02x ", data[i]);
    }
    printf("\n");
}