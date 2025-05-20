//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_SIZE 32
#define MAX_PASS_LENGTH 64

typedef struct {
    char pass[MAX_PASS_LENGTH];
    char salt[HASH_SIZE];
    char hash[HASH_SIZE];
} hash_t;

void generate_salt(hash_t *hash) {
    int i;
    for (i = 0; i < HASH_SIZE; i++) {
        hash->salt[i] = rand() % 256;
    }
}

void generate_hash(hash_t *hash) {
    char *pass = hash->pass;
    char *salt = hash->salt;
    char *hash_str = hash->hash;
    int i, j, k;
    for (i = 0; i < HASH_SIZE; i++) {
        hash_str[i] = 0;
    }
    for (i = 0; i < MAX_PASS_LENGTH && pass[i]!= 0; i++) {
        for (j = 0; j < HASH_SIZE && salt[j]!= 0; j++) {
            hash_str[j] ^= pass[i] ^ salt[j];
        }
    }
    for (i = 0; i < HASH_SIZE; i++) {
        hash_str[i] = hash_str[i] % 256;
    }
}

void print_hash(hash_t *hash) {
    int i;
    for (i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash->hash[i]);
    }
    printf("\n");
}

int main() {
    hash_t hash;
    char pass[MAX_PASS_LENGTH];
    printf("Enter password: ");
    scanf("%s", pass);
    strncpy(hash.pass, pass, MAX_PASS_LENGTH);
    generate_salt(&hash);
    generate_hash(&hash);
    print_hash(&hash);
    return 0;
}