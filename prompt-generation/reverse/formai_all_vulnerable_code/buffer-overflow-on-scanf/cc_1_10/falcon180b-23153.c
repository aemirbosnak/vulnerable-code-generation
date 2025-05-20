//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LEN 64
#define MAX_TEXT_LEN 1024

typedef struct {
    char key[MAX_KEY_LEN];
    int key_len;
    char text[MAX_TEXT_LEN];
    int text_len;
} message;

void generate_random_key(char* key, int key_len) {
    srand(time(NULL));
    for (int i = 0; i < key_len; i++) {
        key[i] = rand() % 26 + 'A';
    }
    key[key_len] = '\0';
}

void generate_random_text(char* text, int text_len) {
    srand(time(NULL));
    for (int i = 0; i < text_len; i++) {
        text[i] = rand() % 26 + 'A';
    }
    text[text_len] = '\0';
}

void encrypt(message* msg) {
    for (int i = 0; i < msg->text_len; i++) {
        msg->text[i] = toupper(msg->text[i]);
        msg->text[i] = msg->text[i] + msg->key[i % msg->key_len];
    }
}

void decrypt(message* msg) {
    for (int i = 0; i < msg->text_len; i++) {
        msg->text[i] = toupper(msg->text[i]);
        msg->text[i] = msg->text[i] - msg->key[i % msg->key_len];
    }
}

void main() {
    message msg;
    char key[MAX_KEY_LEN];
    char text[MAX_TEXT_LEN];

    printf("Enter the key: ");
    scanf("%s", key);
    msg.key_len = strlen(key);
    strcpy(msg.key, key);

    printf("Enter the text to encrypt: ");
    scanf("%s", text);
    msg.text_len = strlen(text);
    strcpy(msg.text, text);

    printf("Encrypted text: %s\n", msg.text);
    encrypt(&msg);
    printf("Decrypted text: %s\n", msg.text);
}