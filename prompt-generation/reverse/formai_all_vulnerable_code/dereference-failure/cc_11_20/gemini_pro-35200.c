//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/err.h>

int main(int argc, char **argv)
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s encrypt|decrypt keyfile infile outfile\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *mode = argv[1];
    const char *keyfile = argv[2];
    const char *infile = argv[3];
    const char *outfile = argv[4];

    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }

    FILE *key = fopen(keyfile, "rb");
    if (!key) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    unsigned char keybuf[EVP_MAX_KEY_LENGTH];
    size_t keylen = fread(keybuf, 1, EVP_MAX_KEY_LENGTH, key);
    fclose(key);

    if (keylen == 0) {
        fprintf(stderr, "Error: empty key file\n");
        return EXIT_FAILURE;
    }

    FILE *in = fopen(infile, "rb");
    if (!in) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    FILE *out = fopen(outfile, "wb");
    if (!out) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    if (!strcmp(mode, "encrypt")) {
        EVP_EncryptInit_ex(ctx, EVP_aes_256_cfb(), NULL, keybuf, keylen);
    } else if (!strcmp(mode, "decrypt")) {
        EVP_DecryptInit_ex(ctx, EVP_aes_256_cfb(), NULL, keybuf, keylen);
    } else {
        fprintf(stderr, "Error: invalid mode '%s'\n", mode);
        return EXIT_FAILURE;
    }

    unsigned char inbuf[4096];
    unsigned char outbuf[4096 + EVP_MAX_BLOCK_LENGTH];

    size_t inlen;
    int outlen;

    while ((inlen = fread(inbuf, 1, sizeof(inbuf), in)) > 0) {
        if (!EVP_EncryptUpdate(ctx, outbuf, &outlen, inbuf, inlen)) {
            ERR_print_errors_fp(stderr);
            return EXIT_FAILURE;
        }

        fwrite(outbuf, 1, outlen, out);
    }

    if (!EVP_EncryptFinal_ex(ctx, outbuf, &outlen)) {
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }

    fwrite(outbuf, 1, outlen, out);

    EVP_CIPHER_CTX_free(ctx);
    fclose(in);
    fclose(out);

    return EXIT_SUCCESS;
}