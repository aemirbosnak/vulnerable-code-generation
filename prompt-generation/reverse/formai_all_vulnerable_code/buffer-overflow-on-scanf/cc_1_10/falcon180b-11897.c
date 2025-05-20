//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <openssl/hmac.h>

#define HASH_LENGTH 64
#define SALT_LENGTH 16

typedef struct {
    char salt[SALT_LENGTH];
    char hash[HASH_LENGTH];
} hash_t;

void generate_salt(char* salt) {
    for (int i = 0; i < SALT_LENGTH; i++) {
        salt[i] = 'a' + rand() % 26;
    }
    salt[SALT_LENGTH - 1] = '\0';
}

void hash_password(const char* password, hash_t* hash) {
    char salt[SALT_LENGTH];
    generate_salt(salt);
    strcpy(hash->salt, salt);

    unsigned char digest[HASH_LENGTH];
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, password, strlen(password));
    SHA256_Update(&ctx, salt, SALT_LENGTH);
    SHA256_Final(digest, &ctx);

    for (int i = 0; i < HASH_LENGTH; i++) {
        sprintf(&hash->hash[i * 2], "%02x", digest[i]);
    }
    hash->hash[HASH_LENGTH * 2] = '\0';
}

int main() {
    hash_t hash;
    char password[100];

    printf("Enter password: ");
    scanf("%s", password);

    hash_password(password, &hash);

    printf("Salt: %s\n", hash.salt);
    printf("Hash: %s\n", hash.hash);

    return 0;
}