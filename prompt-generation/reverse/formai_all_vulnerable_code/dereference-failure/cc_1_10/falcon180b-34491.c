//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LEN 16
#define BLOCK_LEN 8
#define ROUNDS 10

void encrypt(char* plaintext, char* key, char* ciphertext) {
    int i, j;
    char* block = malloc(BLOCK_LEN + 1);
    char* state = malloc(KEY_LEN * BLOCK_LEN + 1);

    strcpy(state, key);
    for (i = 0; i < ROUNDS; i++) {
        for (j = 0; j < strlen(plaintext); j++) {
            strncat(state, plaintext + j, 1);
            strncat(state, key, KEY_LEN - j % KEY_LEN);
        }
        strncpy(plaintext, state, strlen(plaintext));
        memset(state, 0, strlen(state));
    }

    for (i = 0; i < strlen(plaintext); i += BLOCK_LEN) {
        strncpy(block, plaintext + i, BLOCK_LEN);
        for (j = 0; j < BLOCK_LEN; j++) {
            char c = block[j];
            if (c >= 'A' && c <= 'Z') {
                c += 'a' - 'A';
            } else if (c >= 'a' && c <= 'z') {
                c += 'A' - 'a';
            } else if (c >= '0' && c <= '9') {
                c += 'A' - '0';
            } else {
                c += 'A' - 'a';
            }
            strncat(ciphertext, &c, 1);
        }
    }

    free(block);
    free(state);
}

int main() {
    char plaintext[1000];
    char key[KEY_LEN];
    char ciphertext[1000];

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);

    encrypt(plaintext, key, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}