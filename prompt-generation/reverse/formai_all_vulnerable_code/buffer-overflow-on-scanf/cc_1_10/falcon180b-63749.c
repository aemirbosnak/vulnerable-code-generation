//Falcon-180B DATASET v1.0 Category: Password management ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#define PASSWORD_LENGTH 32
#define SALT_LENGTH 16
#define HASH_LENGTH 64
#define ITERATIONS 10000

typedef struct {
    char username[64];
    char password[PASSWORD_LENGTH];
    char salt[SALT_LENGTH];
    char hash[HASH_LENGTH];
} User;

void generate_salt(char *salt) {
    for (int i = 0; i < SALT_LENGTH; i++) {
        salt[i] = 'a' + rand() % 26;
    }
    salt[SALT_LENGTH - 1] = '\0';
}

void generate_hash(char *hash, char *password, char *salt) {
    char *buffer = malloc(PASSWORD_LENGTH + SALT_LENGTH);
    strcat(buffer, password);
    strcat(buffer, salt);

    char *result = malloc(HASH_LENGTH + 1);
    char *c = result;
    for (int i = 0; i < ITERATIONS; i++) {
        for (int j = 0; j < strlen(buffer); j++) {
            *c = buffer[j];
            c++;
        }
    }
    *c = '\0';

    strcpy(hash, result);
    free(buffer);
    free(result);
}

int main() {
    srand(time(NULL));
    User user;

    printf("Enter a username: ");
    scanf("%s", user.username);

    printf("Enter a password: ");
    scanf("%s", user.password);

    generate_salt(user.salt);
    generate_hash(user.hash, user.password, user.salt);

    printf("Username: %s\n", user.username);
    printf("Password: %s\n", user.hash);

    return 0;
}