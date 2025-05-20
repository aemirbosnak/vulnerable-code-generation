//Falcon-180B DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1024
#define PRIME_NUMBER 31
#define G 3

typedef struct {
    int *key;
    int *encrypted_key;
} KeyPair;

void generate_keys(KeyPair *key_pair) {
    int *key = (int *)malloc(MAX_SIZE * sizeof(int));
    int *encrypted_key = (int *)malloc(MAX_SIZE * sizeof(int));

    for (int i = 0; i < MAX_SIZE; i++) {
        key[i] = rand() % PRIME_NUMBER;
    }

    for (int i = 0; i < MAX_SIZE; i++) {
        encrypted_key[i] = (key[i] * G) % PRIME_NUMBER;
    }

    key_pair->key = key;
    key_pair->encrypted_key = encrypted_key;
}

void encrypt_message(int *message, int *public_key, int *encrypted_message) {
    int size = strlen((char *)message);

    for (int i = 0; i < size; i++) {
        encrypted_message[i] = ((int)message[i] * public_key[i]) % PRIME_NUMBER;
    }
}

void decrypt_message(int *encrypted_message, int *private_key, char *decrypted_message) {
    int size = strlen((char *)encrypted_message);

    for (int i = 0; i < size; i++) {
        int temp = encrypted_message[i];

        for (int j = 0; j < MAX_SIZE; j++) {
            if ((temp % private_key[j]) == 0) {
                decrypted_message[i] = j + 'a';
                break;
            }
        }
    }

    decrypted_message[size] = '\0';
}

int main() {
    KeyPair key_pair;
    generate_keys(&key_pair);

    int *public_key = key_pair.encrypted_key;
    int *private_key = key_pair.key;

    char message[MAX_SIZE] = "Hello, World!";
    int encrypted_message[MAX_SIZE];

    encrypt_message((int *)message, public_key, encrypted_message);

    char decrypted_message[MAX_SIZE];
    decrypt_message(encrypted_message, private_key, decrypted_message);

    printf("Original message: %s\n", message);
    printf("Encrypted message: ");
    for (int i = 0; i < strlen((char *)encrypted_message); i++) {
        printf("%d ", encrypted_message[i]);
    }
    printf("\n");

    printf("Decrypted message: %s\n", decrypted_message);

    return 0;
}