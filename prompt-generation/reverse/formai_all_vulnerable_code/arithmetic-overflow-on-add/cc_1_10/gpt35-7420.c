//FormAI DATASET v1.0 Category: Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define SALT_SIZE 16
#define KEY_SIZE 32
#define BLOCK_SIZE 16

void encryptAsync(unsigned char *plaintext, int plaintext_len, unsigned char *key,
                  unsigned char *ciphertext, unsigned char *iv, int *ciphertext_len) {

    /* generate a random salt */
    unsigned char *salt = malloc(SALT_SIZE);
    RAND_bytes(salt, SALT_SIZE);

    /* derive the encryption key and initialization vector */
    EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha256(), salt, key, KEY_SIZE, 1, iv, NULL);

    /* set up the encryption context */
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    /* perform encryption */
    int len;
    EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len);
    *ciphertext_len = len;
    EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);
    *ciphertext_len += len;

    /* clean up */
    EVP_CIPHER_CTX_free(ctx);
    free(salt);
}

int main() {
    unsigned char plaintext[] = "Encryption example in C using OpenSSL library";
    int plaintext_len = strlen((char *) plaintext);

    /* generate a random key */
    unsigned char *key = malloc(KEY_SIZE);
    RAND_bytes(key, KEY_SIZE);

    /* allocate space for the ciphertext and initialization vector */
    unsigned char *ciphertext = malloc(plaintext_len + BLOCK_SIZE);
    unsigned char *iv = malloc(BLOCK_SIZE);

    int ciphertext_len;
    
    /* calling the asynchronous encryption function */
    encryptAsync(plaintext, plaintext_len, key, ciphertext, iv, &ciphertext_len);
   
    /* print out the results */
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    printf("Initialization vector: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", iv[i]);
    }
    printf("\n");

    /* clean up */
    free(key);
    free(ciphertext);
    free(iv);

    return 0;
}