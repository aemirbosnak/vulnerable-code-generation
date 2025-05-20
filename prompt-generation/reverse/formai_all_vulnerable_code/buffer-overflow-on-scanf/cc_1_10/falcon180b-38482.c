//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_LENGTH 64
#define MAX_MESSAGE_LENGTH 1024
#define MAX_CIPHERTEXT_LENGTH (MAX_MESSAGE_LENGTH + 1)

typedef struct {
    char key[MAX_KEY_LENGTH+1];
    int key_length;
    int rounds;
} rc4_state;

void rc4_init(rc4_state *state, char *key, int key_length, int rounds) {
    int i, j, k;
    char *s = state->key;

    for (i = 0; i < 256; i++) {
        state->key[i] = i;
    }

    for (i = 0; i < key_length; i++) {
        j = (j + state->key[key[i]] + i) % 256;
        k = state->key[i];
        state->key[i] = state->key[j];
        state->key[j] = k;
    }

    state->rounds = rounds;
}

void rc4_crypt(rc4_state *state, char *message, int message_length, char *ciphertext) {
    int i, j, k;
    char *s = state->key;
    char *m = message;
    char *c = ciphertext;

    for (i = 0; i < message_length; i++) {
        j = (j + state->key[s[i % s[0]]]) % 256;
        k = s[i % s[0]];
        s[i % s[0]] = s[j];
        s[j] = k;
        c[i] = m[i] ^ s[(s[0] + s[s[0]]) % 256];
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    char key[MAX_KEY_LENGTH];
    int message_length, key_length, rounds;
    char ciphertext[MAX_CIPHERTEXT_LENGTH];
    rc4_state state;

    printf("Enter message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message_length = strlen(message);

    printf("Enter key: ");
    fgets(key, MAX_KEY_LENGTH, stdin);
    key_length = strlen(key);

    printf("Enter number of rounds: ");
    scanf("%d", &rounds);

    rc4_init(&state, key, key_length, rounds);
    rc4_crypt(&state, message, message_length, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}