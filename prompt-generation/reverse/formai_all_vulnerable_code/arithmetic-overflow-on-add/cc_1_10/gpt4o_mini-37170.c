//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define KEY_LENGTH 32 // AES-256
#define IV_LENGTH 16  // AES block size
#define BUFFER_SIZE 1024 // Buffer size for read/write

void handle_errors() {
    ERR_print_errors_fp(stderr);
    abort();
}

// Function to encrypt plaintext
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handle_errors();

    // Initialize the encryption operation
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handle_errors();

    // Provide the message to be encrypted, and obtain the ciphertext output
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1) handle_errors();
    ciphertext_len = len;

    // Finalize the encryption
    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) handle_errors();
    ciphertext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

// Function to decrypt ciphertext
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handle_errors();

    // Initialize the decryption operation
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handle_errors();

    // Provide the message to be decrypted, and obtain the plaintext output
    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) != 1) handle_errors();
    plaintext_len = len;

    // Finalize the decryption
    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &len) != 1) handle_errors();
    plaintext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

// Function to generate a random key and IV
void generate_key_iv(unsigned char *key, unsigned char *iv) {
    if (!RAND_bytes(key, KEY_LENGTH)) handle_errors();
    if (!RAND_bytes(iv, IV_LENGTH)) handle_errors();
}

// Main function
int main() {
    // Input plaintext, key, and IV
    unsigned char *plaintext = "This is a secret message!";
    unsigned char key[KEY_LENGTH];
    unsigned char iv[IV_LENGTH];

    // Buffers for ciphertext and decrypted text
    unsigned char ciphertext[BUFFER_SIZE];
    unsigned char decryptedtext[BUFFER_SIZE];

    // Display plaintext
    printf("Plaintext: %s\n", plaintext);

    // Generate random key and IV
    generate_key_iv(key, iv);

    // Encrypt the plaintext
    int ciphertext_len = encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext);
    ciphertext[ciphertext_len] = '\0'; // Null-terminate the ciphertext

    // Display the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    // Decrypt the ciphertext
    int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);
    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the decrypted text

    // Display the decrypted text
    printf("Decrypted Text: %s\n", decryptedtext);

    return 0;
}