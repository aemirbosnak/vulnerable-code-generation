//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 1024
#define PRIME 29

typedef struct {
    int *key;
    int *public_key;
} KeyPair;

void generate_keys(KeyPair *key_pair) {
    int i;
    int *key = (int *)malloc(SIZE * sizeof(int));
    int *public_key = (int *)malloc(SIZE * sizeof(int));

    for (i = 0; i < SIZE; i++) {
        key[i] = rand() % PRIME;
        public_key[i] = key[i] ^ PRIME;
    }

    key_pair->key = key;
    key_pair->public_key = public_key;
}

void encrypt(int *message, int *key, int *encrypted) {
    int i;

    for (i = 0; i < SIZE; i++) {
        encrypted[i] = message[i] ^ key[i];
    }
}

void decrypt(int *encrypted, int *key, int *decrypted) {
    int i;

    for (i = 0; i < SIZE; i++) {
        decrypted[i] = encrypted[i] ^ key[i];
    }
}

int main() {
    KeyPair key_pair;
    int message[SIZE];
    int encrypted[SIZE];
    int decrypted[SIZE];

    srand(time(NULL));
    generate_keys(&key_pair);

    printf("Enter message to encrypt: ");
    fgets(message, SIZE, stdin);

    encrypt(message, key_pair.key, encrypted);

    printf("Encrypted message: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", encrypted[i]);
    }

    decrypt(encrypted, key_pair.key, decrypted);

    printf("\nDecrypted message: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", decrypted[i]);
    }

    free(key_pair.key);
    free(key_pair.public_key);

    return 0;
}