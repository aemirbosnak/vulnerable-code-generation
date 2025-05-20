//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define BUF_SIZE 1024

void print_hex(const char *title, const unsigned char *s, int len);

int main(int argc, char **argv)
{
    EVP_CIPHER_CTX *ctx;
    unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];
    unsigned char ciphertext[BUF_SIZE + EVP_MAX_BLOCK_LENGTH];
    unsigned char plaintext[BUF_SIZE];
    int len;
    int plaintext_len = 0, ciphertext_len = 0;
    
    const char *passphrase = "mysecretpassword";
    const char *data = "ATTACK AT DAWN";

    /* Create and initialize the context */
    ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        fprintf(stderr, "Error creating context.\n");
        return EXIT_FAILURE;
    }

    /* Generate the key and IV from the passphrase and data */
    if (!EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha256(), NULL, (unsigned char *)passphrase, strlen(passphrase), 1000, key, iv)) {
        fprintf(stderr, "Error generating key and IV.\n");
        return EXIT_FAILURE;
    }

    /* Set the encryption cipher */
    if (!EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        fprintf(stderr, "Error setting encryption cipher.\n");
        return EXIT_FAILURE;
    }

    /* Encrypt the data */
    if (!EVP_EncryptUpdate(ctx, ciphertext, &len, (unsigned char *)data, strlen(data))) {
        fprintf(stderr, "Error encrypting data.\n");
        return EXIT_FAILURE;
    }
    ciphertext_len = len;

    /* Finish the encryption */
    if (!EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) {
        fprintf(stderr, "Error finishing encryption.\n");
        return EXIT_FAILURE;
    }
    ciphertext_len += len;

    /* Clean up the context */
    EVP_CIPHER_CTX_free(ctx);
    ctx = NULL;

    /* Print the plaintext */
    printf("Plaintext: %s\n", data);

    /* Print the ciphertext */
    print_hex("Ciphertext", ciphertext, ciphertext_len);

    /* Create and initialize the context */
    ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        fprintf(stderr, "Error creating context.\n");
        return EXIT_FAILURE;
    }

    /* Set the decryption cipher */
    if (!EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        fprintf(stderr, "Error setting decryption cipher.\n");
        return EXIT_FAILURE;
    }

    /* Decrypt the data */
    if (!EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)) {
        fprintf(stderr, "Error decrypting data.\n");
        return EXIT_FAILURE;
    }
    plaintext_len = len;

    /* Finish the decryption */
    if (!EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) {
        fprintf(stderr, "Error finishing decryption.\n");
        return EXIT_FAILURE;
    }
    plaintext_len += len;

    /* Clean up the context */
    EVP_CIPHER_CTX_free(ctx);
    ctx = NULL;

    /* Print the decrypted data */
    plaintext[plaintext_len] = '\0';
    printf("Decrypted Data: %s\n", plaintext);

    return EXIT_SUCCESS;
}

void print_hex(const char *title, const unsigned char *s, int len)
{
    int i;
    printf("%s:\n", title);
    for (i = 0; i < len; i++) {
        printf("%02X", s[i]);
    }
    printf("\n");
}