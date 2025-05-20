//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

typedef struct {
    char key[KEY_SIZE];
    int round;
} DES;

void des_set_key(DES* des, char* key) {
    memset(des->key, 0, KEY_SIZE);
    strncpy(des->key, key, KEY_SIZE);
    des->round = 0;
}

void des_encrypt(DES* des, char* plaintext, char* ciphertext) {
    int i, j;
    char* ip = plaintext;
    char* op = ciphertext;
    char* key = des->key;
    int r = des->round;

    while (r < 16) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            *op++ = *ip++ ^ key[r];
            r = (r + 1) % KEY_SIZE;
        }
    }
}

void des_decrypt(DES* des, char* ciphertext, char* plaintext) {
    int i, j;
    char* ip = ciphertext;
    char* op = plaintext;
    char* key = des->key;
    int r = des->round;

    while (r < 16) {
        for (i = 0; i < BLOCK_SIZE; i++) {
            *op++ = *ip++ ^ key[r];
            r = (r + 1) % KEY_SIZE;
        }
    }
}

int main() {
    DES des;
    char plaintext[100] = "Hello, world!";
    char ciphertext[100];
    char key[16] = "secretkey";

    des_set_key(&des, key);
    des_encrypt(&des, plaintext, ciphertext);
    des_decrypt(&des, ciphertext, plaintext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}