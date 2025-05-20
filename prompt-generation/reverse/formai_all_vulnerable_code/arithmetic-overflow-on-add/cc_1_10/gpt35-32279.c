//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>

#define MAX_SIZE 1024

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
            unsigned char *iv, unsigned char *ciphertext);

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
            unsigned char *iv, unsigned char *plaintext);

void print_hex(unsigned char *hex, int hex_len);

int main(int argc, char *argv[]) {

    unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];
    unsigned char plaintext[MAX_SIZE], ciphertext[MAX_SIZE], decrypted_plaintext[MAX_SIZE];
    int plaintext_len, ciphertext_len, decrypted_plaintext_len;

    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    /* Generate a random key and random iv */
    RAND_bytes(key, EVP_MAX_KEY_LENGTH);
    RAND_bytes(iv, EVP_MAX_IV_LENGTH);

    /* Get the plaintext from the user */
    printf("Enter plaintext: ");
    fgets(plaintext, MAX_SIZE, stdin);
    plaintext_len = strlen(plaintext);

    printf("\n===============================================================================\n\n");

    /* Encrypt the plaintext */
    ciphertext_len = encrypt(plaintext, plaintext_len, key, iv, ciphertext);
    printf("Ciphertext is:\n");
    print_hex(ciphertext, ciphertext_len);

    printf("Encryption key is:\n");
    print_hex(key, EVP_MAX_KEY_LENGTH);

    printf("Initialization vector is:\n");
    print_hex(iv, EVP_MAX_IV_LENGTH);

    printf("\n===============================================================================\n\n");

    /* Decrypt the ciphertext */
    decrypted_plaintext_len = decrypt(ciphertext, ciphertext_len, key, iv, decrypted_plaintext);
    printf("Decrypted plaintext is:\n");
    printf("%s", decrypted_plaintext);

    printf("\n===============================================================================\n\n");

    /* Clean up */
    EVP_cleanup();
    ERR_free_strings();

    return 0;
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
            unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len, ciphertext_len;

    /* Create and initialize the context */
    if(!(ctx = EVP_CIPHER_CTX_new())) {
        printf("Error creating context.\n");
        return -1;
    }

    /* Initialize the encryption */
    if(EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
        printf("Error initializing encryption.\n");
        return -2;
    }

    /* Encrypt the plaintext */
    if(EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len) != 1) {
        printf("Error encrypting.\n");
        return -3;
    }
    ciphertext_len = len;

    /* Finalize the encryption */
    if(EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) {
        printf("Error finalizing encryption.\n");
        return -4;
    }
    ciphertext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
        unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len, plaintext_len;

    /* Create and initialize the context */
    if(!(ctx = EVP_CIPHER_CTX_new())) {
        printf("Error creating context.\n");
        return -1;
    }

    /* Initialize the decryption */
    if(EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
        printf("Error initializing decryption.\n");
        return -2;
    }

    /* Decrypt the ciphertext */
    if(EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) != 1) {
        printf("Error decrypting.\n");
        return -3;
    }
    plaintext_len = len;

    /* Finalize the decryption */
    if(EVP_DecryptFinal_ex(ctx, plaintext + len, &len) != 1) {
        printf("Error finalizing decryption.\n");
        return -4;
    }
    plaintext_len += len;

    /* Clean up */
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

void print_hex(unsigned char *hex, int hex_len) {
    for(int i = 0; i < hex_len; i++) {
        printf("%02x", hex[i]);
    }
    printf("\n");
}