//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define KEY_LENGTH 32  // Length of the key for AES-256
#define IV_LENGTH 16   // Length of the Initialization Vector (IV)

// Function to encrypt plaintext using AES-256-CBC
int encrypt(const unsigned char *plaintext, int plaintext_len, 
            const unsigned char *key, const unsigned char *iv, 
            unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) 
        return -1;

    // Initialize the encryption operation
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) 
        return -1;

    // Provide the message to be encrypted
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1) 
        return -1;
    ciphertext_len = len;

    // Finalize the encryption
    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) 
        return -1;
    ciphertext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

// Function to decrypt ciphertext using AES-256-CBC
int decrypt(const unsigned char *ciphertext, int ciphertext_len, 
            const unsigned char *key, const unsigned char *iv, 
            unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) 
        return -1;

    // Initialize the decryption operation
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) 
        return -1;

    // Provide the message to be decrypted
    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) != 1) 
        return -1;
    plaintext_len = len;

    // Finalize the decryption
    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &len) != 1) 
        return -1;
    plaintext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

// Function to print a buffer in hexadecimal representation
void print_hex(const char *label, const unsigned char *buffer, int length) {
    printf("%s: ", label);
    for (int i = 0; i < length; i++) {
        printf("%02x", buffer[i]);
    }
    printf("\n");
}

int main() {
    // Example plaintext to encrypt
    const char *plaintext = "This is a secret message!";
    unsigned char key[KEY_LENGTH] = "01234567890123456789012345678901"; // 32 bytes for AES-256
    unsigned char iv[IV_LENGTH] = "0123456789012345"; // 16 bytes for AES block size

    // Allocate cipher text buffer
    unsigned char ciphertext[128];
    unsigned char decryptedtext[128];

    // Encrypt the plaintext
    int ciphertext_len = encrypt((unsigned char *)plaintext, strlen(plaintext), key, iv, ciphertext);
    if (ciphertext_len < 0) {
        fprintf(stderr, "Encryption failed!\n");
        return 1;
    }

    // Print encrypted data
    print_hex("Ciphertext", ciphertext, ciphertext_len);

    // Decrypt the ciphertext
    int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);
    if (decryptedtext_len < 0) {
        fprintf(stderr, "Decryption failed!\n");
        return 1;
    }

    // Null terminate the decrypted text
    decryptedtext[decryptedtext_len] = '\0';

    // Print decrypted data
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}