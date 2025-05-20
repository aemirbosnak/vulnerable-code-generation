//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_SIZE 32
#define SALT_SIZE 16

typedef struct {
    char salt[SALT_SIZE];
    char hash[HASH_SIZE];
} Hash;

void generate_salt(char *salt) {
    time_t now = time(NULL);
    srand(now);
    for (int i = 0; i < SALT_SIZE; i++) {
        salt[i] = rand() % 62 + 'a';
    }
    salt[SALT_SIZE - 1] = '\0';
}

void generate_hash(const char *password, const char *salt, char *hash) {
    char *p = (char *)password;
    char *s = (char *)salt;
    char *h = (char *)hash;
    int len = strlen(password);
    int salt_len = strlen(salt);
    int i, j;
    for (i = 0; i < len; i++) {
        p[i] = tolower(p[i]);
    }
    for (i = 0; i < salt_len; i++) {
        s[i] = tolower(s[i]);
    }
    for (i = 0; i < len; i++) {
        for (j = 0; j < salt_len; j++) {
            h[i * salt_len + j] = (p[i] + s[j]) % 62 + 'a';
        }
    }
    h[len * salt_len - 1] = '\0';
}

int main() {
    Hash hash;
    char password[100];
    char salt[SALT_SIZE];

    printf("Enter the password to hash: ");
    scanf("%s", password);

    generate_salt(salt);
    generate_hash(password, salt, hash.hash);
    strcpy(hash.salt, salt);

    printf("Salt: %s\n", hash.salt);
    printf("Hash: %s\n", hash.hash);

    return 0;
}