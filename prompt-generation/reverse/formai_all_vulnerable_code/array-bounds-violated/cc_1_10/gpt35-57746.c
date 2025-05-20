//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<openssl/conf.h>
#include<openssl/evp.h>
#include<openssl/err.h>

void handleErrors(void)
{
    ERR_print_errors_fp(stderr);
    abort();
}

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int ciphertext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        handleErrors();

    ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)) handleErrors();

    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int plaintext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len))
        handleErrors();

    plaintext_len = len;

    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)) handleErrors();

    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}

int main (void)
{
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    unsigned char key[] = "01234567890123456789012345678901";
    unsigned char iv[] = "0123456789012345";

    /* Message to be encrypted */
    unsigned char plaintext[] = "Secret message!";

    /* Maximum size of ciphertext is length of plaintext plus the block size of cipher algorithm */
    unsigned char ciphertext[sizeof(plaintext) + EVP_MAX_BLOCK_LENGTH];
    int ciphertext_len;

    /* Buffer to hold decrypted text */
    unsigned char decryptedtext[sizeof(ciphertext)];
    int decryptedtext_len;

    /* Encrypt the plaintext */
    ciphertext_len = encrypt(plaintext, strlen(plaintext), key, iv, ciphertext);

    /* Decrypt the ciphertext */
    decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);

    /* Add null character at the end of decrypted text to print it */
    decryptedtext[decryptedtext_len] = '\0';

    printf("Original Message: %s\n", plaintext);
    printf("Encrypted Message: ");
    BIO_dump_fp(stdout, ciphertext, ciphertext_len);
    printf("\nDecrypted Message: %s\n", decryptedtext);

    /* Remove all ciphers and digests */
    EVP_cleanup();
    /* Remove all digests and ciphers loaded into the library at runtime*/
    ERR_free_strings();

    return 0;
}