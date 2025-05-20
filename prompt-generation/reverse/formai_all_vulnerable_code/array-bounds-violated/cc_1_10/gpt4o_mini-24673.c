//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define KEY_LEN 32     // 256 bits
#define IV_LEN 16      // 128 bits
#define BLOCK_SIZE 16  // Block size for AES is 16 bytes

// Function prototypes
void handleErrors(void);
void encrypt(const unsigned char *plaintext, int plaintext_len, const unsigned char *key,
             const unsigned char *iv, unsigned char *ciphertext, int *ciphertext_len);
void decrypt(const unsigned char *ciphertext, int ciphertext_len, const unsigned char *key,
             const unsigned char *iv, unsigned char *plaintext, int *plaintext_len);
void generate_key_and_iv(unsigned char *key, unsigned char *iv);
void user_interaction_and_encryption();

int main() {
    user_interaction_and_encryption();
    return 0;
}

// Function to simulate an error handling mechanism
void handleErrors(void) {
    fprintf(stderr, "An error occurred during encryption or decryption.\n");
    exit(EXIT_FAILURE);
}

// Function to generate AES key and IV
void generate_key_and_iv(unsigned char *key, unsigned char *iv) {
    if (!RAND_bytes(key, KEY_LEN)) handleErrors();
    if (!RAND_bytes(iv, IV_LEN)) handleErrors();
}

// AES Encryption function
void encrypt(const unsigned char *plaintext, int plaintext_len, const unsigned char *key,
             const unsigned char *iv, unsigned char *ciphertext, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();
    
    // Initialize the encryption operation
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handleErrors();
    
    // Provide the message to be encrypted, and obtain the encrypted output
    int len;
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1) handleErrors();
    *ciphertext_len = len;

    // Finalize the encryption
    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) handleErrors();
    *ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

// AES Decryption function
void decrypt(const unsigned char *ciphertext, int ciphertext_len, const unsigned char *key,
             const unsigned char *iv, unsigned char *plaintext, int *plaintext_len) {
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();
    
    // Initialize the decryption operation
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handleErrors();

    // Provide the message to be decrypted, and obtain the decrypted output
    int len;
    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) != 1) handleErrors();
    *plaintext_len = len;

    // Finalize the decryption
    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &len) != 1) handleErrors();
    *plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

// Function for user interaction and encryption/decryption process
void user_interaction_and_encryption() {
    unsigned char key[KEY_LEN];
    unsigned char iv[IV_LEN];
    char plaintext[128];

    // Generate random key and IV
    generate_key_and_iv(key, iv);
    printf("Generated AES Key and IV.\n\n");

    printf("Enter a message to encrypt: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = 0; // Remove newline character

    unsigned char ciphertext[128];
    int ciphertext_len;

    // Encrypt the plaintext
    encrypt((unsigned char *)plaintext, strlen(plaintext), key, iv, ciphertext, &ciphertext_len);

    printf("Encrypted message:\n");
    for (int i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);
    printf("\n\n");

    unsigned char decryptedtext[128];
    int decryptedtext_len;

    // Decrypt the ciphertext
    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, &decryptedtext_len);
    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the decrypted string

    printf("Decrypted message: %s\n", decryptedtext);
}