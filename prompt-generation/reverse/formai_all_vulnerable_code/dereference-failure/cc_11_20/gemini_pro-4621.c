//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main(int argc, char **argv) {
    int rc = 0;
    EVP_PKEY *pkey = NULL;
    EVP_CIPHER_CTX *ctx = NULL;
    EVP_MD_CTX *md = NULL;
    unsigned char *in = NULL, *out = NULL, *hash = NULL;
    unsigned int inlen, outlen, hashlen;
    FILE *fp = NULL;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    inlen = fread(in, 1, 256, fp);
    fclose(fp);

    if (!inlen) {
        fprintf(stderr, "Error reading input file\n");
        return 1;
    }

    pkey = EVP_PKEY_new();
    if (pkey == NULL) {
        fprintf(stderr, "EVP_PKEY_new failed\n");
        return 1;
    }

    rc = EVP_PKEY_assign_RSA(pkey, RSA_new());
    if (rc != 1) {
        fprintf(stderr, "EVP_PKEY_assign_RSA failed\n");
        return 1;
    }

    ctx = EVP_CIPHER_CTX_new();
    if (ctx == NULL) {
        fprintf(stderr, "EVP_CIPHER_CTX_new failed\n");
        return 1;
    }

    rc = EVP_EncryptInit_ex(ctx, EVP_des_ede3_cbc(), NULL, NULL, NULL);
    if (rc != 1) {
        fprintf(stderr, "EVP_EncryptInit_ex failed\n");
        return 1;
    }

    rc = EVP_EncryptUpdate(ctx, out, &outlen, in, inlen);
    if (rc != 1) {
        fprintf(stderr, "EVP_EncryptUpdate failed\n");
        return 1;
    }

    rc = EVP_EncryptFinal_ex(ctx, out + outlen, &hashlen);
    if (rc != 1) {
        fprintf(stderr, "EVP_EncryptFinal_ex failed\n");
        return 1;
    }

    hashlen += outlen;

    md = EVP_MD_CTX_new();
    if (md == NULL) {
        fprintf(stderr, "EVP_MD_CTX_new failed\n");
        return 1;
    }

    rc = EVP_DigestInit_ex(md, EVP_sha1(), NULL);
    if (rc != 1) {
        fprintf(stderr, "EVP_DigestInit_ex failed\n");
        return 1;
    }

    rc = EVP_DigestUpdate(md, out, hashlen);
    if (rc != 1) {
        fprintf(stderr, "EVP_DigestUpdate failed\n");
        return 1;
    }

    rc = EVP_DigestFinal_ex(md, hash, &hashlen);
    if (rc != 1) {
        fprintf(stderr, "EVP_DigestFinal_ex failed\n");
        return 1;
    }

    fp = fopen(argv[2], "wb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    fwrite(out, 1, hashlen, fp);
    fclose(fp);

    EVP_PKEY_free(pkey);
    EVP_CIPHER_CTX_free(ctx);
    EVP_MD_CTX_free(md);
    free(in);
    free(out);
    free(hash);

    return 0;
}