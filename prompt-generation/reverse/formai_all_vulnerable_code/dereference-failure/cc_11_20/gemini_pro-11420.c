//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/err.h>

#define ENCRYPT 1
#define DECRYPT 0

int main(int argc, char **argv)
{
    int operation = ENCRYPT;
    unsigned char *key = NULL;
    unsigned char *iv = NULL;
    unsigned char *input = NULL;
    unsigned char *output = NULL;
    int input_len = 0;
    int output_len = 0;
    int key_len = 0;
    int iv_len = 0;

    // Parse command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [encrypt|decrypt] [key] [iv] [input] [output]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (!strcmp(argv[1], "encrypt")) {
        operation = ENCRYPT;
    } else if (!strcmp(argv[1], "decrypt")) {
        operation = DECRYPT;
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Read the key
    key_len = strlen(argv[2]);
    key = malloc(key_len + 1);
    strcpy(key, argv[2]);

    // Read the IV
    iv_len = strlen(argv[3]);
    iv = malloc(iv_len + 1);
    strcpy(iv, argv[3]);

    // Read the input
    FILE *fp = fopen(argv[4], "rb");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    input_len = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    input = malloc(input_len);
    fread(input, 1, input_len, fp);
    fclose(fp);

    // Create a context for the cipher
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Initialize the context
    if (operation == ENCRYPT) {
        if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
            ERR_print_errors_fp(stderr);
            exit(EXIT_FAILURE);
        }
    } else if (operation == DECRYPT) {
        if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) {
            ERR_print_errors_fp(stderr);
            exit(EXIT_FAILURE);
        }
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Update the context
    if (EVP_CipherUpdate(ctx, NULL, &output_len, input, input_len) != 1) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Finalize the context
    output = malloc(output_len);
    if (EVP_CipherFinal_ex(ctx, output, &output_len) != 1) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    // Clean up
    EVP_CIPHER_CTX_free(ctx);
    free(key);
    free(iv);
    free(input);
    free(output);

    // Write the output
    fp = fopen(argv[5], "wb");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fwrite(output, 1, output_len, fp);
    fclose(fp);

    return EXIT_SUCCESS;
}