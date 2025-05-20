//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: happy
// Let's play with crypto, it's gonna be fun!

#include <stdio.h>
#include <stdlib.h>
#include <openssl/evp.h>

// Our secret key, keep it secret, keep it safe!
static const unsigned char key[] = "SuperSecretPassword123!";

// Encrypt a message using AES-256-CBC
char *encrypt_aes_cbc(const char *plaintext) {
    // Initialize OpenSSL context and cipher
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        fprintf(stderr, "Error creating OpenSSL context\n");
        return NULL;
    }
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL) != 1) {
        fprintf(stderr, "Error initializing encryption\n");
        EVP_CIPHER_CTX_free(ctx);
        return NULL;
    }

    // Calculate padded plaintext length
    int plaintext_len = strlen(plaintext);
    int padded_len = plaintext_len + (EVP_CIPHER_CTX_block_size(ctx) - (plaintext_len % EVP_CIPHER_CTX_block_size(ctx)));

    // Allocate memory for encrypted text
    char *ciphertext = malloc(padded_len + 1);
    if (!ciphertext) {
        fprintf(stderr, "Error allocating memory for ciphertext\n");
        EVP_CIPHER_CTX_free(ctx);
        return NULL;
    }

    // Encrypt the plaintext
    int ciphertext_len;
    if (EVP_EncryptUpdate(ctx, (unsigned char *)ciphertext, &ciphertext_len, (unsigned char *)plaintext, plaintext_len) != 1) {
        fprintf(stderr, "Error encrypting plaintext\n");
        EVP_CIPHER_CTX_free(ctx);
        free(ciphertext);
        return NULL;
    }
    if (EVP_EncryptFinal_ex(ctx, (unsigned char *)ciphertext + ciphertext_len, &ciphertext_len) != 1) {
        fprintf(stderr, "Error finalizing encryption\n");
        EVP_CIPHER_CTX_free(ctx);
        free(ciphertext);
        return NULL;
    }

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    // Null-terminate the ciphertext
    ciphertext[padded_len] = '\0';

    return ciphertext;
}

// Decrypt a message using AES-256-CBC
char *decrypt_aes_cbc(const char *ciphertext) {
    // Initialize OpenSSL context and cipher
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        fprintf(stderr, "Error creating OpenSSL context\n");
        return NULL;
    }
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL) != 1) {
        fprintf(stderr, "Error initializing decryption\n");
        EVP_CIPHER_CTX_free(ctx);
        return NULL;
    }

    // Calculate padded ciphertext length
    int ciphertext_len = strlen(ciphertext);
    int padded_len = ciphertext_len + (EVP_CIPHER_CTX_block_size(ctx) - (ciphertext_len % EVP_CIPHER_CTX_block_size(ctx)));

    // Allocate memory for decrypted text
    char *plaintext = malloc(padded_len + 1);
    if (!plaintext) {
        fprintf(stderr, "Error allocating memory for plaintext\n");
        EVP_CIPHER_CTX_free(ctx);
        return NULL;
    }

    // Decrypt the ciphertext
    int plaintext_len;
    if (EVP_DecryptUpdate(ctx, (unsigned char *)plaintext, &plaintext_len, (unsigned char *)ciphertext, ciphertext_len) != 1) {
        fprintf(stderr, "Error decrypting ciphertext\n");
        EVP_CIPHER_CTX_free(ctx);
        free(plaintext);
        return NULL;
    }
    if (EVP_DecryptFinal_ex(ctx, (unsigned char *)plaintext + plaintext_len, &plaintext_len) != 1) {
        fprintf(stderr, "Error finalizing decryption\n");
        EVP_CIPHER_CTX_free(ctx);
        free(plaintext);
        return NULL;
    }

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    // Null-terminate the plaintext
    plaintext[plaintext_len] = '\0';

    return plaintext;
}

// Let's dance with some cryptography!
int main() {
    // Our secret message, let's keep it confidential!
    const char *plaintext = "Top secret message, don't tell anyone!";

    // Encrypt the message using AES-256-CBC
    char *ciphertext = encrypt_aes_cbc(plaintext);
    if (!ciphertext) {
        fprintf(stderr, "Error encrypting message\n");
        return EXIT_FAILURE;
    }

    // Show the encrypted ciphertext, looks like gibberish now!
    printf("Encrypted ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using AES-256-CBC
    char *decrypted_plaintext = decrypt_aes_cbc(ciphertext);
    if (!decrypted_plaintext) {
        fprintf(stderr, "Error decrypting message\n");
        free(ciphertext);
        return EXIT_FAILURE;
    }

    // Reveal the decrypted plaintext, our secret is safe!
    printf("Decrypted plaintext: %s\n", decrypted_plaintext);

    // Clean up
    free(ciphertext);
    free(decrypted_plaintext);

    return EXIT_SUCCESS;
}