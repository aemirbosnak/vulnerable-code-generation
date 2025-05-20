//Falcon-180B DATASET v1.0 Category: Password management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>

#define PASSWORD_LENGTH 20
#define SALT_LENGTH 16
#define ITERATIONS 100000

typedef struct {
    char password[PASSWORD_LENGTH];
    char salt[SALT_LENGTH];
} password_t;

char *generate_salt() {
    char salt[SALT_LENGTH];
    for (int i = 0; i < SALT_LENGTH; i++) {
        salt[i] = 'a' + rand() % 26;
    }
    return strdup(salt);
}

void hash_password(password_t *password, char *salt) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, password->password, strlen(password->password));
    SHA256_Update(&ctx, salt, SALT_LENGTH);
    SHA256_Final(password->password, &ctx);
}

int verify_password(password_t *password, char *salt, char *attempt) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, attempt, strlen(attempt));
    SHA256_Update(&ctx, salt, SALT_LENGTH);
    SHA256_Final(password->password, &ctx);
    return strcmp(password->password, attempt) == 0;
}

void main() {
    srand(time(NULL));
    password_t password;
    char *salt = generate_salt();
    hash_password(&password, salt);
    printf("Password: %s\n", password.password);
    printf("Salt: %s\n", salt);

    char input[PASSWORD_LENGTH];
    printf("Enter password to verify: ");
    scanf("%s", input);

    if (verify_password(&password, salt, input)) {
        printf("Password verified\n");
    } else {
        printf("Incorrect password\n");
    }
}