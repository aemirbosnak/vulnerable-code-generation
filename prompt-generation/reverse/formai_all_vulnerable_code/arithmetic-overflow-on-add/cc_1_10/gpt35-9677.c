//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <pthread.h>

#define MAX_THREADS 4
#define BLOCK_SIZE 1024

typedef struct {
    int tid;
    unsigned char *input;
    unsigned char *output;
    unsigned char *key;
    unsigned char *iv;
    int len;
    int outlen;
} thread_args;

void handleErrors(void)
{
    ERR_print_errors_fp(stderr);
    abort();
}

void encryption_worker(void *ptr)
{
    thread_args *args = (thread_args*)ptr;
    
    EVP_CIPHER_CTX *ctx;
    int len, outlen;

    ctx = EVP_CIPHER_CTX_new();
    if (!ctx) handleErrors();

    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, args->key, args->iv))
        handleErrors();

    if (1 != EVP_EncryptUpdate(ctx, args->output, &len, args->input, args->len))
        handleErrors();
    args->outlen = len;

    if (1 != EVP_EncryptFinal_ex(ctx, args->output + len, &outlen))
        handleErrors();
    args->outlen += outlen;

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    pthread_exit(NULL);
}

void encryption(unsigned char *plaintext, int plaintext_len, unsigned char *key, unsigned char *iv, unsigned char *ciphertext, int *ciphertext_len)
{
    pthread_t threads[MAX_THREADS];
    thread_args t_args[MAX_THREADS];

    int block_size = plaintext_len / MAX_THREADS;

    for (int i = 0; i < MAX_THREADS; i++) {
        t_args[i].tid = i;
        t_args[i].input = plaintext + (i * block_size);
        t_args[i].output = ciphertext + (i * block_size);
        t_args[i].key = key;
        t_args[i].iv = iv;
        t_args[i].len = block_size;
        t_args[i].outlen = 0;

        pthread_create(&threads[i], NULL, (void*)encryption_worker, &t_args[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
        *ciphertext_len += t_args[i].outlen;
    }
}

int main(int argc, char *argv[])
{
    // Initializing OpenSSL
    OpenSSL_add_all_algorithms();

    // Plaintext
    unsigned char *plaintext = (unsigned char *)"This is a test file that will be encrypted using OpenSSL AES-256 CBC algorithm with multiple threads.";
    int plaintext_len = strlen((char *)plaintext);
    printf("Plaintext:\n%s\n\n", plaintext);

    // Key and IV
    unsigned char key[EVP_MAX_KEY_LENGTH], iv[EVP_MAX_IV_LENGTH];
    RAND_bytes(key, 32);
    RAND_bytes(iv, 16);

    // Ciphertext
    unsigned char ciphertext[MAX_THREADS * BLOCK_SIZE];
    memset(ciphertext, 0, MAX_THREADS * BLOCK_SIZE);
    int ciphertext_len = 0;

    // Encryption
    encryption(plaintext, plaintext_len, key, iv, ciphertext, &ciphertext_len);

    printf("Ciphertext:\n");
    for (int i = 0; i < ciphertext_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    // Clean up OpenSSL
    EVP_cleanup();
    ERR_free_strings();

    return 0;
}