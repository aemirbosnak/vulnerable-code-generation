#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

// Pseudo-library for Encryption

#define MAX_KEY_LEN 10

void encrypt(char *input, char *key) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        input[i] = input[i] + key[i % MAX_KEY_LEN];
    }
}

int main(int argc, char *argv[]) {
    char input[100];
    char key[MAX_KEY_LEN];

    if (argc != 3) {
        printf("Usage: %s <input> <key>\n", argv[0]);
        return 1;
    }

    strcpy(input, argv[1]);
    strcpy(key, argv[2]);

    encrypt(input, key);

    printf("Encrypted Message: %s\n", input);

    // OOB Read vulnerability
    printf("First 10 bytes of the key: %.*s\n", 11, key);

    return 0;
}
