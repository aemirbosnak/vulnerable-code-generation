//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define MAX_KEY 100
#define MAX_ROUNDS 10

int key[MAX_KEY];
int rounds;

void generate_key() {
    int i;
    srand(time(NULL));
    for(i = 0; i < MAX_KEY; i++) {
        key[i] = rand() % 26 + 1;
    }
}

void encrypt(char* message, int rounds) {
    int i, j;
    for(i = 0; i < rounds; i++) {
        for(j = 0; j < SIZE; j++) {
            if(message[j] >= 'a' && message[j] <= 'z') {
                message[j] = (char)(message[j] + key[i % MAX_KEY]);
            } else if(message[j] >= 'A' && message[j] <= 'Z') {
                message[j] = (char)(message[j] + key[i % MAX_KEY] - 26);
            }
        }
    }
}

void decrypt(char* message, int rounds) {
    int i, j;
    for(i = 0; i < rounds; i++) {
        for(j = 0; j < SIZE; j++) {
            if(message[j] >= 'a' && message[j] <= 'z') {
                message[j] = (char)(message[j] - key[i % MAX_KEY]);
            } else if(message[j] >= 'A' && message[j] <= 'Z') {
                message[j] = (char)(message[j] - key[i % MAX_KEY] + 26);
            }
        }
    }
}

int main() {
    char message[SIZE];
    int i, rounds = 1;

    generate_key();

    printf("Enter a message to encrypt/decrypt: ");
    scanf("%s", message);

    encrypt(message, rounds);

    printf("Encrypted message: %s\n", message);

    decrypt(message, rounds);

    printf("Decrypted message: %s\n", message);

    return 0;
}