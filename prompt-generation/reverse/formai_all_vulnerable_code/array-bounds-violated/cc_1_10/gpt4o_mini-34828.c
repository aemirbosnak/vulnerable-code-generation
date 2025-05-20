//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define MAX_INPUT_SIZE 1024
#define KEY_SIZE 32 // 256 bits
#define IV_SIZE 16  // 128 bits

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

void generateKeyAndIV(unsigned char *key, unsigned char *iv) {
    // Generate key and IV using random bytes
    if (!RAND_bytes(key, KEY_SIZE)) handleErrors();
    if (!RAND_bytes(iv, IV_SIZE)) handleErrors();
}

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
             unsigned char *iv, unsigned char *ciphertext, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;
    int len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize the encryption operation
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();

    // Provide the message to be encrypted, and obtain the encrypted output
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) handleErrors();
    *ciphertext_len = len;

    // Finalize the encryption
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();
    *ciphertext_len += len;

    // Clean up the context
    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
             unsigned char *iv, unsigned char *plaintext, int *plaintext_len) {
    EVP_CIPHER_CTX *ctx;
    int len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize the decryption operation
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) handleErrors();

    // Provide the message to be decrypted, and obtain the plaintext output
    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)) handleErrors();
    *plaintext_len = len;

    // Finalize the decryption
    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();
    *plaintext_len += len;

    // Clean up the context
    EVP_CIPHER_CTX_free(ctx);
}

void printHex(const char *label, unsigned char *data, int len) {
    printf("%s: ", label);
    for (int i = 0; i < len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {
    unsigned char key[KEY_SIZE];
    unsigned char iv[IV_SIZE];

    // Allocate memory for plaintext and ciphertext
    unsigned char plaintext[MAX_INPUT_SIZE];
    unsigned char ciphertext[MAX_INPUT_SIZE + EVP_MAX_BLOCK_LENGTH];
    unsigned char decryptedtext[MAX_INPUT_SIZE + EVP_MAX_BLOCK_LENGTH];
    int decryptedtext_len, ciphertext_len;

    printf("Enter plaintext: ");
    fgets((char *)plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn((char *)plaintext, "\n")] = 0; // remove newline

    generateKeyAndIV(key, iv);

    printf("Key: ");
    printHex("Generated Key", key, KEY_SIZE);
    printf("IV: ");
    printHex("Generated IV", iv, IV_SIZE);

    // Encrypt the plaintext
    encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext, &ciphertext_len);
    printHex("Ciphertext", ciphertext, ciphertext_len);

    // Decrypt the ciphertext
    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, &decryptedtext_len);
    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the decrypted string

    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}