//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HASH_SIZE 32

void hash(char* message, char* digest) {
    int i, j, k;
    char temp;
    int hash_val[HASH_SIZE];
    int message_len = strlen(message);

    // Initializing hash value array with 0s
    for (i = 0; i < HASH_SIZE; i++) {
        hash_val[i] = 0;
    }

    // Iterating through the message and updating hash value
    for (i = 0; i < message_len; i++) {
        hash_val[i % HASH_SIZE] += message[i];
    }

    // Computing final hash value
    for (i = 0; i < HASH_SIZE; i++) {
        hash_val[i] = hash_val[i] % 256;
    }

    // Converting hash value to hexadecimal
    for (i = 0; i < HASH_SIZE; i++) {
        if (hash_val[i] < 16) {
            sprintf(&digest[i * 2], "0%x", hash_val[i]);
        } else {
            sprintf(&digest[i * 2], "%x", hash_val[i]);
        }
    }
}

int main() {
    char message[100];
    char digest[HASH_SIZE * 2];

    printf("Enter message to hash: ");
    scanf("%s", message);

    hash(message, digest);

    printf("Hash value: %s\n", digest);

    return 0;
}