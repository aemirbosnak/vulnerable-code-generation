//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LEN 64
#define MAX_MSG_LEN 1000

typedef struct {
    char key[MAX_KEY_LEN];
    char msg[MAX_MSG_LEN];
} Message;

void generate_key(char* key, int len) {
    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[len] = '\0';
}

void encrypt(Message* msg, char* key) {
    int len = strlen(msg->msg);
    for (int i = 0; i < len; i++) {
        if (isalpha(msg->msg[i])) {
            char c = tolower(msg->msg[i]);
            int k = tolower(key[i % strlen(key)]) - 'a';
            c = (c - 'a' + k) % 26 + 'a';
            msg->msg[i] = c;
        }
    }
}

void decrypt(Message* msg, char* key) {
    int len = strlen(msg->msg);
    for (int i = 0; i < len; i++) {
        if (isalpha(msg->msg[i])) {
            char c = tolower(msg->msg[i]);
            int k = tolower(key[i % strlen(key)]) - 'a';
            c = (c - 'a' - k + 26) % 26 + 'a';
            msg->msg[i] = c;
        }
    }
}

int main() {
    Message msg;
    char key[MAX_KEY_LEN];

    printf("Enter a message to encrypt/decrypt: ");
    scanf("%s", msg.msg);

    printf("Enter a key: ");
    scanf("%s", key);

    generate_key(key, strlen(key));

    printf("Encrypting message with key: %s\n", key);
    encrypt(&msg, key);
    printf("Encrypted message: %s\n", msg.msg);

    printf("Decrypting message with key: %s\n", key);
    decrypt(&msg, key);
    printf("Decrypted message: %s\n", msg.msg);

    return 0;
}