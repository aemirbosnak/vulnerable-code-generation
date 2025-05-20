//LLAMA2-13B DATASET v1.0 Category: Encryption ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16

typedef struct {
    char key[KEY_SIZE];
    char plaintext[BLOCK_SIZE];
} message_t;

void init_key(message_t *m) {
    int i;
    for (i = 0; i < KEY_SIZE; i++) {
        m->key[i] = (i % 2 == 0) ? 'a' : 'z';
    }
}

void encrypt(message_t *m) {
    int i, j, k;
    char c;
    for (i = 0; i < BLOCK_SIZE; i++) {
        j = i * 2;
        k = j % KEY_SIZE;
        c = m->key[k];
        m->plaintext[i] = (c == 'a') ? (m->plaintext[i - j] + 'z') : (m->plaintext[i - j] + 'a');
    }
}

void decrypt(message_t *m) {
    int i, j, k;
    char c;
    for (i = 0; i < BLOCK_SIZE; i++) {
        j = i * 2;
        k = j % KEY_SIZE;
        c = m->plaintext[i];
        m->key[k] = (c == 'z') ? (m->key[k] - 'a') : (m->key[k] + 'a');
    }
}

int main() {
    message_t m;
    init_key(&m);
    printf("Original plaintext: ");
    gets(m.plaintext);
    encrypt(&m);
    printf("Encrypted ciphertext: ");
    gets(m.plaintext);
    decrypt(&m);
    printf("Decrypted plaintext: ");
    gets(m.plaintext);
    return 0;
}