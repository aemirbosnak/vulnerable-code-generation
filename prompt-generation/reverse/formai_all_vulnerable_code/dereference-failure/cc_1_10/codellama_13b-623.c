//Code Llama-13B DATASET v1.0 Category: Modern Encryption ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/evp.h>

#define BUFFER_SIZE 1024

// Function to encrypt the data using AES-256-CBC mode
void encrypt(unsigned char *data, int data_len, unsigned char *key, int key_len, unsigned char *iv, unsigned char *encrypted_data) {
    EVP_CIPHER_CTX *ctx;
    int encrypted_data_len;

    // Create and initialize the context
    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // Encrypt the data
    EVP_EncryptUpdate(ctx, encrypted_data, &encrypted_data_len, data, data_len);

    // Finalize the encryption
    EVP_EncryptFinal_ex(ctx, encrypted_data + encrypted_data_len, &encrypted_data_len);

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
}

// Function to decrypt the data using AES-256-CBC mode
void decrypt(unsigned char *encrypted_data, int encrypted_data_len, unsigned char *key, int key_len, unsigned char *iv, unsigned char *data) {
    EVP_CIPHER_CTX *ctx;
    int data_len;

    // Create and initialize the context
    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // Decrypt the data
    EVP_DecryptUpdate(ctx, data, &data_len, encrypted_data, encrypted_data_len);

    // Finalize the decryption
    EVP_DecryptFinal_ex(ctx, data + data_len, &data_len);

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
}

int main() {
    unsigned char *data = "Hello, World!";
    unsigned char *key = "secretkey1234567890123456";
    unsigned char *iv = "randomiv1234567890123456";
    unsigned char *encrypted_data;
    unsigned char *decrypted_data;

    // Encrypt the data
    encrypt(data, strlen(data), key, strlen(key), iv, encrypted_data);

    // Decrypt the data
    decrypt(encrypted_data, strlen(encrypted_data), key, strlen(key), iv, decrypted_data);

    // Print the decrypted data
    printf("%s\n", decrypted_data);

    return 0;
}