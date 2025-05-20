//Falcon-180B DATASET v1.0 Category: Cryptographic hash function ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_SIZE 32
#define BLOCK_SIZE 64
#define ROUNDS 1000

typedef struct {
    unsigned char state[HASH_SIZE];
    int index;
} hash_state;

void hash_init(hash_state *state) {
    memset(state->state, 0, HASH_SIZE);
    state->index = 0;
}

void hash_update(hash_state *state, const unsigned char *data, int len) {
    int i;
    for (i = 0; i < len; i++) {
        state->state[state->index] ^= data[i];
        state->index = (state->index + 1) % HASH_SIZE;
    }
}

void hash_final(hash_state *state, unsigned char *digest) {
    int i;
    for (i = 0; i < HASH_SIZE; i++) {
        digest[i] = state->state[i];
    }
}

void hash(const unsigned char *data, int len, unsigned char *digest) {
    hash_state state;
    hash_init(&state);
    hash_update(&state, data, len);
    hash_final(&state, digest);
}

int main() {
    char input[256];
    printf("Enter input string: ");
    scanf("%s", input);
    int len = strlen(input);
    unsigned char digest[HASH_SIZE];
    hash(input, len, digest);
    printf("Hash: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
    return 0;
}