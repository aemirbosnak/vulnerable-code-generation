//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1024
#define PRIME_NUMBER 17

typedef struct {
    int *key;
    int size;
} Key;

Key generate_key() {
    Key key;
    int i;
    srand(time(NULL));
    key.key = (int *)malloc(MAX_SIZE * sizeof(int));
    key.size = 0;

    for (i = 0; i < MAX_SIZE; i++) {
        key.key[i] = rand() % PRIME_NUMBER;
        if (key.key[i] == 0) {
            i--;
        } else {
            key.size++;
        }
    }

    return key;
}

int encrypt(int message, Key key) {
    int i;
    for (i = 0; i < key.size; i++) {
        message = (message * key.key[i]) % PRIME_NUMBER;
    }
    return message;
}

int decrypt(int message, Key key) {
    int i;
    for (i = key.size - 1; i >= 0; i--) {
        message = (message - key.key[i] * (message % PRIME_NUMBER)) / PRIME_NUMBER;
    }
    return message;
}

int main() {
    Key key = generate_key();
    int message = 123456789;

    printf("Original message: %d\n", message);
    printf("Encrypted message: %d\n", encrypt(message, key));
    printf("Decrypted message: %d\n", decrypt(encrypt(message, key), key));

    return 0;
}