//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <openssl/evp.h>

// Function to produce a random byte array of specified length
void generateRandomBytes(unsigned char* bytes, int len) {
    FILE* urandom = fopen("/dev/urandom", "r");
    fread(bytes, 1, len, urandom);
    fclose(urandom);
}

// Function to perform AES-256 encryption
// Takes in the plaintext, key, and initialization vector (IV)
// Returns the ciphertext
unsigned char* AES256Encrypt(unsigned char* plaintext, int plaintext_len,
                            unsigned char* key, unsigned char* iv) {
    EVP_CIPHER_CTX* ctx;
    int ciphertext_len;
    unsigned char* ciphertext = malloc(plaintext_len+16);

    // Initialize the context with the key and IV
    if(!(ctx = EVP_CIPHER_CTX_new())) {
        printf("Unable to create context\n");
        return NULL;
    }

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        printf("Unable to initialize encryption\n");
        return NULL;
    }

    // Perform the encryption
    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, plaintext, plaintext_len)) {
        printf("Unable to perform encryption\n");
        return NULL;
    }
    int final_ciphertext_len = ciphertext_len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext+ciphertext_len, &ciphertext_len)) {
        printf("Unable to complete encryption\n");
        return NULL;
    }
    final_ciphertext_len += ciphertext_len;

    EVP_CIPHER_CTX_free(ctx);
    ciphertext[final_ciphertext_len] = '\0';

    return ciphertext;
}

// Function to perform AES-256 decryption
// Takes in the ciphertext, key, and initialization vector (IV)
// Returns the plaintext
unsigned char* AES256Decrypt(unsigned char* ciphertext, int ciphertext_len,
                            unsigned char* key, unsigned char* iv) {
    EVP_CIPHER_CTX* ctx;
    int plaintext_len;
    unsigned char* plaintext = malloc(ciphertext_len+16);

    // Initialize the context with the key and IV
    if(!(ctx = EVP_CIPHER_CTX_new())) {
        printf("Unable to create context\n");
        return NULL;
    }

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        printf("Unable to initialize decryption\n");
        return NULL;
    }

    // Perform the decryption
    if(1 != EVP_DecryptUpdate(ctx, plaintext, &plaintext_len, ciphertext, ciphertext_len)) {
        printf("Unable to perform decryption\n");
        return NULL;
    }
    int final_plaintext_len = plaintext_len;

    if(1 != EVP_DecryptFinal_ex(ctx, plaintext+plaintext_len, &plaintext_len)) {
        printf("Unable to complete decryption\n");
        return NULL;
    }
    final_plaintext_len += plaintext_len;

    EVP_CIPHER_CTX_free(ctx);
    plaintext[final_plaintext_len] = '\0';

    return plaintext;
}

int main() {
    // Generate a random 256-bit key and initialization vector (IV)
    unsigned char key[32], iv[16];
    generateRandomBytes(key, 32);
    generateRandomBytes(iv, 16);

    // Define some plaintext to encrypt
    char* plaintext_string = "Hello, world!";
    int plaintext_len = strlen(plaintext_string) + 1;
    unsigned char plaintext[plaintext_len];
    memcpy(plaintext, plaintext_string, plaintext_len);

    // Perform the encryption
    unsigned char* ciphertext = AES256Encrypt(plaintext, plaintext_len, key, iv);
    printf("Ciphertext: %s\n", ciphertext);

    // Perform the decryption
    unsigned char* decrypted_plaintext = AES256Decrypt(ciphertext, strlen(ciphertext), key, iv);
    printf("Decrypted Plaintext: %s\n", decrypted_plaintext);

    return 0;
}