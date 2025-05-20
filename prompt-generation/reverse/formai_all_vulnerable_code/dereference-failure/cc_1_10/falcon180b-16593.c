//Falcon-180B DATASET v1.0 Category: Encryption ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 8

typedef struct {
    char key[KEY_SIZE];
    int rounds;
} RC4_state;

void RC4_init(RC4_state *state, char *key, int rounds) {
    int i, j;
    for (i = 0; i < KEY_SIZE; i++) {
        state->key[i] = key[i];
    }
    state->rounds = rounds;
    for (i = 0; i < KEY_SIZE; i++) {
        j = (i + state->key[i] + 0xAA) % KEY_SIZE;
        char temp = state->key[i];
        state->key[i] = state->key[j];
        state->key[j] = temp;
    }
    i = j = 0;
}

void RC4_crypt(RC4_state *state, char *data, int length) {
    int i, j;
    for (i = 0; i < length; i++) {
        j = (j + 1) % KEY_SIZE;
        i = (i + state->key[j]) % KEY_SIZE;
        char temp = state->key[i];
        state->key[i] = state->key[j];
        state->key[j] = temp;
        data[i] ^= state->key[(state->key[i] + state->key[j]) % KEY_SIZE];
    }
}

void RC4_encrypt(RC4_state *state, char *data, int length) {
    RC4_crypt(state, data, length);
}

void RC4_decrypt(RC4_state *state, char *data, int length) {
    RC4_crypt(state, data, length);
}

int main() {
    char key[KEY_SIZE] = "ThisIsMySecretKey";
    RC4_state state;
    RC4_init(&state, key, 16);

    char message[BLOCK_SIZE] = "Hello, world!";
    char ciphertext[BLOCK_SIZE];
    char plaintext[BLOCK_SIZE];

    RC4_encrypt(&state, message, strlen(message));
    memcpy(ciphertext, message, strlen(message));
    RC4_decrypt(&state, ciphertext, strlen(message));
    memcpy(plaintext, ciphertext, strlen(message));

    printf("Encrypted message: %s\n", ciphertext);
    printf("Decrypted message: %s\n", plaintext);

    return 0;
}