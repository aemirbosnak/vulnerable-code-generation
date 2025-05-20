//FormAI DATASET v1.0 Category: Modern Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rand.h>
#include <openssl/aes.h>
#include <pthread.h>

#define BUFFER_SIZE 512
#define KEY_SIZE 16

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext);
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext);
void *async_encrypt(void *args);

int main() {
    unsigned char key[KEY_SIZE], iv[KEY_SIZE];
    unsigned char plaintext[BUFFER_SIZE], ciphertext[BUFFER_SIZE], decrypted[BUFFER_SIZE];
    pthread_t thread;

    // Generate random key and iv
    RAND_bytes(key, KEY_SIZE);
    RAND_bytes(iv, KEY_SIZE);

    printf("Enter plaintext to encrypt (max length %d): ", BUFFER_SIZE);
    fgets(plaintext, BUFFER_SIZE, stdin);

    // Remove trailing newline from plaintext
    plaintext[strcspn(plaintext, "\n")] = 0;

    // Encrypt using synchronous function
    encrypt(plaintext, strlen(plaintext), key, iv, ciphertext);

    printf("\nSynchronous encryption complete. Ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Reset ciphertext buffer
    memset(ciphertext, 0, BUFFER_SIZE);

    // Encrypt using asynchronous function
    int rc;
    struct { unsigned char *plaintext; int plaintext_len; unsigned char *key; unsigned char *iv; unsigned char *ciphertext; } args = { plaintext, strlen(plaintext), key, iv, ciphertext };
    if ((rc = pthread_create(&thread, NULL, async_encrypt, &args))) {
        fprintf(stderr, "Error: return code from pthread_create() is %d\n", rc);
        exit(1);
    }

    // Wait for asynchronous function to complete
    pthread_join(thread, NULL);

    printf("\nAsynchronous encryption complete. Ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Decrypt ciphertext using synchronous function
    decrypt(ciphertext, strlen(plaintext), key, iv, decrypted);

    printf("\nSynchronous decryption complete. Decrypted text: %s\n", decrypted);

    return 0;
}

// Synchronous encryption function using AES-CBC mode
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;

    int ciphertext_len, len;
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        fprintf(stderr, "Error: failed to allocate EVP_CIPHER_CTX\n");
        return 0;
    }

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv)) {
        fprintf(stderr, "Error: encryption initialization failed\n");
        return 0;
    }

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) {
        fprintf(stderr, "Error: encryption update failed\n");
        return 0;
    }
    ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
        fprintf(stderr, "Error: encryption finalization failed\n");
        return 0;
    }
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

// Synchronous decryption function using AES-CBC mode
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;

    int plaintext_len, len;
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        fprintf(stderr, "Error: failed to allocate EVP_CIPHER_CTX\n");
        return 0;
    }

    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv)) {
        fprintf(stderr, "Error: decryption initialization failed\n");
        return 0;
    }

    if (1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)) {
        fprintf(stderr, "Error: decryption update failed\n");
        return 0;
    }
    plaintext_len = len;

    if (1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) {
        fprintf(stderr, "Error: decryption finalization failed\n");
        return 0;
    }
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

// Asynchronous encryption function using AES-CBC mode
void *async_encrypt(void *args) {
    unsigned char *plaintext = ((struct { unsigned char *plaintext; int plaintext_len; unsigned char *key; unsigned char *iv; unsigned char *ciphertext; } *)args)->plaintext;
    int plaintext_len = ((struct { unsigned char *plaintext; int plaintext_len; unsigned char *key; unsigned char *iv; unsigned char *ciphertext; } *)args)->plaintext_len;
    unsigned char *key = ((struct { unsigned char *plaintext; int plaintext_len; unsigned char *key; unsigned char *iv; unsigned char *ciphertext; } *)args)->key;
    unsigned char *iv = ((struct { unsigned char *plaintext; int plaintext_len; unsigned char *key; unsigned char *iv; unsigned char *ciphertext; } *)args)->iv;
    unsigned char *ciphertext = ((struct { unsigned char *plaintext; int plaintext_len; unsigned char *key; unsigned char *iv; unsigned char *ciphertext; } *)args)->ciphertext;

    EVP_CIPHER_CTX *ctx;

    int ciphertext_len, len;
    if (!(ctx = EVP_CIPHER_CTX_new())) {
        fprintf(stderr, "Error: failed to allocate EVP_CIPHER_CTX\n");
        return NULL;
    }

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv)) {
        fprintf(stderr, "Error: encryption initialization failed\n");
        return NULL;
    }

    if (1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)) {
        fprintf(stderr, "Error: encryption update failed\n");
        return NULL;
    }
    ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
        fprintf(stderr, "Error: encryption finalization failed\n");
        return NULL;
    }
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    pthread_exit(NULL);
}