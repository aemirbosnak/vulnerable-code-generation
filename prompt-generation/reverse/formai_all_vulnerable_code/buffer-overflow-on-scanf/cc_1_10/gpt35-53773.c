//FormAI DATASET v1.0 Category: Cryptographic hash fucntionPassword management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_PASS_LEN 20
#define HASH_LEN SHA256_DIGEST_LENGTH

typedef struct {
    char name[25];
    unsigned char hash[HASH_LEN];
} user;

void hash_password(char password[], unsigned char hash[]) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, password, strlen(password));
    SHA256_Final(hash, &ctx);
}

int authenticate_user(user *users, int num_users, char name[], char password[]) {
    unsigned char hash[HASH_LEN];
    hash_password(password, hash);

    for (int i = 0; i < num_users; i++) {
        if (strcmp(name, users[i].name) == 0 && memcmp(hash, users[i].hash, HASH_LEN) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    user users[3] = {"Alice", "", "Bob", "", "Charlie", ""};

    char password[MAX_PASS_LEN];
    printf("Enter password for Alice: ");
    scanf("%s", password);
    hash_password(password, users[0].hash);

    printf("Enter password for Bob: ");
    scanf("%s", password);
    hash_password(password, users[1].hash);

    printf("Enter password for Charlie: ");
    scanf("%s", password);
    hash_password(password, users[2].hash);

    char name[25];
    printf("Enter name to authenticate: ");
    scanf("%s", name);

    printf("Enter password to authenticate: ");
    scanf("%s", password);

    if (authenticate_user(users, 3, name, password)) {
        printf("Authentication successful!\n");
    }
    else {
        printf("Authentication failed.\n");
    }

    return 0;
}