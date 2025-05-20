//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define HASH_LENGTH 64
#define SALT_LENGTH 16

void generate_salt(char *salt) {
    const char alphanum[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < SALT_LENGTH; i++) {
        salt[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    salt[SALT_LENGTH - 1] = '\0';
}

void hash(const char *input, const char *salt, char *output) {
    const char alphanum[] = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char hash_input[HASH_LENGTH + strlen(input) + 1];
    strcpy(hash_input, salt);
    strcat(hash_input, input);

    for (int i = 0; i < strlen(hash_input); i++) {
        hash_input[i] = toupper(hash_input[i]);
    }

    unsigned int hash = 0;
    for (int i = 0; i < strlen(hash_input); i++) {
        hash = (hash << 6) + (hash_input[i] - '0');
    }

    sprintf(output, "%08x", hash);
}

int main() {
    char salt[SALT_LENGTH];
    generate_salt(salt);

    char input[100];
    printf("Enter input: ");
    scanf("%s", input);

    char output[HASH_LENGTH];
    hash(input, salt, output);

    printf("Input: %s\n", input);
    printf("Salt: %s\n", salt);
    printf("Hash: %s\n", output);

    return 0;
}