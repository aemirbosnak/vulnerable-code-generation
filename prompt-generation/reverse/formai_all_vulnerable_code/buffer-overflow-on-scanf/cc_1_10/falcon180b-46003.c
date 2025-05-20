//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>

#define HASH_SIZE 64
#define HASH_ALGORITHM "SHA256"

void hash_file(const char *filename, unsigned char *hash) {
    FILE *file;
    SHA256_CTX ctx;
    unsigned char buffer[4096];
    size_t bytes_read;

    if ((file = fopen(filename, "rb")) == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    SHA256_Init(&ctx);
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        SHA256_Update(&ctx, buffer, bytes_read);
    }
    SHA256_Final(hash, &ctx);

    fclose(file);
}

void hash_string(const char *string, unsigned char *hash) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, string, strlen(string));
    SHA256_Final(hash, &ctx);
}

int main() {
    char filename[256];
    char string[256];
    unsigned char hash[HASH_SIZE];

    printf("Enter filename to hash: ");
    scanf("%s", filename);
    hash_file(filename, hash);

    printf("SHA256 hash of file %s: ", filename);
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    printf("Enter string to hash: ");
    scanf("%s", string);
    hash_string(string, hash);

    printf("SHA256 hash of string %s: ", string);
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}