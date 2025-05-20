//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LEN 16
#define BLOCK_LEN 64

void generate_key(char *key, int len) {
    for (int i = 0; i < len; i++) {
        key[i] = rand() % 26 + 'a';
    }
}

void encrypt(char *plain_text, char *key, char *cipher_text) {
    int i, j;
    for (i = 0, j = 0; i < strlen(plain_text); i++, j++) {
        if (j == KEY_LEN) {
            generate_key(key, KEY_LEN);
            j = 0;
        }
        char ch = plain_text[i];
        if (isalpha(ch)) {
            ch = (ch + key[j] - 'a' + 26) % 26 + 'a';
        }
        cipher_text[i] = ch;
    }
}

void decrypt(char *cipher_text, char *key, char *plain_text) {
    int i, j;
    for (i = 0, j = 0; i < strlen(cipher_text); i++, j++) {
        if (j == KEY_LEN) {
            generate_key(key, KEY_LEN);
            j = 0;
        }
        char ch = cipher_text[i];
        if (isalpha(ch)) {
            ch = (ch - key[j] + 26) % 26 + 'a';
        }
        plain_text[i] = ch;
    }
}

int main() {
    char plain_text[BLOCK_LEN];
    char key[KEY_LEN];
    char cipher_text[BLOCK_LEN];

    printf("Enter plain text: ");
    scanf("%s", plain_text);

    generate_key(key, KEY_LEN);
    encrypt(plain_text, key, cipher_text);

    printf("Encrypted text: %s\n", cipher_text);

    decrypt(cipher_text, key, plain_text);
    printf("Decrypted text: %s\n", plain_text);

    return 0;
}