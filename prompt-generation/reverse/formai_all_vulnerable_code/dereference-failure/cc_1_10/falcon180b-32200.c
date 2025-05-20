//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 128

typedef struct {
    int *public_key;
    int *private_key;
} KeyPair;

void generate_keys(KeyPair *key_pair) {
    int *public_key = malloc(SIZE * sizeof(int));
    int *private_key = malloc(SIZE * sizeof(int));

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        public_key[i] = rand() % 2;
        private_key[i] = rand() % 2;
    }

    key_pair->public_key = public_key;
    key_pair->private_key = private_key;
}

void print_key(int *key, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", key[i]);
    }
    printf("\n");
}

void encrypt(int *public_key, int *message, int *cipher_text, int size) {
    for (int i = 0; i < size; i++) {
        cipher_text[i] = message[i] ^ public_key[i];
    }
}

void decrypt(int *private_key, int *cipher_text, int *message, int size) {
    for (int i = 0; i < size; i++) {
        message[i] = cipher_text[i] ^ private_key[i];
    }
}

int main() {
    KeyPair key_pair;
    generate_keys(&key_pair);

    int message[SIZE];
    printf("Enter message: ");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &message[i]);
    }

    int cipher_text[SIZE];
    encrypt(key_pair.public_key, message, cipher_text, SIZE);

    printf("Encrypted message: ");
    print_key(cipher_text, SIZE);

    int decrypted_message[SIZE];
    decrypt(key_pair.private_key, cipher_text, decrypted_message, SIZE);

    printf("Decrypted message: ");
    print_key(decrypted_message, SIZE);

    return 0;
}