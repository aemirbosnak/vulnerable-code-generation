//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define BLOCK_SIZE 16 // Block size for AES is 16 bytes

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

// Function to encrypt plain text using AES algorithm
int encrypt_AES(const uint8_t *plaintext, int plaintext_len, const uint8_t *key,
                const uint8_t *iv, uint8_t *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize the encryption operation with AES-256-CBC
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    // Provide the message to be encrypted, and obtain the ciphertext
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
    ciphertext_len = len;

    // Finalize the encryption. Further ciphertext bytes may be written
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    ciphertext_len += len;

    // Clean up the context
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

// Function to decrypt a ciphertext using AES algorithm
int decrypt_AES(const uint8_t *ciphertext, int ciphertext_len, const uint8_t *key,
                const uint8_t *iv, uint8_t *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize the decryption operation with AES-256-CBC
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    // Provide the message to be decrypted, and obtain the plaintext
    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();
    plaintext_len = len;

    // Finalize the decryption. Further plaintext bytes may be written
    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();
    plaintext_len += len;

    // Clean up the context
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

// Function to generate a random key and IV
void generate_key_iv(uint8_t *key, uint8_t *iv) {
    if (!RAND_bytes(key, BLOCK_SIZE) || !RAND_bytes(iv, BLOCK_SIZE)) {
        fprintf(stderr, "Error generating random bytes\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    uint8_t key[BLOCK_SIZE]; // Key for encryption
    uint8_t iv[BLOCK_SIZE];  // Initialization vector
    const char *original_text = "Greetings from the land of code!";
    int original_length = strlen(original_text);
    uint8_t ciphertext[128]; // Buffer for ciphertext
    uint8_t decryptedtext[128]; // Buffer for decrypted text
    int decrypted_length;

    // Generate a random key and IV
    generate_key_iv(key, iv);

    // Encrypt the original text
    int ciphertext_length = encrypt_AES((uint8_t *)original_text, original_length, key, iv, ciphertext);
    printf("Ciphertext length: %d\n", ciphertext_length);

    // Decrypt the ciphertext
    decrypted_length = decrypt_AES(ciphertext, ciphertext_length, key, iv, decryptedtext);
    decryptedtext[decrypted_length] = '\0'; // Null-terminate the decrypted text

    // Output the results
    printf("Original: %s\n", original_text);
    printf("Decrypted: %s\n", decryptedtext);

    // Example of displaying the hexadecimal representation of the ciphertext
    printf("Ciphertext (hex): ");
    for (int i = 0; i < ciphertext_length; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    return 0;
}