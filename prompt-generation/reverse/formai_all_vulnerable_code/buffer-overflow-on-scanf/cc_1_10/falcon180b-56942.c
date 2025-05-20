//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 64
#define MAX_MSG_LEN 256
#define MAX_CIPHER_LEN (MAX_MSG_LEN + 1)

typedef struct {
    char key[MAX_KEY_LEN];
    int key_len;
    char cipher[MAX_CIPHER_LEN];
    int cipher_len;
} Cipher;

void init_cipher(Cipher *cipher, const char *key) {
    strcpy(cipher->key, key);
    cipher->key_len = strlen(key);
    cipher->cipher_len = 0;
}

void encrypt(Cipher *cipher, const char *msg, char *cipher_text) {
    int i, j;
    char ch;

    for (i = 0, j = 0; i < strlen(msg); i++) {
        ch = msg[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 'a' - 'A';
        }
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch + cipher->key[j % cipher->key_len]) % 26 + 'a';
            j++;
        }
        cipher_text[i] = ch;
    }
    cipher_text[i] = '\0';
    cipher->cipher_len = i;
}

void decrypt(Cipher *cipher, const char *cipher_text, char *msg) {
    int i, j;
    char ch;

    for (i = 0, j = 0; i < cipher->cipher_len; i++) {
        ch = cipher_text[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = (ch - cipher->key[j % cipher->key_len] + 26) % 26 + 'A';
            j++;
        }
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 'a' - 'A';
        }
        msg[i] = ch;
    }
    msg[i] = '\0';
}

int main() {
    Cipher cipher;
    char msg[MAX_MSG_LEN];
    char cipher_text[MAX_CIPHER_LEN];
    char key[MAX_KEY_LEN];

    printf("Enter message to encrypt: ");
    scanf("%s", msg);

    printf("Enter encryption key (up to %d characters): ", MAX_KEY_LEN);
    scanf("%s", key);

    init_cipher(&cipher, key);
    encrypt(&cipher, msg, cipher_text);

    printf("Encrypted message: %s\n", cipher_text);

    printf("Enter decryption key: ");
    scanf("%s", key);

    init_cipher(&cipher, key);
    decrypt(&cipher, cipher_text, msg);

    printf("Decrypted message: %s\n", msg);

    return 0;
}