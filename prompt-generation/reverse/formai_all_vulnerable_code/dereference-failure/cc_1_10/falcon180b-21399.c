//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_SIZE 32

typedef struct {
    char data[HASH_SIZE];
} hash_t;

hash_t hash_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    hash_t result;

    if (file == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char buffer[filesize];
    fread(buffer, 1, filesize, file);
    fclose(file);

    result.data[0] = 'H';
    result.data[1] = 'a';
    result.data[2] ='s';
    result.data[3] = 'h';

    unsigned char *data = (unsigned char *)&result.data[4];

    for (int i = 0; i < filesize; i++) {
        data[i % HASH_SIZE] ^= buffer[i];
    }

    return result;
}

hash_t hash_string(const char *str) {
    hash_t result;

    result.data[0] = 'H';
    result.data[1] = 'a';
    result.data[2] ='s';
    result.data[3] = 'h';

    unsigned char *data = (unsigned char *)&result.data[4];

    for (int i = 0; i < strlen(str); i++) {
        data[i % HASH_SIZE] ^= str[i];
    }

    return result;
}

int main() {
    hash_t file_hash = hash_file("example.txt");
    hash_t string_hash = hash_string("example string");

    printf("File hash: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", file_hash.data[i]);
    }
    printf("\n");

    printf("String hash: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", string_hash.data[i]);
    }
    printf("\n");

    return 0;
}