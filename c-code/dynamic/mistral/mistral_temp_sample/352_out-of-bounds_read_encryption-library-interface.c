#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 16
#define MAX_PLAINTEXT_SIZE 1024
#define ALPHABET_SIZE 26

void encrypt(char *key, char *plaintext, char *ciphertext) {
    int i, j;
    char keyChars[MAX_KEY_SIZE];
    char cipherChars[MAX_PLAINTEXT_SIZE];

    for (i = 0; i < MAX_KEY_SIZE; i++) {
        keyChars[i] = key[i % strlen(key)];
    }

    for (i = 0, j = 0; i < strlen(plaintext); i++) {
        cipherChars[j] = ((plaintext[i] - 'a' + keyChars[(i % strlen(key)) - 1]) % ALPHABET_SIZE) + 'a';
        j++;
    }

    strcpy(ciphertext, cipherChars);
}

int main(int argc, char *argv[]) {
    char key[MAX_KEY_SIZE];
    char plaintext[MAX_PLAINTEXT_SIZE];
    char ciphertext[MAX_PLAINTEXT_SIZE];

    if (argc != 4) {
        printf("Usage: %s <key> <plaintext> <output>\n", argv[0]);
        return 1;
    }

    strcpy(key, argv[1]);
    strcpy(plaintext, argv[2]);
    strcpy(ciphertext, argv[3]);

    encrypt(key, plaintext, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
