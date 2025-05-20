//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s [encrypt/decrypt] [input file] [output file]\n", argv[0]);
        return 1;
    }

    const char *algo = "aes-256-cbc";
    const char *key = "secretkey";
    const char *iv = "8D7AEB256B6AE1F1";

    int is_encrypt = 0;
    if (strcmp(argv[1], "encrypt") == 0) {
        is_encrypt = 1;
    } else if (strcmp(argv[1], "decrypt") != 0) {
        printf("Invalid operation: %s\n", argv[1]);
        return 1;
    }

    FILE *in_fp = fopen(argv[2], "rb");
    if (in_fp == NULL) {
        printf("Could not open input file: %s\n", argv[2]);
        return 1;
    }

    FILE *out_fp = fopen(argv[3], "wb");
    if (out_fp == NULL) {
        printf("Could not open output file: %s\n", argv[3]);
        fclose(in_fp);
        return 1;
    }

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        printf("Could not create context\n");
        fclose(in_fp);
        fclose(out_fp);
        return 1;
    }

    if (is_encrypt) {
        if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char*)key, (unsigned char*)iv) == 0) {
            printf("Could not initialize encryption\n");
            goto cleanup;
        }
    } else {
        if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, (unsigned char*)key, (unsigned char*)iv) == 0) {
            printf("Could not initialize decryption\n");
            goto cleanup;
        }
    }

    unsigned char in_buf[1024];
    unsigned char out_buf[1024 + EVP_MAX_BLOCK_LENGTH];
    int in_len, out_len;

    while ((in_len = fread(in_buf, 1, sizeof(in_buf), in_fp)) > 0) {
        if (is_encrypt) {
            if (EVP_EncryptUpdate(ctx, out_buf, &out_len, in_buf, in_len) == 0) {
                printf("Could not encrypt data\n");
                goto cleanup;
            }
            fwrite(out_buf, 1, out_len, out_fp);
        } else {
            if (EVP_DecryptUpdate(ctx, out_buf, &out_len, in_buf, in_len) == 0) {
                printf("Could not decrypt data\n");
                goto cleanup;
            }
            fwrite(out_buf, 1, out_len, out_fp);
        }
    }

    if (is_encrypt) {
        if (EVP_EncryptFinal_ex(ctx, out_buf, &out_len) == 0) {
            printf("Could not finalize encryption\n");
            goto cleanup;
        }
        fwrite(out_buf, 1, out_len, out_fp);
    } else {
        if (EVP_DecryptFinal_ex(ctx, out_buf, &out_len) == 0) {
            printf("Could not finalize decryption\n");
            goto cleanup;
        }
        fwrite(out_buf, 1, out_len, out_fp);
    }

    fclose(in_fp);
    fclose(out_fp);
    EVP_CIPHER_CTX_free(ctx);
    return 0;

cleanup:
    fclose(in_fp);
    fclose(out_fp);
    EVP_CIPHER_CTX_free(ctx);
    return 1;
}