//Falcon-180B DATASET v1.0 Category: Password management ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>

#define PASSWORD_LENGTH 64
#define SALT_LENGTH 32
#define HASH_LENGTH SHA512_DIGEST_LENGTH
#define MAX_USERNAME_LENGTH 32

typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[PASSWORD_LENGTH];
    char salt[SALT_LENGTH];
} User;

void generate_salt(char *salt) {
    int i;
    for (i = 0; i < SALT_LENGTH; i++) {
        salt[i] = 'A' + rand() % 26;
    }
    salt[SALT_LENGTH - 1] = '\0';
}

void hash_password(User *user) {
    SHA512_CTX ctx;
    unsigned char digest[SHA512_DIGEST_LENGTH];
    SHA512_Init(&ctx);
    SHA512_Update(&ctx, user->password, strlen(user->password));
    SHA512_Update(&ctx, user->salt, strlen(user->salt));
    SHA512_Final(digest, &ctx);
    memcpy(user->password, digest, HASH_LENGTH);
}

int main() {
    User user;
    char salt[SALT_LENGTH];

    // Initialize random seed
    srand(time(NULL));

    // Generate salt
    generate_salt(salt);

    // Create username
    printf("Enter username: ");
    scanf("%s", user.username);

    // Create password
    printf("Enter password: ");
    scanf("%s", user.password);

    // Hash password
    hash_password(&user);

    // Store user data
    FILE *file = fopen("users.dat", "a");
    fprintf(file, "%s|%s|%s\n", user.username, user.salt, user.password);
    fclose(file);

    return 0;
}