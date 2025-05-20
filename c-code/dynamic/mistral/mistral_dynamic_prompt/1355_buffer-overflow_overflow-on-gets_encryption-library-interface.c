#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LENGTH 20
#define BUFFER_SIZE 1024

char encrypt(const char *key, const char *plaintext, char *ciphertext) {
    for (int i = 0; plaintext[i]; i++) {
        ciphertext[i] = toupper(plaintext[i]) - toupper(key[i % MAX_KEY_LENGTH]);
        if (ciphertext[i] < 'A') ciphertext[i] += 26;
    }
    return '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: key plaintext output\n");
        return 1;
    }

    char key[MAX_KEY_LENGTH];
    strncpy(key, argv[1], MAX_KEY_LENGTH);
    char plaintext[BUFFER_SIZE];
    fgets(plaintext, BUFFER_SIZE, stdin);
    char ciphertext[BUFFER_SIZE];

    encrypt(key, plaintext, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
