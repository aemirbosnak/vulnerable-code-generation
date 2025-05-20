//Falcon-180B DATASET v1.0 Category: Password management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>

#define MAX_PASSWORD_LEN 64
#define SALT_LEN 32
#define DIGEST_LEN SHA256_DIGEST_LENGTH

typedef struct {
    char password[MAX_PASSWORD_LEN];
    char salt[SALT_LEN];
} password_t;

void generate_salt(char *salt) {
    int i;
    for (i = 0; i < SALT_LEN; i++) {
        salt[i] = 'a' + rand() % 26;
    }
    salt[SALT_LEN - 1] = '\0';
}

void hash_password(password_t *password, char *salt) {
    unsigned char digest[DIGEST_LEN];
    SHA256(password->password, strlen(password->password), digest);
    sprintf(password->salt, "%s%s", salt, digest);
}

int verify_password(password_t *password, char *salt) {
    unsigned char digest[DIGEST_LEN];
    SHA256(password->password, strlen(password->password), digest);
    return strcmp(password->salt, salt) == 0 && memcmp(digest, password->salt + SALT_LEN, DIGEST_LEN) == 0;
}

int main() {
    password_t password;
    char salt[SALT_LEN];

    generate_salt(salt);
    printf("Enter password: ");
    scanf("%s", password.password);
    hash_password(&password, salt);
    printf("Salt: %s\n", salt);
    printf("Hashed password: %s\n", password.salt);

    int verified = verify_password(&password, salt);
    if (verified) {
        printf("Password verified\n");
    } else {
        printf("Password not verified\n");
    }

    return 0;
}