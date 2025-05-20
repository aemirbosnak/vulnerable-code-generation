//FormAI DATASET v1.0 Category: modern Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
            unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;
    
    // Create and initialize the context
    if(!(ctx = EVP_CIPHER_CTX_new())) {
        return -1;
    }
    
    // Initialize the encryption operation.
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        return -1;
    }
    
    // Perform the encryption
    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) {
        return -1;
    }
    ciphertext_len = len;
    
    // Finalize the encryption
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
        return -1;
    }
    ciphertext_len += len;
    
    // Clean up the context
    EVP_CIPHER_CTX_free(ctx);
    
    return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
            unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;
    
    // Create and initialize the context
    if(!(ctx = EVP_CIPHER_CTX_new())) {
        return -1;
    }
    
    // Initialize the decryption operation
    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        return -1;
    }
    
    // Perform the decryption
    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)) {
        return -1;
    }
    plaintext_len = len;
    
    // Finalize the decryption
    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) {
        return -1;
    }
    plaintext_len += len;
    
    // Clean up the context
    EVP_CIPHER_CTX_free(ctx);
    
    return plaintext_len;
}

int main() {
    // Set up the encryption key and the IV
    unsigned char *key = (unsigned char *)"01234567890123456789012345678901";
    unsigned char *iv = (unsigned char *)"abcdefghijklmnop";
    
    // Set up the plaintext to be encrypted
    unsigned char *plaintext = (unsigned char *)"The quick brown fox jumps over the lazy dog";
    int plaintext_len = strlen((char *)plaintext);
    
    // Allocate memory for the ciphertext
    int ciphertext_len = plaintext_len + EVP_MAX_BLOCK_LENGTH;
    unsigned char *ciphertext = (unsigned char *)malloc(ciphertext_len);

    // Encrypt the plaintext
    int len = encrypt(plaintext, plaintext_len, key, iv, ciphertext);
    if(len == -1) {
        printf("Encryption failed!\n");
        return 1;
    }
    
    // Print the ciphertext
    printf("Ciphertext:\n");
    BIO_dump_fp(stdout, (char *)ciphertext, len);
    
    // Allocate memory for the decrypted text
    unsigned char *decryptedtext = (unsigned char *)malloc(len);

    // Decrypt the ciphertext
    int decryptedtext_len = decrypt(ciphertext, len, key, iv, decryptedtext);
    if(decryptedtext_len == -1) {
        printf("Decryption failed!\n");
        return 1;
    }
    
    // Print the decrypted text
    decryptedtext[decryptedtext_len] = '\0';
    printf("Decrypted text: %s\n", decryptedtext);
    
    // Free memory
    free(ciphertext);
    free(decryptedtext);

    return 0;
}