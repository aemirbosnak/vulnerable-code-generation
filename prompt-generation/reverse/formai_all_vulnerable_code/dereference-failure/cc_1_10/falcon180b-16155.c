//Falcon-180B DATASET v1.0 Category: Encryption ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j, k;
    char state[KEY_SIZE];

    for (i = 0; i < KEY_SIZE; i++) {
        state[i] = key[i];
    }

    i = j = 0;

    while (plaintext[i]) {
        if (isalpha(plaintext[i])) {
            plaintext[i] = toupper(plaintext[i]);
        }

        j = (j + 1) % KEY_SIZE;

        if (isalpha(plaintext[i])) {
            ciphertext[i] = (state[j] + plaintext[i] - 65) % 26 + 65;
        } else {
            ciphertext[i] = plaintext[i];
        }

        i++;
    }
}

void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i, j, k;
    char state[KEY_SIZE];

    for (i = 0; i < KEY_SIZE; i++) {
        state[i] = key[i];
    }

    i = j = 0;

    while (ciphertext[i]) {
        if (isalpha(ciphertext[i])) {
            ciphertext[i] = toupper(ciphertext[i]);
        }

        j = (j + 1) % KEY_SIZE;

        if (isalpha(ciphertext[i])) {
            plaintext[i] = (ciphertext[i] - state[j] - 65 + 26) % 26 + 65;
        } else {
            plaintext[i] = ciphertext[i];
        }

        i++;
    }
}

int main() {
    char plaintext[] = "Hello, World!";
    char key[] = "mysecretkey";
    char ciphertext[100];
    char decrypted_text[100];

    encrypt(plaintext, key, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Key: %s\n", key);
    printf("Ciphertext: %s\n", ciphertext);

    decrypt(ciphertext, key, decrypted_text);

    printf("Decrypted text: %s\n", decrypted_text);

    return 0;
}