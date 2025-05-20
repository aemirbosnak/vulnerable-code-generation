//Falcon-180B DATASET v1.0 Category: Cryptography Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_KEY_SIZE 100
#define MAX_PLAINTEXT_SIZE 1000
#define MAX_CIPHERTEXT_SIZE (MAX_PLAINTEXT_SIZE + 1)

typedef struct {
    char key[MAX_KEY_SIZE];
    int keylen;
    int rounds;
} RC4_KEY;

void RC4_init(RC4_KEY *key, const char *password, int rounds) {
    int i, j, k;
    char *ptr = (char *)password;
    char state[256];
    char key_stream[256];

    // Initialize the state
    for (i = 0; i < 256; i++) {
        state[i] = i;
    }

    // Generate the key stream
    for (i = 0; i < 256; i++) {
        j = (j + state[i] + ptr[k % strlen(password)]) % 256;
        k++;
        state[i] = state[j];
        state[j] = i;
    }

    // Set the key
    memset(key, 0, sizeof(RC4_KEY));
    strncpy(key->key, password, MAX_KEY_SIZE);
    key->keylen = strlen(password);
    key->rounds = rounds;
}

void RC4_crypt(RC4_KEY *key, char *plaintext, char *ciphertext) {
    int i, j, k;
    char state[256];
    char key_stream[256];

    // Initialize the state
    for (i = 0; i < 256; i++) {
        state[i] = i;
    }

    // Generate the key stream
    for (i = 0; i < key->keylen; i++) {
        j = (j + state[key->key[i] % 256] + i) % 256;
        k = (k + state[key->key[(j - key->key[i]) % key->keylen] % 256]) % 256;
        state[i] = state[j];
        state[j] = state[k];
    }

    // Encrypt the plaintext
    for (i = 0; i < strlen(plaintext); i++) {
        j = (j + state[(state[key->key[(j % key->keylen)]] + plaintext[i]) % 256]) % 256;
        ciphertext[i] = plaintext[i] ^ state[j];
    }
}

int main() {
    char plaintext[MAX_PLAINTEXT_SIZE];
    char ciphertext[MAX_CIPHERTEXT_SIZE];
    char password[MAX_KEY_SIZE];
    int rounds;

    // Get the plaintext
    printf("Enter the plaintext: ");
    fgets(plaintext, MAX_PLAINTEXT_SIZE, stdin);

    // Get the password
    printf("Enter the password: ");
    fgets(password, MAX_KEY_SIZE, stdin);

    // Get the number of rounds
    printf("Enter the number of rounds: ");
    scanf("%d", &rounds);

    // Initialize the key
    RC4_KEY key;
    RC4_init(&key, password, rounds);

    // Encrypt the plaintext
    RC4_crypt(&key, plaintext, ciphertext);

    // Print the ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}