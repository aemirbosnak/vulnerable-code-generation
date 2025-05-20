//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: grateful
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <stdio.h>
#include <stdlib.h>

// OpenSSL provides various encryption algorithms, each with its key length and modes of operation. Let's explore an example using AES-256 in CBC mode.

int main() {
    // First, we generate a random key for our encryption.
    unsigned char key[32];
    RAND_bytes(key, sizeof(key));

    // Next, we create an OpenSSL context for our encryption operation.
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        fprintf(stderr, "Failed to create EVP context.\n");
        return EXIT_FAILURE;
    }

    // Now, we initialize the context for encryption using AES-256 in CBC mode.
    // EVP_aes_256_cbc points to the specific OpenSSL implementation we want to use, 
    // which takes a key, initialization vector, and other parameters.
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL) != 1) {
        fprintf(stderr, "Failed to initialize encryption context.\n");
        EVP_CIPHER_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Let's encrypt some plaintext now!
    const char *plaintext = "This is the secret message we want to encrypt.";
    // We allocate sufficient memory for the ciphertext, as the ciphertext can be larger than the plaintext.
    size_t ciphertext_len = EVP_CIPHER_CTX_block_size(ctx) * ((strlen(plaintext) + EVP_CIPHER_CTX_block_size(ctx) - 1) / EVP_CIPHER_CTX_block_size(ctx));
    unsigned char ciphertext[ciphertext_len];

    int ciphertext_out_len;
    // Finally, we perform the encryption operation by passing in our plaintext, ciphertext buffer, and the length of the plaintext.
    // The length of the ciphertext will be stored in ciphertext_out_len.
    if (EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_out_len, (unsigned char *)plaintext, strlen(plaintext)) != 1) {
        fprintf(stderr, "Failed to encrypt the plaintext.\n");
        EVP_CIPHER_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Don't forget to finalize the encryption process to make sure any remaining data is processed.
    if (EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_out_len, &ciphertext_out_len) != 1) {
        fprintf(stderr, "Failed to finalize the encryption process.\n");
        EVP_CIPHER_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Now that our plaintext is securely encrypted, we can release the OpenSSL context.
    EVP_CIPHER_CTX_free(ctx);

    // Let's display the ciphertext!
    printf("Encrypted Ciphertext (in hexadecimal):\n");
    for (size_t i = 0; i < ciphertext_out_len; i++) {
        printf("%02X", ciphertext[i]);
    }
    printf("\n");

    // For demonstration purposes, let's assume we received the ciphertext from somewhere else.
    printf("\nNow, let's try to decrypt the ciphertext we just encrypted.\n");

    // We create a new OpenSSL context for decryption.
    ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        fprintf(stderr, "Failed to create EVP context for decryption.\n");
        return EXIT_FAILURE;
    }

    // We initialize the context for decryption using the same parameters as encryption.
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL) != 1) {
        fprintf(stderr, "Failed to initialize decryption context.\n");
        EVP_CIPHER_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Allocate space for the decrypted plaintext.
    unsigned char decryptedtext[strlen(plaintext)];

    int decryptedtext_len;
    // Perform the decryption operation by passing in the ciphertext, decryptedtext buffer, and the length of the ciphertext.
    if (EVP_DecryptUpdate(ctx, decryptedtext, &decryptedtext_len, ciphertext, ciphertext_out_len) != 1) {
        fprintf(stderr, "Failed to decrypt the ciphertext.\n");
        EVP_CIPHER_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Finalize the decryption process to make sure any remaining data is processed.
    if (EVP_DecryptFinal_ex(ctx, decryptedtext + decryptedtext_len, &decryptedtext_len) != 1) {
        fprintf(stderr, "Failed to finalize the decryption process.\n");
        EVP_CIPHER_CTX_free(ctx);
        return EXIT_FAILURE;
    }

    // Release the OpenSSL context after decryption.
    EVP_CIPHER_CTX_free(ctx);

    // Finally, let's print the decrypted plaintext and witness the magic!
    printf("Decrypted Plaintext:\n%s\n", decryptedtext);

    return EXIT_SUCCESS;
}