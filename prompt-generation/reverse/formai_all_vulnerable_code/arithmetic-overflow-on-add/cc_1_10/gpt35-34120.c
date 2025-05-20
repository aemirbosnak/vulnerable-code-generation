//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define MESSAGE_LEN 1024
#define KEY_LEN 128

// Function to handle errors
void handleErrors() {
    printf("An error occurred\n");
    exit(1);
}

// Generate a secure random key
void generateKey(unsigned char* key, int keyLen) {
    if(!RAND_bytes(key, keyLen)) {
        handleErrors();
    }
}

// Encrypt a message using AES-128-CBC
int encrypt(unsigned char* key, unsigned char* iv, unsigned char* plaintext, int plaintextLen, unsigned char* ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len, ciphertextLen;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        handleErrors();
    }

    // Initialize the cipher
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv)) {
        handleErrors();
    }

    // Encrypt the plaintext
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintextLen)) {
        handleErrors();
    }
    ciphertextLen = len;

    // Finalize the encryption
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
        handleErrors();
    }
    ciphertextLen += len;

    // Free the context
    EVP_CIPHER_CTX_free(ctx);

    return ciphertextLen;
}

// Decrypt a message using AES-128-CBC
int decrypt(unsigned char* key, unsigned char* iv, unsigned char* ciphertext, int ciphertextLen, unsigned char* plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len, plaintextLen;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        handleErrors();
    }

    // Initialize the cipher
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv)) {
        handleErrors();
    }

    // Decrypt the ciphertext
    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertextLen)) {
        handleErrors();
    }
    plaintextLen = len;

    // Finalize the decryption
    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) {
        handleErrors();
    }
    plaintextLen += len;

    // Free the context
    EVP_CIPHER_CTX_free(ctx);

    return plaintextLen;
}

int main() {
    // Generate a random key
    unsigned char key[KEY_LEN];
    generateKey(key, KEY_LEN);

    // Generate a random IV
    unsigned char iv[EVP_MAX_IV_LENGTH];
    if (!RAND_bytes(iv, EVP_MAX_IV_LENGTH)) {
        handleErrors();
    }

    // Get a message to encrypt
    char message[MESSAGE_LEN];
    printf("Enter a message to encrypt: ");
    fgets(message, MESSAGE_LEN, stdin);
    message[strcspn(message, "\n")] = 0;

    // Encrypt the message
    unsigned char ciphertext[MESSAGE_LEN];
    int ciphertextLen = encrypt(key, iv, (unsigned char*)message, strlen(message), ciphertext);

    // Print the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertextLen; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the ciphertext
    unsigned char plaintext[MESSAGE_LEN];
    int plaintextLen = decrypt(key, iv, ciphertext, ciphertextLen, plaintext);

    // Print the plaintext
    printf("Plaintext: %s\n", (char*)plaintext);

    return 0;
}