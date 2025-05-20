//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_LENGTH 64

typedef struct {
    int length;
    unsigned char hash[HASH_LENGTH];
} hash_t;

void hash_init(hash_t* hash) {
    hash->length = 0;
    memset(hash->hash, 0, HASH_LENGTH);
}

void hash_update(hash_t* hash, const unsigned char* data, int length) {
    hash->length += length;
    for (int i = 0; i < length; i++) {
        hash->hash[hash->length % HASH_LENGTH] ^= data[i];
    }
}

void hash_final(hash_t* hash, unsigned char* digest) {
    int pad_length = HASH_LENGTH - (hash->length % HASH_LENGTH);
    hash_update(hash, (const unsigned char*)"\200", pad_length);
    hash_update(hash, (const unsigned char*)&hash->length, sizeof(hash->length));
    for (int i = 0; i < HASH_LENGTH; i++) {
        sprintf(&digest[i*2], "%02x", hash->hash[i]);
    }
}

int main() {
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    char timestamp[64];
    strftime(timestamp, sizeof(timestamp), "%Y%m%d%H%M%S", tm);

    hash_t hash;
    hash_init(&hash);

    FILE* file = fopen("input.txt", "rb");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    unsigned char buffer[4096];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        hash_update(&hash, buffer, bytes_read);
    }

    unsigned char digest[HASH_LENGTH*2+1];
    hash_final(&hash, digest);

    printf("Hash of file 'input.txt' at %s:\n", timestamp);
    for (int i = 0; i < HASH_LENGTH*2; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    fclose(file);

    return 0;
}