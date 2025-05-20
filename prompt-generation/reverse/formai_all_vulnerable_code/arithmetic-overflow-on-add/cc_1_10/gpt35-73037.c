//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

#define KEY_SIZE 16
#define IV_SIZE 16

void handleErrors(void)
{
    printf("An error occurred.\n");
    abort();
}

void encrypt(unsigned char *plaintext, int plaintext_len, unsigned char *key,
             unsigned char *iv, unsigned char *ciphertext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int ciphertext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())){
        handleErrors();
    }

    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv)){
        handleErrors();
    }

    if(1 != EVP_EncryptUpdate(ctx, ciphertext, &len, plaintext, plaintext_len)){
        handleErrors();
    }

    ciphertext_len = len;

    if(1 != EVP_EncryptFinal_ex(ctx, ciphertext + len, &len)){
        handleErrors();
    }

    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key,
             unsigned char *iv, unsigned char *plaintext)
{
    EVP_CIPHER_CTX *ctx;

    int len;

    int plaintext_len;

    if(!(ctx = EVP_CIPHER_CTX_new())){
        handleErrors();
    }

    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv)){
        handleErrors();
    }

    if(1 != EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len)){
        handleErrors();
    }

    plaintext_len = len;

    if(1 != EVP_DecryptFinal_ex(ctx, plaintext + len, &len)){
        handleErrors();
    }

    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}


int main(int argc, char *argv[])
{
    unsigned char key[KEY_SIZE];
    unsigned char iv[IV_SIZE];

    // Generate a random key and IV
    if(!RAND_bytes(key, KEY_SIZE)){
        handleErrors();
    }

    if(!RAND_bytes(iv, IV_SIZE)){
        handleErrors();
    }

    unsigned char input[] = "Hi, I am a chatbot!";
    size_t input_len = strlen((char *)input);

    unsigned char encrypted[input_len + EVP_MAX_BLOCK_LENGTH];

    encrypt(input, input_len, key, iv, encrypted);

    unsigned char decrypted[input_len + EVP_MAX_BLOCK_LENGTH];

    decrypt(encrypted, input_len, key, iv, decrypted);

    printf("Input message: %s\n", input);
    printf("Encrypted message: %s\n", encrypted);
    printf("Decrypted message: %s\n", decrypted);

    return 0;
}