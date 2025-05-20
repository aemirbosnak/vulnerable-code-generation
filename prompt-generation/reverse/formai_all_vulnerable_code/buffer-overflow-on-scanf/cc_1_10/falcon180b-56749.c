//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 32
#define MAX_MSG_LEN 1024

void encrypt(char *key, char *msg) {
    int len = strlen(msg);
    int key_len = strlen(key);
    int i, j;
    char *cipher_text = (char *)malloc(len + 1);

    for (i = 0, j = 0; i < len; i++) {
        char c = msg[i];

        if (isalpha(c)) {
            c = (c - 'a' + key_len) % 26 + 'a';
        }

        cipher_text[j++] = c;
    }

    cipher_text[j] = '\0';
    printf("Encrypted message: %s\n", cipher_text);
}

void decrypt(char *key, char *cipher_text) {
    int len = strlen(cipher_text);
    int key_len = strlen(key);
    int i, j;
    char *msg = (char *)malloc(len + 1);

    for (i = 0, j = 0; i < len; i++) {
        char c = cipher_text[i];

        if (isalpha(c)) {
            c = (c - 'a' - key_len + 26) % 26 + 'a';
        }

        msg[j++] = c;
    }

    msg[j] = '\0';
    printf("Decrypted message: %s\n", msg);
}

int main() {
    char key[MAX_KEY_LEN];
    char msg[MAX_MSG_LEN];
    int len;

    printf("Enter message to encrypt: ");
    scanf("%s", msg);

    printf("Enter encryption key: ");
    scanf("%s", key);

    encrypt(key, msg);
    decrypt(key, msg);

    return 0;
}