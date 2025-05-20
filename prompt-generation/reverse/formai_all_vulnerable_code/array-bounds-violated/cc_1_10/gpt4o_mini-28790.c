//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

// Function prototypes
void handle_errors(void);
void encrypt(const unsigned char *plaintext, int plaintext_len,
             const unsigned char *key, const unsigned char *iv,
             unsigned char *ciphertext, int *ciphertext_len);
void decrypt(const unsigned char *ciphertext, int ciphertext_len,
             const unsigned char *key, const unsigned char *iv,
             unsigned char *plaintext, int *plaintext_len);

// Main function
int main() {
    // Initiate random seed
    srand(time(NULL));

    // Generate key and IV
    unsigned char key[32]; // 256-bit key
    unsigned char iv[16];  // 128-bit IV

    if (RAND_bytes(key, sizeof(key)) != 1) handle_errors();
    if (RAND_bytes(iv, sizeof(iv)) != 1) handle_errors();

    // Get plaintext input from user
    char plaintext[128];
    printf("Enter text to encrypt (max 128 chars): ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // Remove newline

    // Buffer for storing ciphertext
    unsigned char ciphertext[128];
    int ciphertext_len;

    // Encrypt the plaintext
    encrypt((unsigned char *)plaintext, strlen(plaintext), key, iv, ciphertext, &ciphertext_len);

    // Display ciphertext in hexadecimal format
    printf("Encrypted text (hexadecimal): ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Buffer for the decrypted text
    unsigned char decryptedtext[128];
    int decryptedtext_len;

    // Decrypt the ciphertext
    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, &decryptedtext_len);
    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the decrypted text

    // Display the decrypted text
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}

// Error handling function
void handle_errors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

// Encryption function
void encrypt(const unsigned char *plaintext, int plaintext_len,
             const unsigned char *key, const unsigned char *iv,
             unsigned char *ciphertext, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new())) handle_errors();

    // Initialize the encryption operation
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handle_errors();

    // Provide the message to be encrypted, and obtain the encrypted output
    if (EVP_EncryptUpdate(ctx, ciphertext, ciphertext_len, plaintext, plaintext_len) != 1) handle_errors();

    // Finalize the encryption
    int len;
    if (EVP_EncryptFinal_ex(ctx, ciphertext + *ciphertext_len, &len) != 1) handle_errors();
    *ciphertext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
}

// Decryption function
void decrypt(const unsigned char *ciphertext, int ciphertext_len,
             const unsigned char *key, const unsigned char *iv,
             unsigned char *plaintext, int *plaintext_len) {
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new())) handle_errors();

    // Initialize the decryption operation
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handle_errors();

    // Provide the message to be decrypted, and obtain the plain text output
    if (EVP_DecryptUpdate(ctx, plaintext, plaintext_len, ciphertext, ciphertext_len) != 1) handle_errors();

    // Finalize the decryption
    int len;
    if (EVP_DecryptFinal_ex(ctx, plaintext + *plaintext_len, &len) != 1) handle_errors();
    *plaintext_len += len;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
}