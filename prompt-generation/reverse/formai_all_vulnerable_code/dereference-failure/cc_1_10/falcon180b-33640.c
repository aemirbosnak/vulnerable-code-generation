//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <openssl/md5.h>
#include <openssl/sha.h>

#define HASH_LENGTH 32
#define SALT_LENGTH 16
#define HASH_ALGORITHM "SHA256"

void generate_salt(char* salt) {
    char chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int salt_len = strlen(salt);
    for (int i = 0; i < salt_len; i++) {
        salt[i] = chars[rand() % 62];
    }
}

char* hash_password(char* password, char* salt) {
    unsigned char digest[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, password, strlen(password));
    SHA256_Update(&sha256, salt, strlen(salt));
    SHA256_Final(digest, &sha256);

    char* result = malloc(HASH_LENGTH + 1);
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(&result[i*2], "%02x", digest[i]);
    }
    result[SHA256_DIGEST_LENGTH*2] = '\0';

    return result;
}

int main() {
    char* password = "mypassword";
    char* salt = malloc(SALT_LENGTH + 1);
    generate_salt(salt);

    char* hashed_password = hash_password(password, salt);

    printf("Original password: %s\n", password);
    printf("Salt: %s\n", salt);
    printf("Hashed password: %s\n", hashed_password);

    free(salt);
    free(hashed_password);

    return 0;
}