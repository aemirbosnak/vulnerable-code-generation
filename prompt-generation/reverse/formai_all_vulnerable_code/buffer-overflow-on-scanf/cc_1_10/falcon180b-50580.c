//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_SIZE 32

void hash(char *input, char *output) {
    char hex_chars[] = "0123456789abcdef";
    int i, j, len = strlen(input);
    unsigned char hash_value[HASH_SIZE];
    unsigned char *ptr;

    for (i = 0; i < len; i++) {
        input[i] = tolower(input[i]);
    }

    for (i = 0; i < len; i++) {
        hash_value[i] = input[i];
    }

    for (i = len; i < HASH_SIZE; i++) {
        hash_value[i] = 0;
    }

    for (i = 0; i < HASH_SIZE; i++) {
        for (j = 0; j < HASH_SIZE; j++) {
            if (hash_value[i] == hash_value[j]) {
                hash_value[i] = 0;
            }
        }
    }

    ptr = (unsigned char *)output;
    for (i = 0; i < HASH_SIZE; i++) {
        sprintf(ptr, "%02x", hash_value[i]);
        ptr += 2;
    }
}

int main() {
    char input[100], output[100];

    printf("Enter input string: ");
    scanf("%s", input);

    hash(input, output);

    printf("Input string: %s\n", input);
    printf("Hash value: %s\n", output);

    return 0;
}