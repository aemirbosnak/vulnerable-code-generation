//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define MSG_SIZE 256

typedef struct {
    int key[KEY_SIZE];
    int msg[MSG_SIZE];
} cipher_t;

void init_key(cipher_t *c) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        c->key[i] = rand() % 256;
    }
}

void encrypt(cipher_t *c, char *msg) {
    int i, j, k;
    for (i = 0; i < MSG_SIZE; i++) {
        j = (c->key[i] + c->msg[i]) % 256;
        c->msg[i] = j;
    }
}

void decrypt(cipher_t *c, char *msg) {
    int i, j, k;
    for (i = 0; i < MSG_SIZE; i++) {
        j = (c->key[i] - c->msg[i]) % 256;
        c->msg[i] = j;
    }
}

int main() {
    cipher_t c;
    char plaintext[] = "Hello World!";
    char ciphertext[MSG_SIZE];

    init_key(&c);
    encrypt(&c, plaintext);
    printf("Encrypted message: ");
    for (int i = 0; i < MSG_SIZE; i++) {
        printf("%c", ciphertext[i]);
    }
    printf("\n");

    decrypt(&c, ciphertext);
    printf("Decrypted message: ");
    for (int i = 0; i < MSG_SIZE; i++) {
        printf("%c", plaintext[i]);
    }
    printf("\n");

    return 0;
}