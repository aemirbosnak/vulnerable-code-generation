#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_KEY_LENGTH 100

void encrypt(char* key) {
    char encrypted[200];

    for (int i = 0; i < strlen(key); i++) {
        encrypted[i] = key[i] + 3;
    }

    printf("Encrypted: %s\n", encrypted);
}

int main(int argc, char* argv[]) {
    char key[MAX_KEY_LENGTH];

    if (argc != 2) {
        printf("Usage: %s <key>\n", argv[0]);
        return 1;
    }

    fscanf(stdin, "%s", key);

    encrypt(key);

    return 0;
}
