//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define SIZE 26
#define KEY_SIZE 16
#define PLAINFORMAT

typedef struct {
    char key[KEY_SIZE];
    char alphabet[SIZE];
} Cipher;

void generate_key(char *key) {
    srand(time(0));
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[KEY_SIZE] = '\0';
}

void generate_alphabet(char *key, char *alphabet) {
    for (int i = 0; i < SIZE; i++) {
        alphabet[i] = key[i % KEY_SIZE];
    }
    alphabet[SIZE] = '\0';
}

void encrypt(char *message, Cipher *cipher) {
    for (int i = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = cipher->alphabet[toupper(message[i]) - 'A'] - 'A' + 'a';
            } else {
                message[i] = cipher->alphabet[tolower(message[i]) - 'a'] - 'a' + 'A';
            }
        }
    }
}

void decrypt(char *message, Cipher *cipher) {
    for (int i = 0; message[i]; i++) {
        if (isalpha(message[i])) {
            if (isupper(message[i])) {
                message[i] = cipher->alphabet[toupper(message[i]) - 'A'] - 'A' + 'a';
            } else {
                message[i] = cipher->alphabet[tolower(message[i]) - 'a'] - 'a' + 'A';
            }
        }
    }
}

int main() {
    Cipher cipher;
    char message[1000];
    char key[KEY_SIZE];

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter encryption key: ");
    scanf("%s", key);

    generate_key(key);
    generate_alphabet(key, cipher.alphabet);

    encrypt(message, &cipher);

    printf("Encrypted message: %s\n", message);

    decrypt(message, &cipher);

    printf("Decrypted message: %s\n", message);

    return 0;
}