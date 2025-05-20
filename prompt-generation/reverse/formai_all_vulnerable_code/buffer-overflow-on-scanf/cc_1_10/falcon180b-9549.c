//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_LENGTH 32

typedef struct {
    char *input_string;
    unsigned char hash[HASH_LENGTH];
} Hash;

void hash_string(Hash *hash) {
    unsigned int i, j, k;
    unsigned char temp[HASH_LENGTH];
    char *input_string = hash->input_string;
    unsigned char *hash_value = hash->hash;

    for (i = 0; i < strlen(input_string); i++) {
        input_string[i] = tolower(input_string[i]);
    }

    for (i = 0; i < strlen(input_string); i++) {
        temp[i] = input_string[i];
    }

    for (i = 0; i < strlen(input_string); i++) {
        for (j = 0; j < strlen(input_string); j++) {
            k = (i * j) % strlen(input_string);
            hash_value[k] = temp[i] ^ temp[j];
        }
    }
}

int main() {
    char input_string[100];
    Hash hash;

    printf("Enter a string: ");
    scanf("%s", input_string);

    hash.input_string = input_string;
    hash_string(&hash);

    printf("Hash: ");
    for (int i = 0; i < HASH_LENGTH; i++) {
        printf("%02X", hash.hash[i]);
    }

    return 0;
}