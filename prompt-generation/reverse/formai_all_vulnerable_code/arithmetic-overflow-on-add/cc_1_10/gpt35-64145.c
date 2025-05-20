//FormAI DATASET v1.0 Category: Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>

static const unsigned char key[] = {
    0x62, 0x44, 0xaa, 0xa0, 0xe1, 0x23, 0x2f, 0x37, 0x15, 0x22, 0xe1, 0xdd,
    0xd3, 0xc9, 0x20, 0xec, 0x71, 0xf5, 0x05, 0xcd, 0x7f, 0x83, 0xdd, 0x1e,
    0x8d, 0xea, 0x29, 0x22, 0x5d, 0x35, 0xfc, 0x4a
};

int encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
            unsigned char *iv, unsigned char *ciphertext) {

    EVP_CIPHER_CTX *ctx;

    int len;

    int ciphertext_len;

    if(!(ctx = EVP_CIPHER_CTX_new()))
        return -1;

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        return -1;

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len))
        return -1;

    ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len))
        return -1;

    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}


int main (void)
{
    /* Message to be encrypted */
    unsigned char plaintext[] = "Hello, world! This message will be encrypted.";
    
    /* Key for encryption */
    unsigned char *key_data = (unsigned char *)&key;
       
    /*Vector Initialization for cipher*/
    unsigned char iv[] = {0x5d, 0x5f, 0x75, 0x1a, 0x03, 0x6d, 0xff, 0x67, 0x05, 0x46, 0xed, 0x0e, 0x15, 0x50, 0x68, 0x79};

    /* Buffer for ciphertext. Make sure the buffer is long enough
     * for your data. */
    unsigned char ciphertext[strlen((char*)plaintext) + EVP_MAX_BLOCK_LENGTH];
   
   
    int ciphertext_len = encrypt(plaintext, strlen((char*)plaintext), key_data, iv,
                                  ciphertext);

    /* Do something with the ciphertext here */
    printf("Ciphertext length: %d\n", ciphertext_len);
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertext_len; i++)
        printf("%02x", ciphertext[i]);

    return 0;
}