//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

// This function takes a plaintext message and a key, encrypts the message, and returns the encrypted message.
char* encrypt(char* plaintext, char* key) {
    // Set up OpenSSL context
    EVP_CIPHER_CTX* ctx;
    ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        printf("OpenSSL context creation failed.\n");
        exit(EXIT_FAILURE);
    }
    
    // Set up key and IV
    unsigned char* key_modified = (unsigned char*) malloc(strlen(key) + 1);
    strcpy((char*) key_modified, key);
    unsigned char iv[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
    
    // Initialize encryption
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key_modified, iv) != 1) {
        printf("Encryption initialization failed.\n");
        exit(EXIT_FAILURE);
    }
    
    // Encrypt
    unsigned char* ciphertext = (unsigned char*) malloc(strlen(plaintext) + EVP_CIPHER_block_size(EVP_aes_256_cbc()));
    int ciphertext_len;
    if (EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, (unsigned char*) plaintext, strlen(plaintext)) != 1) {
        printf("Encryption failed.\n");
        exit(EXIT_FAILURE);
    }
    int ciphertext_len_temp;
    if (EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &ciphertext_len_temp) != 1) {
        printf("Encryption finalization failed.\n");
        exit(EXIT_FAILURE);
    }
    ciphertext_len += ciphertext_len_temp;
    
    // Clean up and return
    EVP_CIPHER_CTX_free(ctx);
    free(key_modified);
    return (char*) ciphertext;
}

// This function takes an encrypted message and a key, decrypts the message, and returns the plaintext message.
char* decrypt(char* ciphertext, char* key) {
    // Set up OpenSSL context
    EVP_CIPHER_CTX* ctx;
    ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        printf("OpenSSL context creation failed.\n");
        exit(EXIT_FAILURE);
    }
    
    // Set up key and IV
    unsigned char* key_modified = (unsigned char*) malloc(strlen(key) + 1);
    strcpy((char*) key_modified, key);
    unsigned char iv[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
    
    // Initialize decryption
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key_modified, iv) != 1) {
        printf("Decryption initialization failed.\n");
        exit(EXIT_FAILURE);
    }
    
    // Decrypt
    unsigned char* plaintext = (unsigned char*) malloc(strlen(ciphertext));
    int plaintext_len;
    if (EVP_DecryptUpdate(ctx, plaintext, &plaintext_len, (unsigned char*) ciphertext, strlen(ciphertext)) != 1) {
        printf("Decryption failed.\n");
        exit(EXIT_FAILURE);
    }
    int plaintext_len_temp;
    if (EVP_DecryptFinal_ex(ctx, plaintext + plaintext_len, &plaintext_len_temp) != 1) {
        printf("Decryption finalization failed.\n");
        exit(EXIT_FAILURE);
    }
    plaintext_len += plaintext_len_temp;
    
    // Clean up and return
    EVP_CIPHER_CTX_free(ctx);
    free(key_modified);
    return (char*) plaintext;
}

int main() {
    // Set up message and key
    char* message = "Hello, world!";
    char* key = "supersecretkey";
    
    // Encrypt and print ciphertext
    char* ciphertext = encrypt(message, key);
    printf("Ciphertext: %s\n", ciphertext);
    
    // Decrypt and print plaintext
    char* plaintext = decrypt(ciphertext, key);
    printf("Plaintext: %s\n", plaintext);
    
    // Clean up
    free(ciphertext);
    free(plaintext);
    return 0;
}