//MISTRAL-7B DATASET v1.0 Category: File Encyptor ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define KEY_SIZE 25
#define BLOCK_SIZE 8

char medieval_key[KEY_SIZE];

void generate_key(void) {
    time_t t;
    struct tm *local;

    time(&t);
    local = localtime(&t);

    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        medieval_key[i] = (rand() % 26) + 'A';
        if (i % 2 == 0) {
            medieval_key[i] += (local->tm_hour * 10) + (local->tm_min / 2);
        }
        if (i % 3 == 0) {
            medieval_key[i] += (local->tm_sec * 5) % 26;
        }
    }
}

void encrypt(char *plaintext, char *ciphertext) {
    int i, j;

    for (i = 0; i < strlen(plaintext); i += BLOCK_SIZE) {
        char block[BLOCK_SIZE];
        strncpy(block, plaintext + i, BLOCK_SIZE);

        for (j = 0; j < BLOCK_SIZE; j++) {
            block[j] = (block[j] + medieval_key[(i / BLOCK_SIZE) % KEY_SIZE]) % 26;
            block[j] = (char)(block[j] + 'A');
        }

        strcpy(ciphertext + i, block);
    }
}

void decrypt(char *ciphertext, char *plaintext) {
    int i, j;

    for (i = 0; i < strlen(ciphertext); i += BLOCK_SIZE) {
        char block[BLOCK_SIZE];
        strncpy(block, ciphertext + i, BLOCK_SIZE);

        for (j = 0; j < BLOCK_SIZE; j++) {
            block[j] = (block[j] - medieval_key[(i / BLOCK_SIZE) % KEY_SIZE]) % 26;
            block[j] = (char)(block[j] + 'A');
        }

        strcpy(plaintext + i, block);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <plaintext> <ciphertext>\n", argv[0]);
        return 1;
    }

    generate_key();

    char plaintext[strlen(argv[1]) + 1];
    strcpy(plaintext, argv[1]);

    char ciphertext[strlen(argv[2]) + 1];
    char decrypted_text[strlen(argv[1]) + 1];

    encrypt(plaintext, ciphertext);

    printf("Encrypted text: %s\n", ciphertext);

    decrypt(ciphertext, decrypted_text);

    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}