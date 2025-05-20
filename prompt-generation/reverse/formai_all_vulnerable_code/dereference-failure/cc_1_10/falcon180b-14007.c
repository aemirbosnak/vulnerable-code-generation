//Falcon-180B DATASET v1.0 Category: Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEY_LEN 100
#define MAX_MSG_LEN 1000

void generate_key(char* key, int key_len) {
    for (int i = 0; i < key_len; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_len] = '\0';
}

void encrypt(char* msg, char* key, char* enc) {
    int msg_len = strlen(msg);
    int key_len = strlen(key);
    int enc_len = msg_len + 1;

    for (int i = 0; i < msg_len; i++) {
        if (isalpha(msg[i])) {
            if (isupper(msg[i])) {
                enc[i] = 'A' + ((msg[i] - 'A' + key[i % key_len] - 'a') % 26);
            } else {
                enc[i] = 'a' + ((msg[i] - 'a' + key[i % key_len] - 'a') % 26);
            }
        } else {
            enc[i] = msg[i];
        }
    }
    enc[enc_len - 1] = '\0';
}

void decrypt(char* enc, char* key, char* msg) {
    int enc_len = strlen(enc);
    int key_len = strlen(key);
    int msg_len = enc_len - 1;

    for (int i = 0; i < enc_len; i++) {
        if (isalpha(enc[i])) {
            if (isupper(enc[i])) {
                msg[i] = 'A' + ((enc[i] - 'A' - key[i % key_len] + 26) % 26);
            } else {
                msg[i] = 'a' + ((enc[i] - 'a' - key[i % key_len] + 26) % 26);
            }
        } else {
            msg[i] = enc[i];
        }
    }
    msg[enc_len - 1] = '\0';
}

int main() {
    char msg[MAX_MSG_LEN];
    char key[MAX_KEY_LEN];
    char enc[MAX_MSG_LEN];

    printf("Enter message to encrypt: ");
    fgets(msg, MAX_MSG_LEN, stdin);

    generate_key(key, strlen(msg));

    encrypt(msg, key, enc);

    printf("Encrypted message: %s\n", enc);

    decrypt(enc, key, msg);

    printf("Decrypted message: %s\n", msg);

    return 0;
}