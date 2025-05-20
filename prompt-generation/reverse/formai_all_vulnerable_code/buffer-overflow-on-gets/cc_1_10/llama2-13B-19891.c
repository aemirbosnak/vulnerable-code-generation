//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

typedef struct {
    char key[KEY_SIZE];
    char message[BLOCK_SIZE];
} encrypt_struct;

void init_key(encrypt_struct *e) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        e->key[i] = rand() % 26 + 'A';
    }
}

void encrypt(encrypt_struct *e) {
    int i, j, k;
    char c, c2;
    for (i = 0; i < BLOCK_SIZE; i++) {
        c = e->message[i];
        for (j = 0; j < KEY_SIZE; j++) {
            c2 = e->key[j] ^ c;
            e->message[i] = c2;
        }
    }
}

void decrypt(encrypt_struct *e) {
    int i, j, k;
    char c, c2;
    for (i = 0; i < BLOCK_SIZE; i++) {
        c = e->message[i];
        for (j = KEY_SIZE - 1; j >= 0; j--) {
            c2 = e->key[j] ^ c;
            e->message[i] = c2;
        }
    }
}

int main() {
    encrypt_struct e;
    init_key(&e);
    printf("Original message: ");
    gets(e.message);
    printf("Encrypted message: ");
    encrypt(&e);
    printf("Decrypted message: ");
    decrypt(&e);
    return 0;
}