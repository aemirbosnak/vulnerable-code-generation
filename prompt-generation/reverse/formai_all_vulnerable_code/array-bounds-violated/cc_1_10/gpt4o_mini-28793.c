//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/rand.h>

#define AES_KEY_LENGTH 256
#define AES_BLOCK_SIZE 16
#define ERR_BUF_SIZE 130

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

void generate_salt(unsigned char *salt, int salt_len) {
    if (!RAND_bytes(salt, salt_len)) {
        handleErrors();
    }
}

void derive_key(const char *password, unsigned char *salt, unsigned char *key, unsigned char *iv) {
    if (!PKCS5_PBKDF2_HMAC_SHA1(password, strlen(password), salt, AES_BLOCK_SIZE, 10000, AES_KEY_LENGTH/8, key)) {
        handleErrors();
    }
    memset(iv, 0, AES_BLOCK_SIZE);  // Use a zero IV for simplicity
}

void encrypt(const unsigned char *plaintext, int plaintext_len, const unsigned char *key, const unsigned char *iv,
             unsigned char *ciphertext, int *ciphertext_len) {
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1)
        handleErrors();

    if (EVP_EncryptUpdate(ctx, ciphertext, ciphertext_len, plaintext, plaintext_len) != 1)
        handleErrors();

    int len;
    if (EVP_EncryptFinal_ex(ctx, ciphertext + *ciphertext_len, &len) != 1)
        handleErrors();

    *ciphertext_len += len;
    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(const unsigned char *ciphertext, int ciphertext_len, const unsigned char *key, const unsigned char *iv,
             unsigned char *plaintext, int *plaintext_len) {
    EVP_CIPHER_CTX *ctx;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1)
        handleErrors();

    if (EVP_DecryptUpdate(ctx, plaintext, plaintext_len, ciphertext, ciphertext_len) != 1)
        handleErrors();

    int len;
    if (EVP_DecryptFinal_ex(ctx, plaintext + *plaintext_len, &len) != 1)
        handleErrors();

    *plaintext_len += len;
    EVP_CIPHER_CTX_free(ctx);
}

int main() {
    unsigned char key[AES_KEY_LENGTH / 8], iv[AES_BLOCK_SIZE], salt[AES_BLOCK_SIZE];
    unsigned char message[128], ciphertext[128], decryptedtext[128];
    int decryptedtext_len = 0, ciphertext_len = 0;

    printf("Enter your password: ");
    char password[128];
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;  // Remove newline

    generate_salt(salt, AES_BLOCK_SIZE);
    derive_key(password, salt, key, iv);

    printf("Enter message to encrypt: ");
    fgets((char *)message, sizeof(message), stdin);
    message[strcspn((char *)message, "\n")] = 0;  // Remove newline

    encrypt(message, strlen((char *)message), key, iv, ciphertext, &ciphertext_len);

    printf("Salt: ");
    for(int i = 0; i < AES_BLOCK_SIZE; i++) {
        printf("%02x", salt[i]);
    }
    printf("\nCiphertext: ");
    for(int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext, &decryptedtext_len);
    decryptedtext[decryptedtext_len] = '\0'; // Null-terminate the decrypted string

    printf("Decrypted message: %s\n", decryptedtext);

    return 0;
}