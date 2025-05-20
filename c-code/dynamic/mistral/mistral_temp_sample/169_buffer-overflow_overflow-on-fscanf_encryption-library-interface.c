#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_KEY_LENGTH 10

void encrypt(char *key) {
    char encrypted[100];
    strcpy(encrypted, "Encrypted: ");
    strcat(encrypted, key);
    printf("%s\n", encrypted);
}

int main(int argc, char *argv[]) {
    char key[MAX_KEY_LENGTH];

    if (argc != 2) {
        printf("Usage: %s <key>\n", argv[0]);
        return 1;
    }

    fscanf(stdin, "%s", key);
    encrypt(key);

    return 0;
}
