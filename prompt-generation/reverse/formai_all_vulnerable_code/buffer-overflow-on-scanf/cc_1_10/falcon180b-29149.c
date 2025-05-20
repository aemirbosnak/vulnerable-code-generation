//Falcon-180B DATASET v1.0 Category: Encryption ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_LEN 32
#define MAX_MSG_LEN 1024

typedef struct {
    char key[MAX_KEY_LEN];
    int key_len;
    int shift;
} CaesarCipher;

void init_caesar_cipher(CaesarCipher* cipher, char* key, int key_len) {
    strncpy(cipher->key, key, MAX_KEY_LEN);
    cipher->key_len = key_len;
    cipher->shift = rand() % 26;
}

void encrypt_message(char* msg, int msg_len, CaesarCipher* cipher) {
    for (int i = 0; i < msg_len; ++i) {
        char c = msg[i];
        if (isalpha(c)) {
            int ascii = c - 'a';
            ascii = (ascii + cipher->shift) % 26;
            c = ascii + 'a';
        }
        msg[i] = c;
    }
}

int main() {
    srand(time(NULL));

    char key[MAX_KEY_LEN];
    printf("Enter a key (up to %d characters): ", MAX_KEY_LEN - 1);
    scanf("%s", key);

    int key_len = strlen(key);
    if (key_len == 0) {
        printf("Error: key cannot be empty\n");
        return 1;
    }

    CaesarCipher cipher;
    init_caesar_cipher(&cipher, key, key_len);

    char msg[MAX_MSG_LEN];
    printf("Enter a message (up to %d characters): ", MAX_MSG_LEN - 1);
    scanf("%s", msg);

    int msg_len = strlen(msg);
    if (msg_len == 0) {
        printf("Error: message cannot be empty\n");
        return 1;
    }

    encrypt_message(msg, msg_len, &cipher);

    printf("Encrypted message: %s\n", msg);

    return 0;
}