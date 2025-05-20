//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_LENGTH 32

typedef struct {
    char username[20];
    char password[20];
    char salt[20];
} User;

void generateSalt(User *user) {
    char saltChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int saltLength = strlen(saltChars);

    srand(time(NULL));

    for (int i = 0; i < strlen(user->username) + strlen(user->password); i++) {
        int randIndex = rand() % saltLength;
        user->salt[i] = saltChars[randIndex];
    }
}

void hashPassword(User *user, char *hash) {
    char saltAndPassword[strlen(user->salt) + strlen(user->password)];
    strcat(saltAndPassword, user->salt);
    strcat(saltAndPassword, user->password);

    char md5Hash[33];
    MD5((unsigned char *)saltAndPassword, strlen(saltAndPassword), (unsigned char *)md5Hash);

    strncpy(hash, md5Hash, HASH_LENGTH);
}

int main() {
    User user;
    char hash[HASH_LENGTH];

    printf("Enter username: ");
    scanf("%s", user.username);

    printf("Enter password: ");
    scanf("%s", user.password);

    generateSalt(&user);

    hashPassword(&user, hash);

    printf("Username: %s\n", user.username);
    printf("Salt: %s\n", user.salt);
    printf("Password: %s\n", user.password);
    printf("Hash: %s\n", hash);

    return 0;
}