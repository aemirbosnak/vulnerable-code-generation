//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/err.h>

#define KEY_LENGTH 32  // 256 bits
#define IV_LENGTH 16   // 128 bits

// Function to handle errors
void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

// Function to encrypt the plaintext using AES-256-CBC
int encrypt(const unsigned char *plaintext, int plaintext_len, 
            const unsigned char *key, const unsigned char *iv, 
            unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize the encryption operation
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1)
        handleErrors();

    // Provide the plaintext to be encrypted
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1)
        handleErrors();
    ciphertext_len = len;

    // Finalize the encryption
    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1)
        handleErrors();
    ciphertext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

// Function to decrypt the ciphertext using AES-256-CBC
int decrypt(const unsigned char *ciphertext, int ciphertext_len, 
            const unsigned char *key, const unsigned char *iv, 
            unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize the decryption operation
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1)
        handleErrors();

    // Provide the ciphertext to be decrypted
    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) != 1)
        handleErrors();
    plaintext_len = len;

    // Finalize the decryption
    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &len) != 1)
        handleErrors();
    plaintext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

// Function to generate a random key and IV
void generate_key_and_iv(unsigned char *key, unsigned char *iv) {
    if (!RAND_bytes(key, KEY_LENGTH)) {
        fprintf(stderr, "Error generating random key.\n");
        exit(EXIT_FAILURE);
    }
    
    if (!RAND_bytes(iv, IV_LENGTH)) {
        fprintf(stderr, "Error generating random IV.\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Sample plaintext
    unsigned char *plaintext = (unsigned char *)"This is a top secret message.";
    unsigned char key[KEY_LENGTH];
    unsigned char iv[IV_LENGTH];
    unsigned char ciphertext[128];
    unsigned char decryptedtext[128];

    // Generate a random key and IV
    generate_key_and_iv(key, iv);

    // Encrypt the plaintext
    int ciphertext_len = encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext);
    printf("Ciphertext is:\n");
    for (int i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    // Decrypt the ciphertext
    int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);
    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the decrypted string

    // Print the decrypted text
    printf("Decrypted text is:\n%s\n", decryptedtext);

    return 0;
}