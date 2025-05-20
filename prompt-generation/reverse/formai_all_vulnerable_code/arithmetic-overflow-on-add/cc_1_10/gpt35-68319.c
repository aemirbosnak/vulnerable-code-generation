//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/err.h>
#include <openssl/evp.h>

void handleErrors(void);
int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
            unsigned char *iv, unsigned char *ciphertext);
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
            unsigned char *iv, unsigned char *plaintext);

int main(void) {

    /* Set up the plaintext, key and IV */
    unsigned char plaintext[] = "This is a top secret message";
    unsigned char key[] = "This is a secret key";
    unsigned char iv[] = "initializationV";

    /* Set up the encrypted buffer and ciphertext length, and encrypt the plaintext */
    unsigned char ciphertext[128];
    int ciphertext_len = encrypt(plaintext, strlen((char *)plaintext), key, iv,
                                  ciphertext);

    /* Output the encrypted data */
    printf("Ciphertext is:\n");
    BIO_dump_fp(stdout, (const char *)ciphertext, ciphertext_len);

    /* Set up the decrypted buffer and plaintext length, and decrypt the ciphertext */
    unsigned char decryptedtext[128];
    int decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv,
                                    decryptedtext);

    /* Output the decrypted data */
    printf("Decrypted text is:\n");
    printf("%s\n", decryptedtext);

    return 0;
}

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}  

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
            unsigned char *iv, unsigned char *ciphertext) {

    /* Set up the cipher and context */
    EVP_CIPHER_CTX *ctx;

    /* Create and initialize the context */
    if(!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    /* Initialize the encryption operation */
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    int len;
    int ciphertext_len;

    /* Start the encryption */
    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();
    ciphertext_len = len;

    /* Finalize the encryption */
    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        handleErrors();
    ciphertext_len += len;

    /* Clean up the context */
    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}  

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
            unsigned char *iv, unsigned char *plaintext) {

    /* Set up the cipher and context */
    EVP_CIPHER_CTX *ctx;

    /* Create and initialize the context */
    if(!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    /* Initialize the decryption operation */
    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    int len;
    int plaintext_len;

    /* Start the decryption */
    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();
    plaintext_len = len;

    /* Finalize the decryption */
    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len))
        handleErrors();
    plaintext_len += len;

    /* Clean up the context */
    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}