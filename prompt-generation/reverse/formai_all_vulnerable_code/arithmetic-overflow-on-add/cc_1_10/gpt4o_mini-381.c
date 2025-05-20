//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define KEY_LENGTH 32  // 256 bits
#define IV_LENGTH 16   // 128 bits
#define BUFFER_SIZE 1024

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

// Function to encrypt plaintext
int encrypt(const unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize the encryption operation
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handleErrors();

    // Provide the message to be encrypted
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1) handleErrors();
    ciphertext_len = len;

    // Finalize the encryption
    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) handleErrors();
    ciphertext_len += len;
    
    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

// Function to decrypt ciphertext
int decrypt(const unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize the decryption operation
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handleErrors();

    // Provide the message to be decrypted
    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) != 1) handleErrors();
    plaintext_len = len;

    // Finalize the decryption
    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &len) != 1) handleErrors();
    plaintext_len += len;
    
    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

// Function to generate a random key and IV
void generate_key_and_iv(unsigned char *key, unsigned char *iv) {
    if (!RAND_bytes(key, KEY_LENGTH)) {
        fprintf(stderr, "Key generation failed.\n");
        exit(EXIT_FAILURE);
    }
    if (!RAND_bytes(iv, IV_LENGTH)) {
        fprintf(stderr, "IV generation failed.\n");
        exit(EXIT_FAILURE);
    }
}

int main(void) {
    unsigned char key[KEY_LENGTH];   // Key buffer
    unsigned char iv[IV_LENGTH];     // Initialization vector buffer
    unsigned char plaintext[BUFFER_SIZE]; // Buffer for plaintext
    unsigned char ciphertext[BUFFER_SIZE + EVP_MAX_BLOCK_LENGTH]; // Buffer for ciphertext
    unsigned char decryptedtext[BUFFER_SIZE]; // Buffer for decrypted text

    // Generate key and IV
    generate_key_and_iv(key, iv);

    // Prompt user for message
    printf("Enter a message to encrypt: ");
    fgets((char*)plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn((char*)plaintext, "\n")] = 0;  // Remove newline

    // Encrypt the plaintext
    int ciphertext_len = encrypt(plaintext, strlen((char*)plaintext), key, iv, ciphertext);
    printf("Ciphertext is:\n");
    for (int i = 0; i < ciphertext_len; i++)
        printf("%02x ", ciphertext[i]);
    printf("\n");

    // Decrypt the ciphertext
    int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);
    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the decrypted string

    // Display the decrypted text
    printf("Decrypted text is:\n%s\n", decryptedtext);

    return 0;
}