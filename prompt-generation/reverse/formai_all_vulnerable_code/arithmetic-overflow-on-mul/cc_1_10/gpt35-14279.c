//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

// Encrypts the given plaintext using the AES-256 algorithm in CBC mode
// with random initialization vector and the given key. Returns the encrypted text.
char* encrypt(char* plaintext, char* key) {
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);
    int iv_len = EVP_CIPHER_iv_length(EVP_aes_256_cbc());
    char* iv = (char*) malloc(iv_len);
    unsigned char* ciphertext = (unsigned char*) malloc(plaintext_len + EVP_CIPHER_block_size(EVP_aes_256_cbc()));
    int ciphertext_len;

    // Generate random initialization vector
    if(!RAND_bytes((unsigned char*) iv, iv_len)) {
        printf("Error generating IV\n");
        exit(1);
    }

    // Setup encryption context
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char*)key, (unsigned char*)iv);

    // Encrypt plaintext
    EVP_EncryptUpdate(ctx, ciphertext, &ciphertext_len, (unsigned char*) plaintext, plaintext_len);
    int tmp_len;
    EVP_EncryptFinal_ex(ctx, ciphertext + ciphertext_len, &tmp_len);
    ciphertext_len += tmp_len;

    // Cleanup encryption context
    EVP_CIPHER_CTX_free(ctx);
    free(iv);

    // Return encrypted text
    char* result = (char*) malloc(ciphertext_len*2 + 1);
    for(int i = 0; i < ciphertext_len; i++) {
        sprintf(result + (i*2), "%02x", ciphertext[i]);
    }
    result[ciphertext_len*2] = '\0';
    free(ciphertext);
    return result;
}

// Decrypts the given ciphertext using the AES-256 algorithm in CBC mode
// with the given key and initialization vector. Returns the decrypted text.
char* decrypt(char* ciphertext, char* key, char* iv) {
    int ciphertext_len = strlen(ciphertext);
    int key_len = strlen(key);
    int iv_len = strlen(iv);
    unsigned char* plaintext = (unsigned char*) malloc(ciphertext_len/2);
    int plaintext_len;

    // Convert hex-encoded ciphertext to byte array
    unsigned char* ciphertext_bytes = (unsigned char*) malloc(ciphertext_len/2);
    for(int i = 0; i < ciphertext_len; i += 2) {
        sscanf(ciphertext + i, "%02x", ciphertext_bytes + (i/2));
    }

    // Setup decryption context
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char*)key, (unsigned char*)iv);

    // Decrypt ciphertext
    EVP_DecryptUpdate(ctx, plaintext, &plaintext_len, ciphertext_bytes, ciphertext_len/2);
    int tmp_len;
    EVP_DecryptFinal_ex(ctx, plaintext+plaintext_len, &tmp_len);
    plaintext_len += tmp_len;

    // Cleanup decryption context
    EVP_CIPHER_CTX_free(ctx);
    free(ciphertext_bytes);

    // Return decrypted text
    char* result = (char*) malloc(plaintext_len+1);
    strncpy(result, (char*) plaintext, plaintext_len);
    result[plaintext_len] = '\0';
    free(plaintext);
    return result;
}

int main() {
    char* plaintext = "Hello, world!";
    char* key = "aBcD1234!@#$";
    char* encrypted = encrypt(plaintext, key);
    printf("Encrypted text: %s\n", encrypted);
    char* decrypted = decrypt(encrypted, key, "randomInitializationVector");
    printf("Decrypted text: %s\n", decrypted);
    free(encrypted);
    free(decrypted);
    return 0;
}