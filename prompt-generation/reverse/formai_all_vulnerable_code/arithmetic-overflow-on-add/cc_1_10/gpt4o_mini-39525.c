//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define KEY_LENGTH 32 // AES-256
#define IV_LENGTH 16  // GCM IV length
#define TAG_LENGTH 16 // GCM Tag length

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

// Generate a random key
void generate_key(unsigned char *key) {
    if (!RAND_bytes(key, KEY_LENGTH)) {
        handleErrors();
    }
}

// Generate a random IV
void generate_iv(unsigned char *iv) {
    if (!RAND_bytes(iv, IV_LENGTH)) {
        handleErrors();
    }
}

// Encrypt the plaintext using AES GCM
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
             unsigned char *iv, unsigned char *ciphertext, unsigned char *tag) {
    EVP_CIPHER_CTX *ctx;
    
    int len;
    int ciphertext_len;

    // Create and initialize the context for encryption
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize encryption operation
    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, NULL, NULL) != 1)
        handleErrors();

    // Set IV length
    if (EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_IVLEN, IV_LENGTH, NULL) != 1)
        handleErrors();

    // Initialize key and IV
    if (EVP_EncryptInit_ex(ctx, NULL, NULL, key, iv) != 1)
        handleErrors();

    // Provide the message to be encrypted
    if (EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1)
        handleErrors();
    ciphertext_len = len;

    // Finalize encryption
    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1)
        handleErrors();
    ciphertext_len += len;

    // Get the GCM tag
    if (EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_GET_TAG, TAG_LENGTH, tag) != 1)
        handleErrors();

    // Clean up
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

// Decrypt the ciphertext using AES GCM
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
             unsigned char *iv, unsigned char *tag, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;

    int len;
    int plaintext_len;
    int ret;

    // Create and initialize the context for decryption
    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    // Initialize decryption operation
    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, NULL, NULL) != 1)
        handleErrors();

    // Set IV length
    if (EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_IVLEN, IV_LENGTH, NULL) != 1)
        handleErrors();

    // Initialize key and IV
    if (EVP_DecryptInit_ex(ctx, NULL, NULL, key, iv) != 1)
        handleErrors();

    // Provide the message to be decrypted
    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) != 1)
        handleErrors();
    plaintext_len = len;

    // Set the expected tag value
    if (EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_TAG, TAG_LENGTH, tag) != 1)
        handleErrors();

    // Finalize the decryption
    ret = EVP_DecryptFinal_ex(ctx, plaintext + len, &len);
    EVP_CIPHER_CTX_free(ctx);

    if (ret > 0) {
        plaintext_len += len;
        return plaintext_len; // Successful decryption
    } else {
        return -1; // Decryption failed
    }
}

int main() {
    // Sample plaintext to encrypt
    unsigned char *plaintext = (unsigned char *)"This is a test message for encryption.";
    
    // Buffers for keys, IVs, and tags
    unsigned char key[KEY_LENGTH];
    unsigned char iv[IV_LENGTH];
    unsigned char tag[TAG_LENGTH];
    unsigned char ciphertext[128];
    unsigned char decryptedtext[128];

    // Length of the plaintext
    int plaintext_len = strlen((char *)plaintext);

    // Generate key and IV
    generate_key(key);
    generate_iv(iv);

    // Encrypt
    int ciphertext_len = encrypt(plaintext, plaintext_len, key, iv, ciphertext, tag);
    printf("Ciphertext is:\n");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x ", ciphertext[i]);
    }
    printf("\n");

    // Decrypt
    int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, tag, decryptedtext);

    if (decryptedtext_len >= 0) {
        decryptedtext[decryptedtext_len] = '\0'; // Null-terminate decrypted text
        printf("Decrypted text is: %s\n", decryptedtext);
    } else {
        printf("Decryption failed!\n");
    }

    return 0;
}