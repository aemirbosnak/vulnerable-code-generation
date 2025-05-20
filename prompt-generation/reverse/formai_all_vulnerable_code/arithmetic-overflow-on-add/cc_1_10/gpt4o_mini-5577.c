//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define KEY_LENGTH     32  // AES-256
#define BLOCK_SIZE     16  // AES block size
#define IV_LENGTH      16  // For AES, the IV should be 16 bytes

// Function to handle encryption
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
             unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) return -1;

    // Initialize the encryption operation
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) return -1;

    // Provide the message to be encrypted
    int len;
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1) return -1;

    int ciphertext_len = len;

    // Finalize the encryption
    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) return -1;
    ciphertext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

// Function to handle decryption
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
             unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) return -1;

    // Initialize the decryption operation
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) return -1;

    // Provide the message to be decrypted
    int len;
    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) != 1) return -1;

    int plaintext_len = len;

    // Finalize the decryption
    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &len) != 1) return -1;
    plaintext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

// Function to print hex values for the ciphertext
void print_hex(const char *prefix, unsigned char *str, int len) {
    printf("%s", prefix);
    for (int i = 0; i < len; i++) {
        printf("%02x", str[i]);
    }
    printf("\n");
}

int main() {
    // Plaintext and keys
    unsigned char *plaintext = (unsigned char *)"This is a secret message.";
    unsigned char key[KEY_LENGTH];
    unsigned char iv[IV_LENGTH];

    // Generate random key and IV
    if (!RAND_bytes(key, sizeof(key))) {
        fprintf(stderr, "Failed to generate random bytes for key.\n");
        return 1;
    }
    if (!RAND_bytes(iv, sizeof(iv))) {
        fprintf(stderr, "Failed to generate random bytes for IV.\n");
        return 1;
    }

    // Output original message
    printf("Original plaintext: %s\n", plaintext);

    // Buffers for ciphertext and decrypted text
    unsigned char ciphertext[128];
    unsigned char decryptedtext[128];

    // Encrypt the plaintext
    int ciphertext_len = encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext);
    if (ciphertext_len == -1) {
        fprintf(stderr, "Encryption failed.\n");
        return 1;
    }

    // Print the hex representation of the ciphertext
    print_hex("Ciphertext: ", ciphertext, ciphertext_len);

    // Decrypt the ciphertext
    int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);
    if (decryptedtext_len == -1) {
        fprintf(stderr, "Decryption failed.\n");
        return 1;
    }

    // Null terminate the decrypted string
    decryptedtext[decryptedtext_len] = '\0';

    // Output the decrypted message
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}