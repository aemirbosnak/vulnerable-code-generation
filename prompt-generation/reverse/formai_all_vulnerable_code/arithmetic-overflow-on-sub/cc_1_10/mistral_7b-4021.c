//MISTRAL-7B DATASET v1.0 Category: Cryptographic hash function ; Style: peaceful
#include <openssl/sha.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <ctype.h>
#include <time.h>

#define HASH_SIZE SHA256_DIGEST_LENGTH
#define BUFFER_SIZE 1024

typedef struct hash_context {
    unsigned char hash[HASH_SIZE];
    SHA256_CTX sha256;
} hash_context;

void my_hash_init(hash_context *ctx) {
    SHA256_Init(&ctx->sha256);
}

void my_hash_update(hash_context *ctx, const void *data, size_t len) {
    SHA256_Update(&ctx->sha256, data, len);
}

void my_hash_finalize(hash_context *ctx, unsigned char output[HASH_SIZE]) {
    SHA256_Final(output, &ctx->sha256);
}

void print_hash(unsigned char hash[HASH_SIZE]) {
    int i;
    printf("\033[1;34m[*] Starry Night Hash:\n");
    for (i = 0; i < HASH_SIZE; i++) {
        printf("\033[1;32m[%2d] %02X\n", i, hash[i]);
    }
}

void hash_file(const char *filename) {
    hash_context ctx;
    FILE *file;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    my_hash_init(&ctx);

    file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        my_hash_update(&ctx, buffer, bytes_read);
    }

    fclose(file);

    unsigned char hash[HASH_SIZE];
    my_hash_finalize(&ctx, hash);

    printf("\033[1;36m[*] File hashed successfully:\n");
    print_hash(hash);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    clock_t start = clock();
    hash_file(argv[1]);
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\033[1;35m[*] Hash computation took %.2f seconds.\n", time_taken);

    return EXIT_SUCCESS;
}