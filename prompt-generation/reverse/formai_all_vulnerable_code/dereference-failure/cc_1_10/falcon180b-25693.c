//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_KEY_SIZE 256
#define MAX_FILE_SIZE 1024*1024*100

typedef struct {
    char key[MAX_KEY_SIZE];
    int key_size;
    FILE *file;
} cipher_ctx;

void init_cipher_ctx(cipher_ctx *ctx, char *key) {
    strncpy(ctx->key, key, MAX_KEY_SIZE);
    ctx->key_size = strlen(ctx->key);
    ctx->file = NULL;
}

void encrypt_file(cipher_ctx *ctx, char *input_file, char *output_file) {
    FILE *in_file, *out_file;
    char in_buffer[MAX_FILE_SIZE], out_buffer[MAX_FILE_SIZE];
    int in_len, out_len, i;

    in_file = fopen(input_file, "rb");
    if (in_file == NULL) {
        printf("Error opening input file: %s\n", input_file);
        exit(1);
    }

    out_file = fopen(output_file, "wb");
    if (out_file == NULL) {
        printf("Error opening output file: %s\n", output_file);
        exit(1);
    }

    while ((in_len = fread(in_buffer, 1, MAX_FILE_SIZE, in_file)) > 0) {
        for (i = 0; i < in_len; i++) {
            in_buffer[i] ^= ctx->key[i % ctx->key_size];
        }
        fwrite(in_buffer, 1, in_len, out_file);
    }

    fclose(in_file);
    fclose(out_file);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input_file> <output_file> <key>\n", argv[0]);
        return 1;
    }

    cipher_ctx ctx;
    init_cipher_ctx(&ctx, argv[3]);

    encrypt_file(&ctx, argv[1], argv[2]);

    return 0;
}