//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// Function to encrypt plaintext using AES-256-CBC algorithm with randomly generated key and IV
void encrypt(char *plaintext, int plaintext_len, char *key, char *iv, char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;
    // Create context for AES-256-CBC algorithm
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        printf("Error creating encryption context\n");
        exit(1);
    }
    // Initialize cipher with key and IV
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        printf("Error initializing encryption cipher\n");
        exit(1);
    }
    // Encrypt plaintext
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) {
        printf("Error encrypting plaintext\n");
        exit(1);
    }
    ciphertext_len = len;
    // Finalize encryption
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
        printf("Error finalizing encryption\n");
        exit(1);
    }
    ciphertext_len += len;
    EVP_CIPHER_CTX_free(ctx);
}

// Function to decrypt ciphertext using AES-256-CBC algorithm with given key and IV
void decrypt(char *ciphertext, int ciphertext_len, char *key, char *iv, char *decryptedtext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int decryptedtext_len;
    // Create context for AES-256-CBC algorithm
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        printf("Error creating decryption context\n");
        exit(1);
    }
    // Initialize cipher with key and IV
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        printf("Error initializing decryption cipher\n");
        exit(1);
    }
    // Decrypt ciphertext
    if (1 != EVP_DecryptUpdate(ctx, decryptedtext, &len, ciphertext, ciphertext_len)) {
        printf("Error decrypting ciphertext\n");
        exit(1);
    }
    decryptedtext_len = len;
    // Finalize decryption
    if (1 != EVP_DecryptFinal_ex(ctx, decryptedtext + len, &len)) {
        printf("Error finalizing decryption\n");
        exit(1);
    }
    decryptedtext_len += len;
    EVP_CIPHER_CTX_free(ctx);
}

int main() {
    char plaintext[] = "This is a test message.";
    char key[EVP_MAX_KEY_LENGTH];
    char iv[EVP_MAX_IV_LENGTH];
    char ciphertext[1024];
    char decryptedtext[1024];
    int plaintext_len = strlen(plaintext);
    int ciphertext_len;
    int decryptedtext_len;

    // Generate random key and IV
    RAND_bytes(key, EVP_MAX_KEY_LENGTH);
    RAND_bytes(iv, EVP_MAX_IV_LENGTH);

    // Encrypt plaintext with key and IV
    encrypt(plaintext, plaintext_len, key, iv, ciphertext);
    ciphertext_len = strlen(ciphertext);

    // Decrypt ciphertext with key and IV
    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);
    decryptedtext_len = strlen(decryptedtext);

    // Print results
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for(int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}