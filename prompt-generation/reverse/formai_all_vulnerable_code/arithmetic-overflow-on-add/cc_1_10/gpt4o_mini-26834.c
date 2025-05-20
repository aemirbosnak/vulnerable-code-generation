//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

// Function to handle encryption
void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

// AES encryption function
int aes_encrypt(const unsigned char *plaintext, int plaintext_len, const unsigned char *key, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;

    int len;
    int ciphertext_len;

    // Creating and initializing the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize the encryption operation: AES-256-CBC
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL) != 1) handleErrors();

    // Provide the message to be encrypted
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1) handleErrors();
    ciphertext_len = len;

    // Finalize the encryption
    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) handleErrors();
    ciphertext_len += len;

    // Clean up the context
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

// AES decryption function
int aes_decrypt(const unsigned char *ciphertext, int ciphertext_len, const unsigned char *key, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;

    int len;
    int plaintext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize the decryption operation: AES-256-CBC
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL) != 1) handleErrors();

    // Provide the message to be decrypted
    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) != 1) handleErrors();
    plaintext_len = len;

    // Finalize the decryption
    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &len) != 1) handleErrors();
    plaintext_len += len;

    // Clean up the context
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

int main() {
    // The secret key - It's a secret! Shhh!
    unsigned char key[32]; // 256 bit key
    if (!RAND_bytes(key, sizeof(key))) handleErrors();

    // A sample plaintext message
    unsigned char *plaintext = (unsigned char *)"Hello, World! This is a secret message.";
    unsigned char ciphertext[128]; // Buffer for the ciphertext
    unsigned char decryptedtext[128]; // Buffer for the decrypted text

    int decryptedtext_len, ciphertext_len;

    // Encrypt the plaintext
    ciphertext_len = aes_encrypt(plaintext, strlen((char *)plaintext), key, ciphertext);
    printf("Ciphertext is:\n");
    for (int i = 0; i < ciphertext_len; i++)
        printf("%02x ", ciphertext[i]);
    printf("\n");

    // Decrypt the ciphertext
    decryptedtext_len = aes_decrypt(ciphertext, ciphertext_len, key, decryptedtext);
    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the string

    // Show the decrypted text
    printf("Decrypted text is:\n%s\n", decryptedtext);

    return 0;
}