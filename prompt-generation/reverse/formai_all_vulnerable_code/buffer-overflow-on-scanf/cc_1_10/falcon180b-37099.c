//Falcon-180B DATASET v1.0 Category: Password management ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASSWORD_LEN 64
#define HASH_LEN 32

typedef struct {
    char *username;
    char *password;
    char *salt;
} user_t;

void generate_salt(char *salt) {
    for (int i = 0; i < HASH_LEN; i++) {
        char c = rand() % 26 + 'a';
        salt[i] = c;
    }
    salt[HASH_LEN] = '\0';
}

char *hash_password(char *password, char *salt) {
    char *hashed_password = malloc(HASH_LEN + 1);
    char *key = password;
    int index = 0;

    while (*key) {
        char c = *key;
        int i = 0;

        if (c >= 'A' && c <= 'Z') {
            i = c - 'A';
        } else if (c >= 'a' && c <= 'z') {
            i = c - 'a';
        } else if (c >= '0' && c <= '9') {
            i = c - '0';
        } else {
            i = 0;
        }

        hashed_password[index] = salt[i];
        index++;
        key++;
    }

    hashed_password[index] = '\0';
    return hashed_password;
}

void read_user(user_t *user) {
    printf("Enter username: ");
    scanf("%s", user->username);

    printf("Enter password: ");
    scanf("%s", user->password);

    generate_salt(user->salt);
    user->password = hash_password(user->password, user->salt);
}

void write_user(user_t *user) {
    printf("User: %s\n", user->username);
    printf("Password: %s\n", user->password);
    printf("Salt: %s\n", user->salt);
}

void main() {
    user_t user;

    read_user(&user);
    write_user(&user);

    free(user.password);
    free(user.salt);
}