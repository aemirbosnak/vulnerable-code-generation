//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define KEY_LENGTH 32    // AES-256 key length
#define BLOCK_SIZE 16    // AES block size
#define IV_LENGTH 16     // Initialization vector length
#define TAG_LENGTH 16    // GCM tag length

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

void generate_symmetric_key(unsigned char *key) {
    if (!RAND_bytes(key, KEY_LENGTH)) {
        handleErrors();
    }
}

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;
    int len;
    *ciphertext_len = 0;

    // Initialize the encryption operation
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, NULL, NULL)) handleErrors();

    // Provide the key and IV
    if (1 != EVP_EncryptInit_ex(ctx, NULL, NULL, key, iv)) handleErrors();

    // Provide the message to be encrypted
    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) handleErrors();
    *ciphertext_len += len;

    // Finalize the encryption
    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + *ciphertext_len, &len)) handleErrors();
    *ciphertext_len += len;

    // Get the GCM tag
    unsigned char tag[TAG_LENGTH];
    if (1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_GET_TAG, TAG_LENGTH, tag)) handleErrors();

    // Clean up the encryption context
    EVP_CIPHER_CTX_free(ctx);

    // Append the tag to the ciphertext
    memcpy(ciphertext + *ciphertext_len, tag, TAG_LENGTH);
    *ciphertext_len += TAG_LENGTH;
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext, int *plaintext_len) {
    EVP_CIPHER_CTX *ctx;
    int len;
    *plaintext_len = 0;

    unsigned char tag[TAG_LENGTH];
    memcpy(tag, ciphertext + ciphertext_len - TAG_LENGTH, TAG_LENGTH);
    ciphertext_len -= TAG_LENGTH;

    // Initialize the decryption operation
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, NULL, NULL)) handleErrors();

    // Provide the key and IV
    if (1 != EVP_DecryptInit_ex(ctx, NULL, NULL, key, iv)) handleErrors();

    // Provide the message to be decrypted
    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)) handleErrors();
    *plaintext_len += len;

    // Set the expected tag value
    if (1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_TAG, TAG_LENGTH, tag)) handleErrors();

    // Finalize the decryption
    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + *plaintext_len, &len)) handleErrors();
    *plaintext_len += len;

    // Clean up the decryption context
    EVP_CIPHER_CTX_free(ctx);
}

int main() {
    unsigned char key[KEY_LENGTH];
    unsigned char iv[IV_LENGTH];
    unsigned char *plaintext = (unsigned char *)"This is a secret message.";
    unsigned char *ciphertext = malloc(strlen((char *)plaintext) + TAG_LENGTH);
    unsigned char decryptedtext[128];
    int decryptedtext_len, ciphertext_len;

    // Generate a random key
    generate_symmetric_key(key);

    // Generate a random IV
    if (!RAND_bytes(iv, IV_LENGTH)) handleErrors();

    printf("Original plaintext: %s\n", plaintext);

    // Encrypt the plaintext
    encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext, &ciphertext_len);
    printf("Ciphertext (hex): ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Decrypt the ciphertext
    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, &decryptedtext_len);
    decryptedtext[decryptedtext_len] = '\0';  // Null terminate the decrypted text

    printf("Decrypted text: %s\n", decryptedtext);

    // Clean up
    free(ciphertext);

    return 0;
}