//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <openssl/md5.h>

#define HASH_SIZE 16

unsigned char *hash(unsigned char *data, int size) {
    unsigned char *hash_value = (unsigned char *) malloc(HASH_SIZE * sizeof(unsigned char));
    unsigned char *hash_data = (unsigned char *) malloc((size + 1) * sizeof(unsigned char));
    memset(hash_data, 0, size + 1);
    memcpy(hash_data, data, size);
    MD5((unsigned char *) hash_data, size + 1, hash_value);
    free(hash_data);
    return hash_value;
}

unsigned char *hash_recursive(unsigned char *data, int size) {
    if (size == 0) {
        return NULL;
    } else if (size == 1) {
        unsigned char *hash_value = (unsigned char *) malloc(HASH_SIZE * sizeof(unsigned char));
        memset(hash_value, 0, HASH_SIZE);
        MD5((unsigned char *) data, 1, hash_value);
        return hash_value;
    } else {
        int half = size / 2;
        unsigned char *left_hash = hash_recursive(data, half);
        unsigned char *right_hash = hash_recursive(data + half, size - half);
        unsigned char *hash_value = (unsigned char *) malloc(HASH_SIZE * sizeof(unsigned char));
        memset(hash_value, 0, HASH_SIZE);
        MD5((unsigned char *) left_hash, HASH_SIZE, hash_value);
        MD5((unsigned char *) right_hash, HASH_SIZE, hash_value);
        free(left_hash);
        free(right_hash);
        return hash_value;
    }
}

int main() {
    char *input = "Hello, World!";
    unsigned char *hash_value = hash(input, strlen(input));
    printf("Hash of input string: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash_value[i]);
    }
    printf("\n");
    unsigned char *recursive_hash_value = hash_recursive(input, strlen(input));
    printf("Recursive hash of input string: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", recursive_hash_value[i]);
    }
    printf("\n");
    return 0;
}